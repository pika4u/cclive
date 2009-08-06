/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22.2
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
  const char *version_help; /**< @brief print version and exit help description.  */
  const char *hosts_help; /**< @brief list supported hosts help description.  */
  const char *quiet_help; /**< @brief turn off all output help description.  */
  const char *debug_help; /**< @brief show curl debug messages help description.  */
  const char *emit_csv_help; /**< @brief emit video details as csv to stdout help description.  */
  const char *print_fname_help; /**< @brief print output filename on a single line help description.  */
  char * agent_arg;	/**< @brief identify as string (default='Mozilla/5.0').  */
  char * agent_orig;	/**< @brief identify as string original value given at command line.  */
  const char *agent_help; /**< @brief identify as string help description.  */
  char * proxy_arg;	/**< @brief use specified proxy.  */
  char * proxy_orig;	/**< @brief use specified proxy original value given at command line.  */
  const char *proxy_help; /**< @brief use specified proxy help description.  */
  const char *no_proxy_help; /**< @brief do not use proxy even if http_proxy is defined help description.  */
  int connect_timeout_arg;	/**< @brief max time allowed connection to server take (default='30').  */
  char * connect_timeout_orig;	/**< @brief max time allowed connection to server take original value given at command line.  */
  const char *connect_timeout_help; /**< @brief max time allowed connection to server take help description.  */
  int connect_timeout_socks_arg;	/**< @brief identical but tries to work around SOCKS proxy bug in libcurl (default='30').  */
  char * connect_timeout_socks_orig;	/**< @brief identical but tries to work around SOCKS proxy bug in libcurl original value given at command line.  */
  const char *connect_timeout_socks_help; /**< @brief identical but tries to work around SOCKS proxy bug in libcurl help description.  */
  const char *no_extract_help; /**< @brief do not actually extract video, simulate only help description.  */
  const char *continue_help; /**< @brief resume partially downloaded file help description.  */
  int limit_rate_arg;	/**< @brief limit download speed to KB/s.  */
  char * limit_rate_orig;	/**< @brief limit download speed to KB/s original value given at command line.  */
  const char *limit_rate_help; /**< @brief limit download speed to KB/s help description.  */
  char * output_video_arg;	/**< @brief write video to file.  */
  char * output_video_orig;	/**< @brief write video to file original value given at command line.  */
  const char *output_video_help; /**< @brief write video to file help description.  */
  char * format_arg;	/**< @brief download video format (default='flv').  */
  char * format_orig;	/**< @brief download video format original value given at command line.  */
  const char *format_help; /**< @brief download video format help description.  */
  const char *number_videos_help; /**< @brief prepend a numeric prefix to output filenames help description.  */
  char * filename_format_arg;	/**< @brief use output filename format (default='%t.%s').  */
  char * filename_format_orig;	/**< @brief use output filename format original value given at command line.  */
  const char *filename_format_help; /**< @brief use output filename format help description.  */
  char * regexp_arg;	/**< @brief regular expression to filter video title.  */
  char * regexp_orig;	/**< @brief regular expression to filter video title original value given at command line.  */
  const char *regexp_help; /**< @brief regular expression to filter video title help description.  */
  const char *find_all_help; /**< @brief use repeated matching to find all occurences, like Perl's /g option help description.  */
  char * exec_arg;	/**< @brief command to invoke when transfer finishes.  */
  char * exec_orig;	/**< @brief command to invoke when transfer finishes original value given at command line.  */
  const char *exec_help; /**< @brief command to invoke when transfer finishes help description.  */
  const char *exec_run_help; /**< @brief invoke command defined with --exec help description.  */
  char * stream_exec_arg;	/**< @brief stream command to be invoked.  */
  char * stream_exec_orig;	/**< @brief stream command to be invoked original value given at command line.  */
  const char *stream_exec_help; /**< @brief stream command to be invoked help description.  */
  const char *stream_pass_help; /**< @brief pass video link to --stream-exec command help description.  */
  int stream_arg;	/**< @brief invoke --stream-exec when transfer reaches %.  */
  char * stream_orig;	/**< @brief invoke --stream-exec when transfer reaches % original value given at command line.  */
  const char *stream_help; /**< @brief invoke --stream-exec when transfer reaches % help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int hosts_given ;	/**< @brief Whether hosts was given.  */
  unsigned int quiet_given ;	/**< @brief Whether quiet was given.  */
  unsigned int debug_given ;	/**< @brief Whether debug was given.  */
  unsigned int emit_csv_given ;	/**< @brief Whether emit-csv was given.  */
  unsigned int print_fname_given ;	/**< @brief Whether print-fname was given.  */
  unsigned int agent_given ;	/**< @brief Whether agent was given.  */
  unsigned int proxy_given ;	/**< @brief Whether proxy was given.  */
  unsigned int no_proxy_given ;	/**< @brief Whether no-proxy was given.  */
  unsigned int connect_timeout_given ;	/**< @brief Whether connect-timeout was given.  */
  unsigned int connect_timeout_socks_given ;	/**< @brief Whether connect-timeout-socks was given.  */
  unsigned int no_extract_given ;	/**< @brief Whether no-extract was given.  */
  unsigned int continue_given ;	/**< @brief Whether continue was given.  */
  unsigned int limit_rate_given ;	/**< @brief Whether limit-rate was given.  */
  unsigned int output_video_given ;	/**< @brief Whether output-video was given.  */
  unsigned int format_given ;	/**< @brief Whether format was given.  */
  unsigned int number_videos_given ;	/**< @brief Whether number-videos was given.  */
  unsigned int filename_format_given ;	/**< @brief Whether filename-format was given.  */
  unsigned int regexp_given ;	/**< @brief Whether regexp was given.  */
  unsigned int find_all_given ;	/**< @brief Whether find-all was given.  */
  unsigned int exec_given ;	/**< @brief Whether exec was given.  */
  unsigned int exec_run_given ;	/**< @brief Whether exec-run was given.  */
  unsigned int stream_exec_given ;	/**< @brief Whether stream-exec was given.  */
  unsigned int stream_pass_given ;	/**< @brief Whether stream-pass was given.  */
  unsigned int stream_given ;	/**< @brief Whether stream was given.  */

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
int cmdline_parser (int argc, char * const *argv,
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
int cmdline_parser2 (int argc, char * const *argv,
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
int cmdline_parser_ext (int argc, char * const *argv,
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

extern const char *cmdline_parser_format_values[];  /**< @brief Possible values for format. */


#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* CMDLINE_H */
