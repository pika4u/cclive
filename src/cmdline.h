/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.4
 *  http://www.gnu.org/software/gengetopt.
 *  DO NOT modify this file, since it can be overwritten
 *  @author GNU Gengetopt by Lorenzo Bettini */

#ifndef CMDLINE_H
#define CMDLINE_H

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h> /* for FILE */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef CMDLINE_PARSER_PACKAGE
/** @brief the program name (used for printing errors) */
#define CMDLINE_PARSER_PACKAGE PACKAGE
#endif

#ifndef CMDLINE_PARSER_PACKAGE_NAME
/** @brief the complete program name (used for help and version) */
#ifdef PACKAGE_NAME
#define CMDLINE_PARSER_PACKAGE_NAME PACKAGE_NAME
#else
#define CMDLINE_PARSER_PACKAGE_NAME PACKAGE
#endif
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION VERSION
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  const char *hosts_help; /**< @brief List supported hosts help description.  */
  const char *background_help; /**< @brief Go to background immediately after startup help description.  */
  const char *emit_csv_help; /**< @brief Print video details in csv format to stdout help description.  */
  int quiet_flag;	/**< @brief Turn off all output (default=off).  */
  const char *quiet_help; /**< @brief Turn off all output help description.  */
  int debug_flag;	/**< @brief Turn on libcurl verbose mode (default=off).  */
  const char *debug_help; /**< @brief Turn on libcurl verbose mode help description.  */
  int print_fname_flag;	/**< @brief Print filename before each download starts (default=off).  */
  const char *print_fname_help; /**< @brief Print filename before each download starts help description.  */
  char * logfile_arg;	/**< @brief Write output to file while in background (default='cclive.log').  */
  char * logfile_orig;	/**< @brief Write output to file while in background original value given at command line.  */
  const char *logfile_help; /**< @brief Write output to file while in background help description.  */
  int logfile_interval_arg;	/**< @brief Update logfile every n seconds while in background (default='10').  */
  char * logfile_interval_orig;	/**< @brief Update logfile every n seconds while in background original value given at command line.  */
  const char *logfile_interval_help; /**< @brief Update logfile every n seconds while in background help description.  */
  char * agent_arg;	/**< @brief Identify cclive as agent string to servers (default='Mozilla/5.0').  */
  char * agent_orig;	/**< @brief Identify cclive as agent string to servers original value given at command line.  */
  const char *agent_help; /**< @brief Identify cclive as agent string to servers help description.  */
  char * proxy_arg;	/**< @brief Use specified proxy.  */
  char * proxy_orig;	/**< @brief Use specified proxy original value given at command line.  */
  const char *proxy_help; /**< @brief Use specified proxy help description.  */
  const char *no_proxy_help; /**< @brief Do not use proxy even if http_proxy is defined help description.  */
  int connect_timeout_arg;	/**< @brief Max time allowed connection to server take (default='30').  */
  char * connect_timeout_orig;	/**< @brief Max time allowed connection to server take original value given at command line.  */
  const char *connect_timeout_help; /**< @brief Max time allowed connection to server take help description.  */
  int connect_timeout_socks_arg;	/**< @brief Same but works around 'SOCKS proxy connect timeout' bug in libcurl (default='30').  */
  char * connect_timeout_socks_orig;	/**< @brief Same but works around 'SOCKS proxy connect timeout' bug in libcurl original value given at command line.  */
  const char *connect_timeout_socks_help; /**< @brief Same but works around 'SOCKS proxy connect timeout' bug in libcurl help description.  */
  int retry_arg;	/**< @brief Number of retries (default='5').  */
  char * retry_orig;	/**< @brief Number of retries original value given at command line.  */
  const char *retry_help; /**< @brief Number of retries help description.  */
  int retry_wait_arg;	/**< @brief wait 5 seconds between retries (default='5').  */
  char * retry_wait_orig;	/**< @brief wait 5 seconds between retries original value given at command line.  */
  const char *retry_wait_help; /**< @brief wait 5 seconds between retries help description.  */
  char * output_video_arg;	/**< @brief Write video to file.  */
  char * output_video_orig;	/**< @brief Write video to file original value given at command line.  */
  const char *output_video_help; /**< @brief Write video to file help description.  */
  int continue_flag;	/**< @brief Resume partially downloaded file (default=off).  */
  const char *continue_help; /**< @brief Resume partially downloaded file help description.  */
  int overwrite_flag;	/**< @brief Overwrite existing file (default=off).  */
  const char *overwrite_help; /**< @brief Overwrite existing file help description.  */
  const char *no_extract_help; /**< @brief Do not actually extract video, simulate only help description.  */
  int limit_rate_arg;	/**< @brief Limit download speed to amount KB/s (0=unlimited) (default='0').  */
  char * limit_rate_orig;	/**< @brief Limit download speed to amount KB/s (0=unlimited) original value given at command line.  */
  const char *limit_rate_help; /**< @brief Limit download speed to amount KB/s (0=unlimited) help description.  */
  char * format_arg;	/**< @brief Download format of video (default='default').  */
  char * format_orig;	/**< @brief Download format of video original value given at command line.  */
  const char *format_help; /**< @brief Download format of video help description.  */
  char * format_map_arg;	/**< @brief Specify format for multiple hosts in a string.  */
  char * format_map_orig;	/**< @brief Specify format for multiple hosts in a string original value given at command line.  */
  const char *format_map_help; /**< @brief Specify format for multiple hosts in a string help description.  */
  int number_videos_flag;	/**< @brief Prepend a numeric prefix to output filenames (default=off).  */
  const char *number_videos_help; /**< @brief Prepend a numeric prefix to output filenames help description.  */
  char * regexp_arg;	/**< @brief Regular expression to cleanup video title, mimics Perl's /what/(gi).  */
  char * regexp_orig;	/**< @brief Regular expression to cleanup video title, mimics Perl's /what/(gi) original value given at command line.  */
  const char *regexp_help; /**< @brief Regular expression to cleanup video title, mimics Perl's /what/(gi) help description.  */
  char * substitute_arg;	/**< @brief Replace matched occurences in filename, mimics Perl's s/old/new/(gi).  */
  char * substitute_orig;	/**< @brief Replace matched occurences in filename, mimics Perl's s/old/new/(gi) original value given at command line.  */
  const char *substitute_help; /**< @brief Replace matched occurences in filename, mimics Perl's s/old/new/(gi) help description.  */
  char * filename_format_arg;	/**< @brief Output filename format (default='%h_%i.%s').  */
  char * filename_format_orig;	/**< @brief Output filename format original value given at command line.  */
  const char *filename_format_help; /**< @brief Output filename format help description.  */
  char * exec_arg;	/**< @brief Command to invoke when transfer finishes.  */
  char * exec_orig;	/**< @brief Command to invoke when transfer finishes original value given at command line.  */
  const char *exec_help; /**< @brief Command to invoke when transfer finishes help description.  */
  const char *exec_run_help; /**< @brief Invoke command specified with --exec help description.  */
  char * stream_exec_arg;	/**< @brief Stream command to be invoked.  */
  char * stream_exec_orig;	/**< @brief Stream command to be invoked original value given at command line.  */
  const char *stream_exec_help; /**< @brief Stream command to be invoked help description.  */
  const char *stream_pass_help; /**< @brief Pass video link to --stream-exec command help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int hosts_given ;	/**< @brief Whether hosts was given.  */
  unsigned int background_given ;	/**< @brief Whether background was given.  */
  unsigned int emit_csv_given ;	/**< @brief Whether emit-csv was given.  */
  unsigned int quiet_given ;	/**< @brief Whether quiet was given.  */
  unsigned int debug_given ;	/**< @brief Whether debug was given.  */
  unsigned int print_fname_given ;	/**< @brief Whether print-fname was given.  */
  unsigned int logfile_given ;	/**< @brief Whether logfile was given.  */
  unsigned int logfile_interval_given ;	/**< @brief Whether logfile-interval was given.  */
  unsigned int agent_given ;	/**< @brief Whether agent was given.  */
  unsigned int proxy_given ;	/**< @brief Whether proxy was given.  */
  unsigned int no_proxy_given ;	/**< @brief Whether no-proxy was given.  */
  unsigned int connect_timeout_given ;	/**< @brief Whether connect-timeout was given.  */
  unsigned int connect_timeout_socks_given ;	/**< @brief Whether connect-timeout-socks was given.  */
  unsigned int retry_given ;	/**< @brief Whether retry was given.  */
  unsigned int retry_wait_given ;	/**< @brief Whether retry-wait was given.  */
  unsigned int output_video_given ;	/**< @brief Whether output-video was given.  */
  unsigned int continue_given ;	/**< @brief Whether continue was given.  */
  unsigned int overwrite_given ;	/**< @brief Whether overwrite was given.  */
  unsigned int no_extract_given ;	/**< @brief Whether no-extract was given.  */
  unsigned int limit_rate_given ;	/**< @brief Whether limit-rate was given.  */
  unsigned int format_given ;	/**< @brief Whether format was given.  */
  unsigned int format_map_given ;	/**< @brief Whether format-map was given.  */
  unsigned int number_videos_given ;	/**< @brief Whether number-videos was given.  */
  unsigned int regexp_given ;	/**< @brief Whether regexp was given.  */
  unsigned int substitute_given ;	/**< @brief Whether substitute was given.  */
  unsigned int filename_format_given ;	/**< @brief Whether filename-format was given.  */
  unsigned int exec_given ;	/**< @brief Whether exec was given.  */
  unsigned int exec_run_given ;	/**< @brief Whether exec-run was given.  */
  unsigned int stream_exec_given ;	/**< @brief Whether stream-exec was given.  */
  unsigned int stream_pass_given ;	/**< @brief Whether stream-pass was given.  */

  char **inputs ; /**< @brief unamed options (options without names) */
  unsigned inputs_num ; /**< @brief unamed options number */
} ;

/** @brief The additional parameters to pass to parser functions */
struct cmdline_parser_params
{
  int override; /**< @brief whether to override possibly already present options (default 0) */
  int initialize; /**< @brief whether to initialize the option structure gengetopt_args_info (default 1) */
  int check_required; /**< @brief whether to check that all required options were provided (default 1) */
  int check_ambiguity; /**< @brief whether to check for options already specified in the option structure gengetopt_args_info (default 0) */
  int print_errors; /**< @brief whether getopt_long should print an error message for a bad option (default 1) */
} ;

/** @brief the purpose string of the program */
extern const char *gengetopt_args_info_purpose;
/** @brief the usage string of the program */
extern const char *gengetopt_args_info_usage;
/** @brief all the lines making the help output */
extern const char *gengetopt_args_info_help[];

/**
 * The command line parser
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser (int argc, char **argv,
  struct gengetopt_args_info *args_info);

/**
 * The command line parser (version with additional parameters - deprecated)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_ext() instead
 */
int cmdline_parser2 (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The command line parser (version with additional parameters)
 * @param argc the number of command line options
 * @param argv the command line options
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_ext (int argc, char **argv,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Save the contents of the option struct into an already open FILE stream.
 * @param outfile the stream where to dump options
 * @param args_info the option struct to dump
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_dump(FILE *outfile,
  struct gengetopt_args_info *args_info);

/**
 * Save the contents of the option struct into a (text) file.
 * This file can be read by the config file parser (if generated by gengetopt)
 * @param filename the file where to save
 * @param args_info the option struct to save
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_file_save(const char *filename,
  struct gengetopt_args_info *args_info);

/**
 * Print the help
 */
void cmdline_parser_print_help(void);
/**
 * Print the version
 */
void cmdline_parser_print_version(void);

/**
 * Initializes all the fields a cmdline_parser_params structure 
 * to their default values
 * @param params the structure to initialize
 */
void cmdline_parser_params_init(struct cmdline_parser_params *params);

/**
 * Allocates dynamically a cmdline_parser_params structure and initializes
 * all its fields to their default values
 * @return the created and initialized cmdline_parser_params structure
 */
struct cmdline_parser_params *cmdline_parser_params_create(void);

/**
 * Initializes the passed gengetopt_args_info structure's fields
 * (also set default values for options that have a default)
 * @param args_info the structure to initialize
 */
void cmdline_parser_init (struct gengetopt_args_info *args_info);
/**
 * Deallocates the string fields of the gengetopt_args_info structure
 * (but does not deallocate the structure itself)
 * @param args_info the structure to deallocate
 */
void cmdline_parser_free (struct gengetopt_args_info *args_info);

/**
 * The config file parser (deprecated version)
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param override whether to override possibly already present options
 * @param initialize whether to initialize the option structure my_args_info
 * @param check_required whether to check that all required options were provided
 * @return 0 if everything went fine, NON 0 if an error took place
 * @deprecated use cmdline_parser_config_file() instead
 */
int cmdline_parser_configfile (const char *filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_config_file (const char *filename,
  struct gengetopt_args_info *args_info,
  struct cmdline_parser_params *params);

/**
 * Checks that all the required options were specified
 * @param args_info the structure to check
 * @param prog_name the name of the program that will be used to print
 *   possible errors
 * @return
 */
int cmdline_parser_required (struct gengetopt_args_info *args_info,
  const char *prog_name);


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
