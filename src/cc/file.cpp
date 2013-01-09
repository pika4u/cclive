/* cclive
 * Copyright (C) 2010-2013  Toni Gundogdu <legatvs@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <ccinternal>

#include <stdexcept>
#include <fstream>
#include <sstream>
#include <iomanip>

#ifdef HAVE_UNISTD_H
#include <unistd.h>
#endif

#ifdef HAVE_SIGNAL_H
#include <signal.h>
#endif

#if defined (HAVE_SIGNAL_H) && defined (HAVE_SIGNAL)
#define WITH_SIGNAL
#endif

#include <boost/program_options/variables_map.hpp>
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/format.hpp>

#ifndef foreach
#define foreach BOOST_FOREACH
#endif

#include <curl/curl.h>
#include <pcrecpp.h>

#include <ccoptions>
#include <ccquvi>
#include <ccprogressbar>
#include <ccre>
#include <ccutil>
#include <cclog>
#include <ccfile>

namespace cc
{

file::file()
  : _initial_length(0), _nothing_todo(false)
{
}

namespace po = boost::program_options;

file::file(const quvi::media& media, const quvi::url& url, const int n)
  : _initial_length(0), _nothing_todo(false)
{
  try
    {
      _init(media, url, n);
    }
  catch (const cc::nothing_todo_error&)
    {
      _nothing_todo = true;
    }
}

file::file(const file& f)
  : _initial_length(0), _nothing_todo(false)
{
  _swap(f);
}

file& file::operator=(const file& f)
{
  if (this != &f) _swap(f);
  return *this;
}

void file::_swap(const file& f)
{
  _title          = f._title;
  _name           = f._name;
  _path           = f._path;
  _initial_length = f._initial_length;
  _nothing_todo   = f._nothing_todo;
}

#define E "server response code %ld, expected 200 or 206 (conn_code=%ld)"

static std::string format_unexpected_http_error(
  const long resp_code,
  const long conn_code)
{
  return (boost::format(E) % resp_code % conn_code).str();
}

#undef E

#define E "%s (curl_code=%ld, resp_code=%ld, conn_code=%ld)"

static std::string format_error(const CURLcode curl_code,
                                const long resp_code,
                                const long conn_code)
{
  const std::string e = curl_easy_strerror(curl_code);
  return (boost::format(E) % e % curl_code % resp_code % conn_code).str();
}

#undef E

static size_t write_cb(void *ptr, size_t size, size_t nmemb, void *userdata)
{
  std::ofstream *o = reinterpret_cast<std::ofstream*>(userdata);
  const size_t rsize = size*nmemb;
  o->write(static_cast<char*>(ptr), rsize);
  o->flush();
  return rsize;
}

#ifdef WITH_SIGNAL
static volatile sig_atomic_t recv_usr1;

static void handle_usr1(int s)
{
  if (s == SIGUSR1)
    recv_usr1 = 1;
}
#endif

static int progress_cb(void *ptr, double, double now, double, double)
{
#ifdef WITH_SIGNAL
  if (recv_usr1)
    {
      recv_usr1 = 0;
      return 1; // Return a non-zero value to abort this transfer.
    }
#endif
  return reinterpret_cast<progressbar*>(ptr)->update(now);
}

static void _set(CURL *c, std::ofstream *o, progressbar *pb,
                 const double initial_length)
{
  curl_easy_setopt(c, CURLOPT_PROGRESSFUNCTION, progress_cb);
  curl_easy_setopt(c, CURLOPT_PROGRESSDATA, pb);
  curl_easy_setopt(c, CURLOPT_NOPROGRESS, 0L);

  curl_easy_setopt(c, CURLOPT_ENCODING, "identity");
  curl_easy_setopt(c, CURLOPT_WRITEDATA, o);
  curl_easy_setopt(c, CURLOPT_HEADER, 0L);

  const po::variables_map map = cc::opts.map();

  curl_easy_setopt(c, CURLOPT_MAX_RECV_SPEED_LARGE,
                   static_cast<curl_off_t>(map["throttle"].as<int>()*1024));

  curl_easy_setopt(c, CURLOPT_RESUME_FROM_LARGE,
                   static_cast<curl_off_t>(initial_length));
}

static void _restore(CURL *c)
{
  curl_easy_setopt(c, CURLOPT_RESUME_FROM_LARGE, 0L);
  curl_easy_setopt(c, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(c, CURLOPT_HEADER, 1L);

  curl_easy_setopt(c, CURLOPT_MAX_RECV_SPEED_LARGE,
                   static_cast<curl_off_t>(0L));
}

namespace po = boost::program_options;

bool file::write(const quvi::url& u, CURL *curl) const
{
  curl_easy_setopt(curl, CURLOPT_URL, u.media_url().c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);

  std::ios_base::openmode mode = std::ofstream::binary;

  if (opts.flags.overwrite)
    mode |= std::ofstream::trunc;
  else
    {
      if (_should_continue())
        mode |= std::ofstream::app;
    }

  std::ofstream out(_path.c_str(), mode);
  if (out.fail())
    {
      std::string s = _path + ": ";

      if (errno)
        s += cc::perror();
      else
        s += "unknown file open error";

      throw std::runtime_error(s);
    }

  progressbar pb(*this, u);
  _set(curl, &out, &pb, _initial_length);

#ifdef WITH_SIGNAL
  recv_usr1 = 0;
  if (signal(SIGUSR1, handle_usr1) == SIG_ERR)
    {
      cc::log << "warning: ";
      if (errno)
        cc::log << cc::perror();
      else
        cc::log << "unable to catch SIGUSR1";
      cc::log << std::endl;
    }
#endif

  const CURLcode rc = curl_easy_perform(curl);
  _restore(curl);

  // Restore curl settings.

  curl_easy_setopt(curl, CURLOPT_HEADER, 1L);
  curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L);
  curl_easy_setopt(curl, CURLOPT_RESUME_FROM_LARGE, 0L);
  curl_easy_setopt(curl,
                   CURLOPT_MAX_RECV_SPEED_LARGE,
                   static_cast<curl_off_t>(0L));

  out.flush();
  out.close();

  long resp_code = 0;
  long conn_code = 0;

  curl_easy_getinfo(curl, CURLINFO_HTTP_CONNECTCODE, &conn_code);
  curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &resp_code);

  std::string error;

  if (CURLE_OK == rc)
    {
      if (resp_code != 200 && resp_code != 206)
        error = format_unexpected_http_error(resp_code, conn_code);
    }
  else
    error = format_error(rc, resp_code, conn_code);

  if (!error.empty())
    {
      cc::log << std::endl;

      if (resp_code >= 400 && resp_code <= 500)
        throw std::runtime_error(error);
      else
        {
#ifdef WITH_SIGNAL
          if (rc == 42)
            {
              // 42 = Operation aborted by callback.
              error = "sigusr1 received: interrupt current download";
            }
#endif
          cc::log << "error: " << error << std::endl;
        }
      return false; // Retry.
    }

  pb.finish();
  cc::log << std::endl;

  return true;
}

double file::initial_length() const
{
  return _initial_length;
}

const std::string& file::title() const
{
  return _title;
}

const std::string& file::path() const
{
  return _path;
}

const std::string& file::name() const
{
  return _name;
}

const bool file::nothing_todo() const
{
  return _nothing_todo;
}

bool file::_should_continue() const
{
  return _initial_length > 0;
}

static double to_mb(const double bytes)
{
  return bytes/(1024*1024);
}

std::string file::to_s(const quvi::url& url) const
{
  const double length = to_mb(url.content_length());

  boost::format fmt = boost::format("%s  %.2fM  [%s]")
                      % _name % length % url.content_type();

  return fmt.str();
}

namespace fs = boost::filesystem;

static fs::path output_dir(const po::variables_map& map)
{
  fs::path dir;
  if (map.count("output-dir"))
    dir = map["output-dir"].as<std::string>();
  return fs::system_complete(dir);
}

typedef std::vector<std::string> vst;

void file::_init(const quvi::media& media,
                 const quvi::url& url,
                 const int n)
{
  _title = media.title();

  const po::variables_map map = cc::opts.map();

  if (map.count("output-file"))
    {
      // Overrides --filename-format.

      fs::path p = output_dir(map);

      p /= map["output-file"].as<std::string>();

#if BOOST_FILESYSTEM_VERSION > 2
      _name = p.filename().string();
#else
      _name = p.filename();
#endif
      _path           = p.string();
      _initial_length = file::exists(_path);

      if ( _initial_length >= url.content_length() && ! opts.flags.overwrite)
        throw cc::nothing_todo_error();
    }

  else
    {
      // Cleanup media title.

      std::string title = media.title();
      vst tr;

      if (map.count("tr"))
        tr = map["tr"].as<vst>();
      else // Use built-in default value.
        {
          if (map.count("regexp")) // Deprecated.
            cc::re::capture(map["regexp"].as<std::string>(), title);
          else
            tr.push_back("/(\\w|\\pL|\\s)/g");
        }

      foreach (const std::string r, tr)
      {
        cc::re::tr(r, title);
      }
      cc::re::trim(title);

      // --filename-format

      std::string fname_format = map["filename-format"].as<std::string>();

      pcrecpp::RE("%i").GlobalReplace(media.id(), &fname_format);
      pcrecpp::RE("%t").GlobalReplace(title, &fname_format);
      pcrecpp::RE("%s").GlobalReplace(url.suffix(), &fname_format);
      pcrecpp::RE("%h").GlobalReplace(media.host(), &fname_format);

      if (map.count("subst")) // Deprecated.
        {
          std::istringstream iss(map["subst"].as<std::string>());
          vst v;

          std::copy(
            std::istream_iterator<std::string >(iss),
            std::istream_iterator<std::string >(),
            std::back_inserter<vst>(v)
          );

          foreach (const std::string s, v)
          {
            cc::re::subst(s, fname_format);
          }
        }

      std::stringstream b;

      b << fname_format;

      // A multi-segment media.

      if (n > 1) b << "_" << n;

      // Output dir.

      const fs::path out_dir = output_dir(map);
      fs::path templ_path    = out_dir;

      templ_path /= b.str();

      // Path, name.

      fs::path p = fs::system_complete(templ_path);

#if BOOST_FILESYSTEM_VERSION > 2
      _name = p.filename().string();
#else
      _name = p.filename();
#endif
      _path = p.string();

      if (! opts.flags.overwrite)
        {
          for (int i=0; i<INT_MAX; ++i)
            {
              _initial_length = file::exists(_path);

              if (_initial_length == 0)
                break;

              else if (_initial_length >= url.content_length())
                throw cc::nothing_todo_error();

              else
                {
                  if (opts.flags.cont)
                    break;
                }

              boost::format fmt =
                boost::format("%1%.%2%") % templ_path.string() % i;

              p = fs::system_complete(fmt.str());

#if BOOST_FILESYSTEM_VERSION > 2
              _name = p.filename().string();
#else
              _name = p.filename();
#endif
              _path = p.string();
            }
        }
    }

  if (opts.flags.overwrite)
    _initial_length = 0;
}

double file::exists(const std::string& path)
{
  fs::path p( fs::system_complete(path) );

  double size = 0;

  if (fs::exists(p))
    size = static_cast<double>(fs::file_size(p));

  return size;
}

} // namespace cc

// vim: set ts=2 sw=2 tw=72 expandtab:
