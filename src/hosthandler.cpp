/*
 * Copyright (C) 2009 Toni Gundogdu.
 *
 * This file is part of cclive.
 * 
 * cclive is free software: you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation, either version 3 of the License, or (at your option) any later
 * version.
 * 
 * cclive is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 * 
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifdef HOST_W32
// A peculiar thing this one. If commented out or included *after* "config.h",
// mingw32-g++ returns: error: '::malloc' has not been declared
#include <cstdlib>
#endif

#include <string>
#include <vector>

#include "config.h"

#include "hosthandler.h"
#include "opts.h"

#ifdef WITH_PERL // -----------------------------
#include <EXTERN.h>
#include <perl.h>
#include <XSUB.h>

EXTERN_C void xs_init(pTHX);

static PerlInterpreter *perl;

static const char script_title[] =
"binmode(STDOUT, \":utf8\");"

"use Encode qw(from_to decode_utf8 FB_CROAK);"
"use HTML::TokeParser;"

"from_to($html, $1, \"utf8\")"
"    if ($html =~ /charset=(.*?)\"/);"

"$html = Encode::decode_utf8($html, Encode::FB_CROAK);"

"$parser = HTML::TokeParser->new(\\$html);"
"$parser->get_tag('title');"
"$title = $parser->get_trimmed_text;"
;

static const char script_filter[] =
"$title =~ s/(youtube|liveleak.com|sevenload|dailymotion)//gi;"
"$title =~ s/(on vimeo|.golem.de|clipfish|funny hub)//gi;"
"$title =~ s/(video[s])//gi;"
"$title =~ s/^[-\\s]+//;"
"$title =~ s/\\s+$//;"

"if (!$no_cclass) {"
"    $re = $cclass || qr|\\w|;"
"    $title = join('', $title =~ /$re/g);"
"}"
;

static void
initPerl() {
    perl = perl_alloc();
    perl_construct(perl);

    const char   *args[] = {"", "-e", "0"};
    perl_parse(perl, xs_init, 3, const_cast<char**>(args), 0);

    perl_run(perl);
}

static void
freePerl() {
    perl_destruct(perl);
    perl_free(perl);
}

static std::string
getPageTitle(const std::string &html) {

    initPerl();

    SV *sv_html = perl_get_sv("html", TRUE);
    sv_setpv(sv_html, html.c_str());

    perl_eval_pv(script_title, TRUE);

    return SvPV(perl_get_sv("title", FALSE), PL_na);
}

static void
filterTitle(std::string& title) {

    Options opts = optsmgr.getOptions();

    if (opts.cclass_given) {
        SV     *sv_cclass = perl_get_sv("cclass", TRUE);
        sv_setpv(sv_cclass, opts.cclass_arg);
    }

    if (opts.no_cclass_given) {
        SV *sv_nocclass = perl_get_sv("no_cclass", TRUE);
        sv_setiv(sv_nocclass, 1);
    }

    SV *sv_title = perl_get_sv("title", TRUE);
    sv_setpv(sv_title, title.c_str());

    perl_eval_pv(script_filter, TRUE);

    title = SvPV(get_sv("title", FALSE), PL_na);

    freePerl();
}
#endif // WITH_PERL -----------------------------

HostHandler::HostHandler()
    : pageContent(""), props(VideoProperties())
{
}

HostHandler::~HostHandler() {
}

const bool
HostHandler::isHost(std::string url) {
    return Util::toLower(url).find(props.getDomain())
        != std::string::npos;
}

void
HostHandler::parsePage(
    const std::string& pageContent,
    const std::string& url)
{
    this->pageContent = pageContent;

    props.setPageLink(url);

#ifdef WITH_PERL
    if (optsmgr.getOptions().title_given)
        props.setTitle( getPageTitle(pageContent) );
#endif

    // call overridden functions
    parseId   ();
    parseLink ();

#ifdef WITH_PERL
    // Overridden parseLink may have changed the title video property.
    // Apply --cclass here.
    if (optsmgr.getOptions().title_given) {
        std::string title = props.getTitle();
        filterTitle(title);
        props.setTitle(title);
    }
#endif

    this->pageContent.clear();
}

const VideoProperties&
HostHandler::getVideoProperties() const {
    return props;
}

HostHandler::
    ParseException::ParseException(const std::string& error)
        : RuntimeException(CCLIVE_PARSE, error)
{
}
