/*
  File autogenerated by gengetopt version 2.22
  generated with the following command:
  /Genomics/ogtr03/cypark/sleipnir/../sleipnir-extlib/gengetopt-2.22/src/gengetopt -iSparseNetCombiner.ggo --default-optional -u -N -e 

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

const char *gengetopt_args_info_purpose = "SparseNetwork(Dat/Dab) file combination(mean/max) tool; Assumes sparse \nconnected network with IDENTICAL gene sets.(gene order may differ, use map flag \nfor those cases)";

const char *gengetopt_args_info_usage = "Usage: NetworkCombiner [OPTIONS]... [FILES]...";

const char *gengetopt_args_info_description = "";

const char *gengetopt_args_info_help[] = {
  "  -h, --help                 Print help and exit",
  "  -V, --version              Print version and exit",
  "\nMain:",
  "  -o, --output=filename      Output file",
  "  -v, --verbosity=INT        Message verbosity  (default=`5')",
  "  -d, --directory=directory  input directory (must only contain input files)",
  "  -m, --map                  Map gene index among the network dabs to combine. \n                               (Should be used when the gene intex are not \n                               identical among network dabs)  (default=off)",
  "  -M, --method=STRING        Combination method, (selectmean computes the mea \n                               of the upper quartile values)  (possible \n                               values=\"max\", \"mean\", \"median\", \"quant\", \n                               \"selectmean\" default=`mean')",
  "\nOptional:",
  "  -q, --quantile=FLOAT       If combine method is Quantile, set the returning \n                               quantile (default is median qunatile 0.5)  \n                               (default=`0.5')",
  "  -w, --weight=filename      File with dataset weights, if given each dataset \n                               values if weighted by the dataset weight. Skips \n                               datasets with no-entry or with zero weights. \n                               File format: dataset name<tab>weight",
  "  -z, --zscore               Convert values to z-scores before combine  \n                               (default=off)",
  "  -r, --rank                 Rank transform data before combine  (default=off)",
  "\nFiltering:",
  "  -g, --genes=filename       Process only genes from the given set",
  "  -D, --genee=filename       Process only edges including a gene from the given \n                               set",
    0
};

typedef enum {ARG_NO
  , ARG_FLAG
  , ARG_STRING
  , ARG_INT
  , ARG_FLOAT
} cmdline_parser_arg_type;

static
void clear_given (struct gengetopt_args_info *args_info);
static
void clear_args (struct gengetopt_args_info *args_info);

static int
cmdline_parser_internal (int argc, char * const *argv, struct gengetopt_args_info *args_info,
                        struct cmdline_parser_params *params, const char *additional_error);


char *cmdline_parser_method_values[] = {"max", "mean", "median", "quant", "selectmean", 0} ;	/* Possible values for method.  */

static char *
gengetopt_strdup (const char *s);

static
void clear_given (struct gengetopt_args_info *args_info)
{
  args_info->help_given = 0 ;
  args_info->version_given = 0 ;
  args_info->output_given = 0 ;
  args_info->verbosity_given = 0 ;
  args_info->directory_given = 0 ;
  args_info->map_given = 0 ;
  args_info->method_given = 0 ;
  args_info->quantile_given = 0 ;
  args_info->weight_given = 0 ;
  args_info->zscore_given = 0 ;
  args_info->rank_given = 0 ;
  args_info->genes_given = 0 ;
  args_info->genee_given = 0 ;
}

static
void clear_args (struct gengetopt_args_info *args_info)
{
  args_info->output_arg = NULL;
  args_info->output_orig = NULL;
  args_info->verbosity_arg = 5;
  args_info->verbosity_orig = NULL;
  args_info->directory_arg = NULL;
  args_info->directory_orig = NULL;
  args_info->map_flag = 0;
  args_info->method_arg = gengetopt_strdup ("mean");
  args_info->method_orig = NULL;
  args_info->quantile_arg = 0.5;
  args_info->quantile_orig = NULL;
  args_info->weight_arg = NULL;
  args_info->weight_orig = NULL;
  args_info->zscore_flag = 0;
  args_info->rank_flag = 0;
  args_info->genes_arg = NULL;
  args_info->genes_orig = NULL;
  args_info->genee_arg = NULL;
  args_info->genee_orig = NULL;
  
}

static
void init_args_info(struct gengetopt_args_info *args_info)
{


  args_info->help_help = gengetopt_args_info_help[0] ;
  args_info->version_help = gengetopt_args_info_help[1] ;
  args_info->output_help = gengetopt_args_info_help[3] ;
  args_info->verbosity_help = gengetopt_args_info_help[4] ;
  args_info->directory_help = gengetopt_args_info_help[5] ;
  args_info->map_help = gengetopt_args_info_help[6] ;
  args_info->method_help = gengetopt_args_info_help[7] ;
  args_info->quantile_help = gengetopt_args_info_help[9] ;
  args_info->weight_help = gengetopt_args_info_help[10] ;
  args_info->zscore_help = gengetopt_args_info_help[11] ;
  args_info->rank_help = gengetopt_args_info_help[12] ;
  args_info->genes_help = gengetopt_args_info_help[14] ;
  args_info->genee_help = gengetopt_args_info_help[15] ;
  
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
    printf("%s\n", gengetopt_args_info_description);
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
  free_string_field (&(args_info->output_arg));
  free_string_field (&(args_info->output_orig));
  free_string_field (&(args_info->verbosity_orig));
  free_string_field (&(args_info->directory_arg));
  free_string_field (&(args_info->directory_orig));
  free_string_field (&(args_info->method_arg));
  free_string_field (&(args_info->method_orig));
  free_string_field (&(args_info->quantile_orig));
  free_string_field (&(args_info->weight_arg));
  free_string_field (&(args_info->weight_orig));
  free_string_field (&(args_info->genes_arg));
  free_string_field (&(args_info->genes_orig));
  free_string_field (&(args_info->genee_arg));
  free_string_field (&(args_info->genee_orig));
  
  
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
  if (args_info->output_given)
    write_into_file(outfile, "output", args_info->output_orig, 0);
  if (args_info->verbosity_given)
    write_into_file(outfile, "verbosity", args_info->verbosity_orig, 0);
  if (args_info->directory_given)
    write_into_file(outfile, "directory", args_info->directory_orig, 0);
  if (args_info->map_given)
    write_into_file(outfile, "map", 0, 0 );
  if (args_info->method_given)
    write_into_file(outfile, "method", args_info->method_orig, cmdline_parser_method_values);
  if (args_info->quantile_given)
    write_into_file(outfile, "quantile", args_info->quantile_orig, 0);
  if (args_info->weight_given)
    write_into_file(outfile, "weight", args_info->weight_orig, 0);
  if (args_info->zscore_given)
    write_into_file(outfile, "zscore", 0, 0 );
  if (args_info->rank_given)
    write_into_file(outfile, "rank", 0, 0 );
  if (args_info->genes_given)
    write_into_file(outfile, "genes", args_info->genes_orig, 0);
  if (args_info->genee_given)
    write_into_file(outfile, "genee", args_info->genee_orig, 0);
  

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

  return result;
}

int
cmdline_parser_required (struct gengetopt_args_info *args_info, const char *prog_name)
{
  return EXIT_SUCCESS;
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
  case ARG_FLAG:
    *((int *)field) = !*((int *)field);
    break;
  case ARG_INT:
    if (val) *((int *)field) = strtol (val, &stop_char, 0);
    break;
  case ARG_FLOAT:
    if (val) *((float *)field) = (float)strtod (val, &stop_char);
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
  case ARG_FLOAT:
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
  case ARG_FLAG:
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
        { "version",	0, NULL, 'V' },
        { "output",	1, NULL, 'o' },
        { "verbosity",	1, NULL, 'v' },
        { "directory",	1, NULL, 'd' },
        { "map",	0, NULL, 'm' },
        { "method",	1, NULL, 'M' },
        { "quantile",	1, NULL, 'q' },
        { "weight",	1, NULL, 'w' },
        { "zscore",	0, NULL, 'z' },
        { "rank",	0, NULL, 'r' },
        { "genes",	1, NULL, 'g' },
        { "genee",	1, NULL, 'D' },
        { NULL,	0, NULL, 0 }
      };

      c = getopt_long (argc, argv, "hVo:v:d:mM:q:w:zrg:D:", long_options, &option_index);

      if (c == -1) break;	/* Exit from `while (1)' loop.  */

      switch (c)
        {
        case 'h':	/* Print help and exit.  */
          cmdline_parser_print_help ();
          cmdline_parser_free (&local_args_info);
          exit (EXIT_SUCCESS);

        case 'V':	/* Print version and exit.  */
        
        
          if (update_arg( 0 , 
               0 , &(args_info->version_given),
              &(local_args_info.version_given), optarg, 0, 0, ARG_NO,
              check_ambiguity, override, 0, 0,
              "version", 'V',
              additional_error))
            goto failure;
          cmdline_parser_free (&local_args_info);
          return 0;
        
          break;
        case 'o':	/* Output file.  */
        
        
          if (update_arg( (void *)&(args_info->output_arg), 
               &(args_info->output_orig), &(args_info->output_given),
              &(local_args_info.output_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "output", 'o',
              additional_error))
            goto failure;
        
          break;
        case 'v':	/* Message verbosity.  */
        
        
          if (update_arg( (void *)&(args_info->verbosity_arg), 
               &(args_info->verbosity_orig), &(args_info->verbosity_given),
              &(local_args_info.verbosity_given), optarg, 0, "5", ARG_INT,
              check_ambiguity, override, 0, 0,
              "verbosity", 'v',
              additional_error))
            goto failure;
        
          break;
        case 'd':	/* input directory (must only contain input files).  */
        
        
          if (update_arg( (void *)&(args_info->directory_arg), 
               &(args_info->directory_orig), &(args_info->directory_given),
              &(local_args_info.directory_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "directory", 'd',
              additional_error))
            goto failure;
        
          break;
        case 'm':	/* Map gene index among the network dabs to combine. (Should be used when the gene intex are not identical among network dabs).  */
        
        
          if (update_arg((void *)&(args_info->map_flag), 0, &(args_info->map_given),
              &(local_args_info.map_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "map", 'm',
              additional_error))
            goto failure;
        
          break;
        case 'M':	/* Combination method, (selectmean computes the mea of the upper quartile values).  */
        
        
          if (update_arg( (void *)&(args_info->method_arg), 
               &(args_info->method_orig), &(args_info->method_given),
              &(local_args_info.method_given), optarg, cmdline_parser_method_values, "mean", ARG_STRING,
              check_ambiguity, override, 0, 0,
              "method", 'M',
              additional_error))
            goto failure;
        
          break;
        case 'q':	/* If combine method is Quantile, set the returning quantile (default is median qunatile 0.5).  */
        
        
          if (update_arg( (void *)&(args_info->quantile_arg), 
               &(args_info->quantile_orig), &(args_info->quantile_given),
              &(local_args_info.quantile_given), optarg, 0, "0.5", ARG_FLOAT,
              check_ambiguity, override, 0, 0,
              "quantile", 'q',
              additional_error))
            goto failure;
        
          break;
        case 'w':	/* File with dataset weights, if given each dataset values if weighted by the dataset weight. Skips datasets with no-entry or with zero weights. File format: dataset name<tab>weight.  */
        
        
          if (update_arg( (void *)&(args_info->weight_arg), 
               &(args_info->weight_orig), &(args_info->weight_given),
              &(local_args_info.weight_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "weight", 'w',
              additional_error))
            goto failure;
        
          break;
        case 'z':	/* Convert values to z-scores before combine.  */
        
        
          if (update_arg((void *)&(args_info->zscore_flag), 0, &(args_info->zscore_given),
              &(local_args_info.zscore_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "zscore", 'z',
              additional_error))
            goto failure;
        
          break;
        case 'r':	/* Rank transform data before combine.  */
        
        
          if (update_arg((void *)&(args_info->rank_flag), 0, &(args_info->rank_given),
              &(local_args_info.rank_given), optarg, 0, 0, ARG_FLAG,
              check_ambiguity, override, 1, 0, "rank", 'r',
              additional_error))
            goto failure;
        
          break;
        case 'g':	/* Process only genes from the given set.  */
        
        
          if (update_arg( (void *)&(args_info->genes_arg), 
               &(args_info->genes_orig), &(args_info->genes_given),
              &(local_args_info.genes_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "genes", 'g',
              additional_error))
            goto failure;
        
          break;
        case 'D':	/* Process only edges including a gene from the given set.  */
        
        
          if (update_arg( (void *)&(args_info->genee_arg), 
               &(args_info->genee_orig), &(args_info->genee_given),
              &(local_args_info.genee_given), optarg, 0, 0, ARG_STRING,
              check_ambiguity, override, 0, 0,
              "genee", 'D',
              additional_error))
            goto failure;
        
          break;

        case 0:	/* Long option with no short option */
        case '?':	/* Invalid option.  */
          /* `getopt_long' already printed an error message.  */
          goto failure;

        default:	/* bug: option not considered.  */
          fprintf (stderr, "%s: option unknown: %c%s\n", CMDLINE_PARSER_PACKAGE, c, (additional_error ? additional_error : ""));
          abort ();
        } /* switch */
    } /* while */




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