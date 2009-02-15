/*
  File autogenerated by gengetopt version 2.22.1
  generated with the following command:
  gengetopt -C --unamed-opts=URL --no-version 

  The developers of gengetopt consider the fixed text that goes in all
  gengetopt output files to be in the public domain:
  we make no copyright claims on it.
*/

/* If we use autoconf.  */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "getopt.h"

#include "cmdline.h"

const char *gengetopt_args_info_purpose = "";

const char *gengetopt_args_info_usage = "Usage: cclive [OPTIONS]... [URL]...";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                   Print help and exit",
  "  -v, --version                print version and exit",
  "      --supported-hosts        list supported hosts",
  "  -q, --quiet                  turn off all output",
  "      --debug                  show curl debug messages",
  "  -n, --no-extract             do not extract video",
  "  -c, --continue               resume partially downloaded file",
  "  -f, --download=FORMAT        download format  (possible values=\"flv\", \n                                 \"mp4\", \"wmv\", \"3gpp\", \"xflv\", \n                                 \"spark\", \"spak-mini\", \"vp6-hq\", \n                                 \"vp6-hd\", \"vp6\", \"h264\" default=`flv')",
  "  -O, --output-video=FILE      write video to file",
  "  -N, --number-videos          number extracted videos",
  "      --emit-csv               emit video details as csv to stdout",
  "      --limit-rate=AMOUNT      limit download speed to amount kb per second",
  "      --agent=STRING           identify as string  (default=`Mozilla/5.0')",
  "      --proxy=ADDRESS          use address for http proxy",
  "      --no-proxy               do not use proxy, even if http_proxy environment \n                                    variable is defined",
  "  -u, --youtube-user=USERNAME  login username for youtube",
  "  -p, --youtube-pass=PASSWORD  login password for youtube, prompt if undefined",
  "  -e, --exec=COMMAND           execute subsequent command with extracted video",
    0
};

typedef enum {ARG_NO
  , ARG_STRING
  , ARG_INT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);

static int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error);
struct line_list
{
  char * string_arg;
  struct line_list * next;
};

static struct line_list *cmd_line_list = 0;
static struct line_list *cmd_line_list_tmp = 0;

static void
free_cmd_list(void)
{
  /* free the list of a previous call */
  if (cmd_line_list)
    {
      while (cmd_line_list) {
        cmd_line_list_tmp = cmd_line_list;
        cmd_line_list = cmd_line_list->next;
        free (cmd_line_list_tmp->string_arg);
        free (cmd_line_list_tmp);
      }
    }
}


char *cmdline_parser_download_values[] = {"flv", "mp4", "wmv", "3gpp", "xflv", "spark", "spak-mini", "vp6-hq", "vp6-hd", "vp6", "h264", 0} ;	/* Possible values for download.  */

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->supported_hosts_given = 0 ;
  args_info->quiet_given = 0 ;
  args_info->debug_given = 0 ;
  args_info->no_extract_given = 0 ;
  args_info->continue_given = 0 ;
  args_info->download_given = 0 ;
  args_info->output_video_given = 0 ;
  args_info->number_videos_given = 0 ;
  args_info->emit_csv_given = 0 ;
  args_info->limit_rate_given = 0 ;
  args_info->agent_given = 0 ;
  args_info->proxy_given = 0 ;
  args_info->no_proxy_given = 0 ;
  args_info->youtube_user_given = 0 ;
  args_info->youtube_pass_given = 0 ;
  args_info->exec_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->download_arg = gengetopt_strdup ("flv");
  args_info->download_orig = NULL;
  args_info->output_video_arg = NULL;
  args_info->output_video_orig = NULL;
  args_info->limit_rate_orig = NULL;
  args_info->agent_arg = gengetopt_strdup ("Mozilla/5.0");
  args_info->agent_orig = NULL;
  args_info->proxy_arg = NULL;
  args_info->proxy_orig = NULL;
  args_info->youtube_user_arg = NULL;
  args_info->youtube_user_orig = NULL;
  args_info->youtube_pass_arg = NULL;
  args_info->youtube_pass_orig = NULL;
  args_info->exec_arg = NULL;
  args_info->exec_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->supported_hosts_help = gengetopt_args_info_help[2] ;
  args_info->quiet_help = gengetopt_args_info_help[3] ;
  args_info->debug_help = gengetopt_args_info_help[4] ;
  args_info->no_extract_help = gengetopt_args_info_help[5] ;
  args_info->continue_help = gengetopt_args_info_help[6] ;
  args_info->download_help = gengetopt_args_info_help[7] ;
  args_info->output_video_help = gengetopt_args_info_help[8] ;
  args_info->number_videos_help = gengetopt_args_info_help[9] ;
  args_info->emit_csv_help = gengetopt_args_info_help[10] ;
  args_info->limit_rate_help = gengetopt_args_info_help[11] ;
  args_info->agent_help = gengetopt_args_info_help[12] ;
  args_info->proxy_help = gengetopt_args_info_help[13] ;
  args_info->no_proxy_help = gengetopt_args_info_help[14] ;
  args_info->youtube_user_help = gengetopt_args_info_help[15] ;
  args_info->youtube_pass_help = gengetopt_args_info_help[16] ;
  args_info->exec_help = gengetopt_args_info_help[17] ;
  
}

void
cmdline_parser_print_version (void)
{
  printf ("%s %s\n", CMDLINE_PARSER_PACKAGE, CMDLINE_PARSER_VERSION);
}

static void print_help_common(void) {
  cmdline_parser_print_version ();

  if (strlen(gengetopt_args_info_purpose) > 0)
    printf("\n%s\n", gengetopt_args_info_purpose);

  if (strlen(gengetopt_args_info_usage) > 0)
    printf("\n%s\n", gengetopt_args_info_usage);

  printf("\n");

  if (strlen(gengetopt_args_info_description) > 0)
    printf("%s\n\n", gengetopt_args_info_description);
}

void
cmdline_parser_print_help (void)
{
  int i = 0;
  print_help_common();
  while (gengetopt_args_info_help[i])
    printf("%s\n", gengetopt_args_info_help[i++]);
}

void
cmdline_parser_init (struct gengetopt_args_info *args_info)
{
  clear_given (args_info);
  clear_args (args_info);
  init_args_info (args_info);

  args_info->inputs = NULL;
  args_info->inputs_num = 0;
}

void
cmdline_parser_params_init(struct cmdline_parser_params *params)
{
  if (params)
    { 
      params->override = 0;
      params->initialize = 1;
      params->check_required = 1;
      params->check_ambiguity = 0;
      params->print_errors = 1;
    }
}

struct cmdline_parser_params *
cmdline_parser_params_create(void)
{
  struct cmdline_parser_params *params = 
    (struct cmdline_parser_params *)malloc(sizeof(struct cmdline_parser_params));
  cmdline_parser_params_init(params);  
  return params;
}

static void
free_string_field (char **s)
{
  if (*s)
    {
      free (*s);
      *s = 0;
    }
}


static void
cmdline_parser_release (struct gengetopt_args_info *args_info)
{
  unsigned int i;
  free_string_field (&(args_info->download_arg));
  free_string_field (&(args_info->download_orig));
  free_string_field (&(args_info->output_video_arg));
  free_string_field (&(args_info->output_video_orig));
  free_string_field (&(args_info->limit_rate_orig));
  free_string_field (&(args_info->agent_arg));
  free_string_field (&(args_info->agent_orig));
  free_string_field (&(args_info->proxy_arg));
  free_string_field (&(args_info->proxy_orig));
  free_string_field (&(args_info->youtube_user_arg));
  free_string_field (&(args_info->youtube_user_orig));
  free_string_field (&(args_info->youtube_pass_arg));
  free_string_field (&(args_info->youtube_pass_orig));
  free_string_field (&(args_info->exec_arg));
  free_string_field (&(args_info->exec_orig));
  
  
  for (i = 0; i < args_info->inputs_num; ++i)
    free (args_info->inputs [i]);

  if (args_info->inputs_num)
    free (args_info->inputs);

  clear_given (args_info);
}

/**
 * @param val the value to check
 * @param values the possible values
 * @return the index of the matched value:
 * -1 if no value matched,
 * -2 if more than one value has matched
 */
static int
check_possible_values(const char *val, char *values[])
{
  int i, found, last;
  size_t len;

  if (!val)   /* otherwise strlen() crashes below */
    return -1; /* -1 means no argument for the option */

  found = last = 0;

  for (i = 0, len = strlen(val); values[i]; ++i)
    {
      if (strncmp(val, values[i], len) == 0)
        {
          ++found;
          last = i;
          if (strlen(values[i]) == len)
            return i; /* exact macth no need to check more */
        }
    }

  if (found == 1) /* one match: OK */
    return last;

  return (found ? -2 : -1); /* return many values or none matched */
}


static void
write_into_file(FILE *outfile, const char *opt, const char *arg, char *values[])
{
  int found = -1;
  if (arg) {
    if (values) {
      found = check_possible_values(arg, values);      
    }
    if (found >= 0)
      fprintf(outfile, "%s=\"%s\" # %s\n", opt, arg, values[found]);
    else
      fprintf(outfile, "%s=\"%s\"\n", opt, arg);
  } else {
    fprintf(outfile, "%s\n", opt);
  }
}


int
cmdline_parser_dump(FILE *outfile, struct gengetopt_args_info *args_info)
{
  int i = 0;

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot dump options to stream\n", CMDLINE_PARSER_PACKAGE);
      return EXIT_FAILURE;
    }

  if (args_info->help_given)
    write_into_file(outfile, "help", 0, 0 );
  if (args_info->version_given)
    write_into_file(outfile, "version", 0, 0 );
  if (args_info->supported_hosts_given)
    write_into_file(outfile, "supported-hosts", 0, 0 );
  if (args_info->quiet_given)
    write_into_file(outfile, "quiet", 0, 0 );
  if (args_info->debug_given)
    write_into_file(outfile, "debug", 0, 0 );
  if (args_info->no_extract_given)
    write_into_file(outfile, "no-extract", 0, 0 );
  if (args_info->continue_given)
    write_into_file(outfile, "continue", 0, 0 );
  if (args_info->download_given)
    write_into_file(outfile, "download", args_info->download_orig, cmdline_parser_download_values);
  if (args_info->output_video_given)
    write_into_file(outfile, "output-video", args_info->output_video_orig, 0);
  if (args_info->number_videos_given)
    write_into_file(outfile, "number-videos", 0, 0 );
  if (args_info->emit_csv_given)
    write_into_file(outfile, "emit-csv", 0, 0 );
  if (args_info->limit_rate_given)
    write_into_file(outfile, "limit-rate", args_info->limit_rate_orig, 0);
  if (args_info->agent_given)
    write_into_file(outfile, "agent", args_info->agent_orig, 0);
  if (args_info->proxy_given)
    write_into_file(outfile, "proxy", args_info->proxy_orig, 0);
  if (args_info->no_proxy_given)
    write_into_file(outfile, "no-proxy", 0, 0 );
  if (args_info->youtube_user_given)
    write_into_file(outfile, "youtube-user", args_info->youtube_user_orig, 0);
  if (args_info->youtube_pass_given)
    write_into_file(outfile, "youtube-pass", args_info->youtube_pass_orig, 0);
  if (args_info->exec_given)
    write_into_file(outfile, "exec", args_info->exec_orig, 0);
  

  i = EXIT_SUCCESS;
  return i;
}

int
cmdline_parser_file_save(const char *filename, struct gengetopt_args_info *args_info)
{
  FILE *outfile;
  int i = 0;

  outfile = fopen(filename, "w");

  if (!outfile)
    {
      fprintf (stderr, "%s: cannot open file for writing: %s\n", CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  i = cmdline_parser_dump(outfile, args_info);
  fclose (outfile);

  return i;
}

void
cmdline_parser_free (struct gengetopt_args_info *args_info)
{
  cmdline_parser_release (args_info);
}

/** @brief replacement of strdup, which is not standard */
char *
gengetopt_strdup (const char *s)
{
  char *result = NULL;
  if (!s)
    return result;

  result = (char*)malloc(strlen(s) + 1);
  if (result == (char*)0)
    return (char*)0;
  strcpy(result, s);
  return result;
}

int
cmdline_parser (int argc, char * const *argv, struct gengetopt_args_info *args_info)
{
  return cmdline_parser2 (argc, argv, args_info, 0, 1, 1);
}

int
cmdline_parser_ext (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                   struct cmdline_parser_params *params)
{
  int result;
  result = cmdline_parser_internal (argc, argv, args_info, params, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser2 (int argc, char * const *argv, struct gengetopt_args_info *args_info, int override, int initialize, int check_required)
{
  int result;
  struct cmdline_parser_params params;
  
  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;

  result = cmdline_parser_internal (argc, argv, args_info, &params, NULL);

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  int result = EXIT_SUCCESS;

  if (cmdline_parser_required2(args_info, prog_name, NULL) > 0)
    result = EXIT_FAILURE;

  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}

int
cmdline_parser_required2 (struct gengetopt_args_info *args_info, const char *prog_name, const char *additional_error)
{
  int error = 0;

  /* checks for required options */
  
  /* checks for dependences among options */
  if (args_info->youtube_pass_given && ! args_info->youtube_user_given)
    {
      fprintf (stderr, "%s: '--youtube-pass' ('-p') option depends on option 'youtube-user'%s\n", prog_name, (additional_error ? additional_error : ""));
      error = 1;
    }

  return error;
}


static char *package_name = 0;

/**
 * @brief updates an option
 * @param field the generic pointer to the field to update
 * @param orig_field the pointer to the orig field
 * @param field_given the pointer to the number of occurrence of this option
 * @param prev_given the pointer to the number of occurrence already seen
 * @param value the argument for this option (if null no arg was specified)
 * @param possible_values the possible values for this option (if specified)
 * @param default_value the default value (in case the option only accepts fixed values)
 * @param arg_type the type of this option
 * @param check_ambiguity @see cmdline_parser_params.check_ambiguity
 * @param override @see cmdline_parser_params.override
 * @param no_free whether to free a possible previous value
 * @param multiple_option whether this is a multiple option
 * @param long_opt the corresponding long option
 * @param short_opt the corresponding short option (or '-' if none)
 * @param additional_error possible further error specification
 */
static
int update_arg(void *field, char **orig_field,
               unsigned int *field_given, unsigned int *prev_given, 
               char *value, char *possible_values[], const char *default_value,
               cmdline_parser_arg_type arg_type,
               int check_ambiguity, int override,
               int no_free, int multiple_option,
               const char *long_opt, char short_opt,
               const char *additional_error)
{
  char *stop_char = 0;
  const char *val = value;
  int found;
  char **string_field;

  stop_char = 0;
  found = 0;

  if (!multiple_option && prev_given && (*prev_given || (check_ambiguity && *field_given)))
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: `--%s' (`-%c') option given more than once%s\n", 
               package_name, long_opt, short_opt,
               (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: `--%s' option given more than once%s\n", 
               package_name, long_opt,
               (additional_error ? additional_error : ""));
      return 1; /* failure */
    }

  if (possible_values && (found = check_possible_values((value ? value : default_value), possible_values)) < 0)
    {
      if (short_opt != '-')
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s' (`-%c')%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt, short_opt,
          (additional_error ? additional_error : ""));
      else
        fprintf (stderr, "%s: %s argument, \"%s\", for option `--%s'%s\n", 
          package_name, (found == -2) ? "ambiguous" : "invalid", value, long_opt,
          (additional_error ? additional_error : ""));
      return 1; /* failure */
    }
    
  if (field_given && *field_given && ! override)
    return 0;
  if (prev_given)
    (*prev_given)++;
  if (field_given)
    (*field_given)++;
  if (possible_values)
    val = possible_values[found];

  switch(arg_type) {
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_STRING:
    if (val) {
      string_field = (char **)field;
      if (!no_free && *string_field)
        free (*string_field); /* free previous string */
      *string_field = gengetopt_strdup (val);
    }
    break;
  default:
    break;
  };

  /* check numeric conversion */
  switch(arg_type) {
  case ARG_INT:
    if (val && !(stop_char && *stop_char == '\0')) {
      fprintf(stderr, "%s: invalid numeric value: %s\n", package_name, val);
      return 1; /* failure */
    }
    break;
  default:
    ;
  };

  /* store the original value */
  switch(arg_type) {
  case ARG_NO:
    break;
  default:
    if (value && orig_field) {
      if (no_free) {
        *orig_field = value;
      } else {
        if (*orig_field)
          free (*orig_field); /* free previous string */
        *orig_field = gengetopt_strdup (value);
      }
    }
  };

  return 0; /* OK */
}


int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error)
{
  int c;	/* Character of the parsed option.  */

  int error = 0;
  struct gengetopt_args_info local_args_info;
  
  int override;
  int initialize;
  int check_required;
  int check_ambiguity;
  
  package_name = argv[0];
  
  override = params->override;
  initialize = params->initialize;
  check_required = params->check_required;
  check_ambiguity = params->check_ambiguity;

  if (initialize)
    cmdline_parser_init (args_info);

  cmdline_parser_init (&local_args_info);

  optarg = 0;
  optind = 0;
  opterr = params->print_errors;
  optopt = '?';

  while (1)
    {
      int option_index = 0;

      static struct option long_options[] = {
        { "help",	0, NULL, 'h' },
        { "version",	0, NULL, 'v' },
        { "supported-hosts",	0, NULL, 0 },
        { "quiet",	0, NULL, 'q' },
        { "debug",	0, NULL, 0 },
        { "no-extract",	0, NULL, 'n' },
        { "continue",	0, NULL, 'c' },
        { "download",	1, NULL, 'f' },
        { "output-video",	1, NULL, 'O' },
        { "number-videos",	0, NULL, 'N' },
        { "emit-csv",	0, NULL, 0 },
        { "limit-rate",	1, NULL, 0 },
        { "agent",	1, NULL, 0 },
        { "proxy",	1, NULL, 0 },
        { "no-proxy",	0, NULL, 0 },
        { "youtube-user",	1, NULL, 'u' },
        { "youtube-pass",	1, NULL, 'p' },
        { "exec",	1, NULL, 'e' },
        { NULL,	0, NULL, 0 }
      };

      c = getopt_long (argc, argv, "hvqncf:O:Nu:p:e:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'v':	/* print version and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->version_given),
              &(local_args_info.version_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "version", 'v',
              additional_error))
            goto failure;
        
          break;
        case 'q':	/* turn off all output.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->quiet_given),
              &(local_args_info.quiet_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "quiet", 'q',
              additional_error))
            goto failure;
        
          break;
        case 'n':	/* do not extract video.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->no_extract_given),
              &(local_args_info.no_extract_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "no-extract", 'n',
              additional_error))
            goto failure;
        
          break;
        case 'c':	/* resume partially downloaded file.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->continue_given),
              &(local_args_info.continue_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "continue", 'c',
              additional_error))
            goto failure;
        
          break;
        case 'f':	/* download format.  */
        
        
          if (update_arg( (void *)&(args_info->download_arg), 
               &(args_info->download_orig), &(args_info->download_given),
              &(local_args_info.download_given), optarg, cmdline_parser_download_values, "flv", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "download", 'f',
              additional_error))
            goto failure;
        
          break;
        case 'O':	/* write video to file.  */
        
        
          if (update_arg( (void *)&(args_info->output_video_arg), 
               &(args_info->output_video_orig), &(args_info->output_video_given),
              &(local_args_info.output_video_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "output-video", 'O',
              additional_error))
            goto failure;
        
          break;
        case 'N':	/* number extracted videos.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->number_videos_given),
              &(local_args_info.number_videos_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "number-videos", 'N',
              additional_error))
            goto failure;
        
          break;
        case 'u':	/* login username for youtube.  */
        
        
          if (update_arg( (void *)&(args_info->youtube_user_arg), 
               &(args_info->youtube_user_orig), &(args_info->youtube_user_given),
              &(local_args_info.youtube_user_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "youtube-user", 'u',
              additional_error))
            goto failure;
        
          break;
        case 'p':	/* login password for youtube, prompt if undefined.  */
        
        
          if (update_arg( (void *)&(args_info->youtube_pass_arg), 
               &(args_info->youtube_pass_orig), &(args_info->youtube_pass_given),
              &(local_args_info.youtube_pass_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "youtube-pass", 'p',
              additional_error))
            goto failure;
        
          break;
        case 'e':	/* execute subsequent command with extracted video.  */
        
        
          if (update_arg( (void *)&(args_info->exec_arg), 
               &(args_info->exec_orig), &(args_info->exec_given),
              &(local_args_info.exec_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "exec", 'e',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
          /* list supported hosts.  */
          if (strcmp (long_options[option_index].name, "supported-hosts") == 0)
          {
          
          
            if (update_arg( 0 , 
                 0 , &(args_info->supported_hosts_given),
                &(local_args_info.supported_hosts_given), optarg, 0, 0, ARG_NO,
                check_ambiguity, override, 0, 0,
                "supported-hosts", '-',
                additional_error))
              goto failure;
          
          }
          /* show curl debug messages.  */
          else if (strcmp (long_options[option_index].name, "debug") == 0)
          {
          
          
            if (update_arg( 0 , 
                 0 , &(args_info->debug_given),
                &(local_args_info.debug_given), optarg, 0, 0, ARG_NO,
                check_ambiguity, override, 0, 0,
                "debug", '-',
                additional_error))
              goto failure;
          
          }
          /* emit video details as csv to stdout.  */
          else if (strcmp (long_options[option_index].name, "emit-csv") == 0)
          {
          
          
            if (update_arg( 0 , 
                 0 , &(args_info->emit_csv_given),
                &(local_args_info.emit_csv_given), optarg, 0, 0, ARG_NO,
                check_ambiguity, override, 0, 0,
                "emit-csv", '-',
                additional_error))
              goto failure;
          
          }
          /* limit download speed to amount kb per second.  */
          else if (strcmp (long_options[option_index].name, "limit-rate") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->limit_rate_arg), 
                 &(args_info->limit_rate_orig), &(args_info->limit_rate_given),
                &(local_args_info.limit_rate_given), optarg, 0, 0, ARG_INT,
                check_ambiguity, override, 0, 0,
                "limit-rate", '-',
                additional_error))
              goto failure;
          
          }
          /* identify as string.  */
          else if (strcmp (long_options[option_index].name, "agent") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->agent_arg), 
                 &(args_info->agent_orig), &(args_info->agent_given),
                &(local_args_info.agent_given), optarg, 0, "Mozilla/5.0", ARG_STRING,
                check_ambiguity, override, 0, 0,
                "agent", '-',
                additional_error))
              goto failure;
          
          }
          /* use address for http proxy.  */
          else if (strcmp (long_options[option_index].name, "proxy") == 0)
          {
          
          
            if (update_arg( (void *)&(args_info->proxy_arg), 
                 &(args_info->proxy_orig), &(args_info->proxy_given),
                &(local_args_info.proxy_given), optarg, 0, 0, ARG_STRING,
                check_ambiguity, override, 0, 0,
                "proxy", '-',
                additional_error))
              goto failure;
          
          }
          /* do not use proxy, even if http_proxy environment    variable is defined.  */
          else if (strcmp (long_options[option_index].name, "no-proxy") == 0)
          {
          
          
            if (update_arg( 0 , 
                 0 , &(args_info->no_proxy_given),
                &(local_args_info.no_proxy_given), optarg, 0, 0, ARG_NO,
                check_ambiguity, override, 0, 0,
                "no-proxy", '-',
                additional_error))
              goto failure;
          
          }
          
          break;
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */



  if (check_required)
    {
      error += cmdline_parser_required2 (args_info, argv[0], additional_error);
    }

  cmdline_parser_release (&local_args_info);

  if ( error )
    return (EXIT_FAILURE);

  if (optind < argc)
    {
      int i = 0 ;
      int found_prog_name = 0;
      /* whether program name, i.e., argv[0], is in the remaining args
         (this may happen with some implementations of getopt,
          but surely not with the one included by gengetopt) */

      i = optind;
      while (i < argc)
        if (argv[i++] == argv[0]) {
          found_prog_name = 1;
          break;
        }
      i = 0;

      args_info->inputs_num = argc - optind - found_prog_name;
      args_info->inputs =
        (char **)(malloc ((args_info->inputs_num)*sizeof(char *))) ;
      while (optind < argc)
        if (argv[optind++] != argv[0])
          args_info->inputs[ i++ ] = gengetopt_strdup (argv[optind-1]) ;
    }

  return 0;

failure:
  
  cmdline_parser_release (&local_args_info);
  return (EXIT_FAILURE);
}

#ifndef CONFIG_FILE_LINE_SIZE
#define CONFIG_FILE_LINE_SIZE 2048
#endif
#define ADDITIONAL_ERROR " in configuration file "

#define CONFIG_FILE_LINE_BUFFER_SIZE (CONFIG_FILE_LINE_SIZE+3)
/* 3 is for "--" and "=" */

static int
_cmdline_parser_configfile (char * const filename, int *my_argc)
{
  FILE* file;
  char my_argv[CONFIG_FILE_LINE_BUFFER_SIZE+1];
  char linebuf[CONFIG_FILE_LINE_SIZE];
  int line_num = 0;
  int result = 0, equal;
  char *fopt, *farg;
  char *str_index;
  size_t len, next_token;
  char delimiter;

  if ((file = fopen(filename, "r")) == NULL)
    {
      fprintf (stderr, "%s: Error opening configuration file '%s'\n",
               CMDLINE_PARSER_PACKAGE, filename);
      return EXIT_FAILURE;
    }

  while ((fgets(linebuf, CONFIG_FILE_LINE_SIZE, file)) != NULL)
    {
      ++line_num;
      my_argv[0] = '\0';
      len = strlen(linebuf);
      if (len > (CONFIG_FILE_LINE_BUFFER_SIZE-1))
        {
          fprintf (stderr, "%s:%s:%d: Line too long in configuration file\n",
                   CMDLINE_PARSER_PACKAGE, filename, line_num);
          result = EXIT_FAILURE;
          break;
        }

      /* find first non-whitespace character in the line */
      next_token = strspn (linebuf, " \t\r\n");
      str_index  = linebuf + next_token;

      if ( str_index[0] == '\0' || str_index[0] == '#')
        continue; /* empty line or comment line is skipped */

      fopt = str_index;

      /* truncate fopt at the end of the first non-valid character */
      next_token = strcspn (fopt, " \t\r\n=");

      if (fopt[next_token] == '\0') /* the line is over */
        {
          farg  = NULL;
          equal = 0;
          goto noarg;
        }

      /* remember if equal sign is present */
      equal = (fopt[next_token] == '=');
      fopt[next_token++] = '\0';

      /* advance pointers to the next token after the end of fopt */
      next_token += strspn (fopt + next_token, " \t\r\n");

      /* check for the presence of equal sign, and if so, skip it */
      if ( !equal )
        if ((equal = (fopt[next_token] == '=')))
          {
            next_token++;
            next_token += strspn (fopt + next_token, " \t\r\n");
          }
      str_index  += next_token;

      /* find argument */
      farg = str_index;
      if ( farg[0] == '\"' || farg[0] == '\'' )
        { /* quoted argument */
          str_index = strchr (++farg, str_index[0] ); /* skip opening quote */
          if (! str_index)
            {
              fprintf
                (stderr,
                 "%s:%s:%d: unterminated string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }
      else
        { /* read up the remaining part up to a delimiter */
          next_token = strcspn (farg, " \t\r\n#\'\"");
          str_index += next_token;
        }

      /* truncate farg at the delimiter and store it for further check */
      delimiter = *str_index, *str_index++ = '\0';

      /* everything but comment is illegal at the end of line */
      if (delimiter != '\0' && delimiter != '#')
        {
          str_index += strspn(str_index, " \t\r\n");
          if (*str_index != '\0' && *str_index != '#')
            {
              fprintf
                (stderr,
                 "%s:%s:%d: malformed string in configuration file\n",
                 CMDLINE_PARSER_PACKAGE, filename, line_num);
              result = EXIT_FAILURE;
              break;
            }
        }

    noarg:
      if (!strcmp(fopt,"include")) {
        if (farg && *farg) {
          result = _cmdline_parser_configfile(farg, my_argc);
        } else {
          fprintf(stderr, "%s:%s:%d: include requires a filename argument.\n",
                  CMDLINE_PARSER_PACKAGE, filename, line_num);
        }
        continue;
      }
      len = strlen(fopt);
      strcat (my_argv, len > 1 ? "--" : "-");
      strcat (my_argv, fopt);
      if (len > 1 && ((farg && *farg) || equal))
        strcat (my_argv, "=");
      if (farg && *farg)
        strcat (my_argv, farg);
      ++(*my_argc);

      cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
      cmd_line_list_tmp->next = cmd_line_list;
      cmd_line_list = cmd_line_list_tmp;
      cmd_line_list->string_arg = gengetopt_strdup(my_argv);
    } /* while */

  if (file)
    fclose(file);
  return result;
}

int
cmdline_parser_configfile (char * const filename,
                           struct gengetopt_args_info *args_info,
                           int override, int initialize, int check_required)
{
  struct cmdline_parser_params params;

  params.override = override;
  params.initialize = initialize;
  params.check_required = check_required;
  params.check_ambiguity = 0;
  params.print_errors = 1;
  
  return cmdline_parser_config_file (filename, args_info, &params);
}

int
cmdline_parser_config_file (char * const filename,
                           struct gengetopt_args_info *args_info,
                           struct cmdline_parser_params *params)
{
  int i, result;
  int my_argc = 1;
  char **my_argv_arg;
  char *additional_error;

  /* store the program name */
  cmd_line_list_tmp = (struct line_list *) malloc (sizeof (struct line_list));
  cmd_line_list_tmp->next = cmd_line_list;
  cmd_line_list = cmd_line_list_tmp;
  cmd_line_list->string_arg = gengetopt_strdup (CMDLINE_PARSER_PACKAGE);

  result = _cmdline_parser_configfile(filename, &my_argc);

  if (result != EXIT_FAILURE) {
    my_argv_arg = (char **) malloc((my_argc+1) * sizeof(char *));
    cmd_line_list_tmp = cmd_line_list;

    for (i = my_argc - 1; i >= 0; --i) {
      my_argv_arg[i] = cmd_line_list_tmp->string_arg;
      cmd_line_list_tmp = cmd_line_list_tmp->next;
    }

    my_argv_arg[my_argc] = 0;

    additional_error = (char *)malloc(strlen(filename) + strlen(ADDITIONAL_ERROR) + 1);
    strcpy (additional_error, ADDITIONAL_ERROR);
    strcat (additional_error, filename);
    result =
      cmdline_parser_internal (my_argc, my_argv_arg, args_info,
                              params,
                              additional_error);

    free (additional_error);
    free (my_argv_arg);
  }

  free_cmd_list();
  if (result == EXIT_FAILURE)
    {
      cmdline_parser_free (args_info);
      exit (EXIT_FAILURE);
    }
  
  return result;
}
