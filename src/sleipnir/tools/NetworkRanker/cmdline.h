/** @file cmdline.h
 *  @brief The header file for the command line option parser
 *  generated by GNU Gengetopt version 2.22
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
/** @brief the program name */
#define CMDLINE_PARSER_PACKAGE "NetworkRanker"
#endif

#ifndef CMDLINE_PARSER_VERSION
/** @brief the program version */
#define CMDLINE_PARSER_VERSION "1.0"
#endif

/** @brief Where the command line options are stored */
struct gengetopt_args_info
{
  const char *help_help; /**< @brief Print help and exit help description.  */
  const char *version_help; /**< @brief Print version and exit help description.  */
  char * output_arg;	/**< @brief Output file.  */
  char * output_orig;	/**< @brief Output file original value given at command line.  */
  const char *output_help; /**< @brief Output file help description.  */
  int verbosity_arg;	/**< @brief Message verbosity (default='5').  */
  char * verbosity_orig;	/**< @brief Message verbosity original value given at command line.  */
  const char *verbosity_help; /**< @brief Message verbosity help description.  */
  char * directory_arg;	/**< @brief input directory (must only contain input files).  */
  char * directory_orig;	/**< @brief input directory (must only contain input files) original value given at command line.  */
  const char *directory_help; /**< @brief input directory (must only contain input files) help description.  */
  char * annot_arg;	/**< @brief matrix of gene to network annotations.  */
  char * annot_orig;	/**< @brief matrix of gene to network annotations original value given at command line.  */
  const char *annot_help; /**< @brief matrix of gene to network annotations help description.  */
  char * genesets_arg;	/**< @brief PCL file of genesets.  */
  char * genesets_orig;	/**< @brief PCL file of genesets original value given at command line.  */
  const char *genesets_help; /**< @brief PCL file of genesets help description.  */
  int gene_flag;	/**< @brief Calculate gene by geneset scores (default=off).  */
  const char *gene_help; /**< @brief Calculate gene by geneset scores help description.  */
  int geneset_idx_arg;	/**< @brief Index of geneset when outputting by genes (default='0').  */
  char * geneset_idx_orig;	/**< @brief Index of geneset when outputting by genes original value given at command line.  */
  const char *geneset_idx_help; /**< @brief Index of geneset when outputting by genes help description.  */
  char * barcode_arg;	/**< @brief PCL file of gene expression (barcode) values.  */
  char * barcode_orig;	/**< @brief PCL file of gene expression (barcode) values original value given at command line.  */
  const char *barcode_help; /**< @brief PCL file of gene expression (barcode) values help description.  */
  float exp_cut_arg;	/**< @brief Cutoff for gene expression (default='.5').  */
  char * exp_cut_orig;	/**< @brief Cutoff for gene expression original value given at command line.  */
  const char *exp_cut_help; /**< @brief Cutoff for gene expression help description.  */
  float no_exp_arg;	/**< @brief Default value for non-expressed gene (default='0').  */
  char * no_exp_orig;	/**< @brief Default value for non-expressed gene original value given at command line.  */
  const char *no_exp_help; /**< @brief Default value for non-expressed gene help description.  */
  int backg_flag;	/**< @brief Divide by background network compendium score (default=on).  */
  const char *backg_help; /**< @brief Divide by background network compendium score help description.  */
  char * refnet_arg;	/**< @brief Use reference network for background correction.  */
  char * refnet_orig;	/**< @brief Use reference network for background correction original value given at command line.  */
  const char *refnet_help; /**< @brief Use reference network for background correction help description.  */
  int enorm_flag;	/**< @brief Correct by the degrees of both genes incident to an edge (default=off).  */
  const char *enorm_help; /**< @brief Correct by the degrees of both genes incident to an edge help description.  */
  int gnorm_flag;	/**< @brief Correct by the degree of gene of interest (default=off).  */
  const char *gnorm_help; /**< @brief Correct by the degree of gene of interest help description.  */
  int nnorm_flag;	/**< @brief Correct by the degree of neighbor gene (default=off).  */
  const char *nnorm_help; /**< @brief Correct by the degree of neighbor gene help description.  */
  int pval_flag;	/**< @brief Correct by p-value (default=off).  */
  const char *pval_help; /**< @brief Correct by p-value help description.  */
  int zscore_flag;	/**< @brief Correct by z-score (default=off).  */
  const char *zscore_help; /**< @brief Correct by z-score help description.  */
  int log_weight_flag;	/**< @brief Weight by log of ratio (default=off).  */
  const char *log_weight_help; /**< @brief Weight by log of ratio help description.  */
  int weight_flag;	/**< @brief Weight edges by chosen metric (default=off).  */
  const char *weight_help; /**< @brief Weight edges by chosen metric help description.  */
  
  unsigned int help_given ;	/**< @brief Whether help was given.  */
  unsigned int version_given ;	/**< @brief Whether version was given.  */
  unsigned int output_given ;	/**< @brief Whether output was given.  */
  unsigned int verbosity_given ;	/**< @brief Whether verbosity was given.  */
  unsigned int directory_given ;	/**< @brief Whether directory was given.  */
  unsigned int annot_given ;	/**< @brief Whether annot was given.  */
  unsigned int genesets_given ;	/**< @brief Whether genesets was given.  */
  unsigned int gene_given ;	/**< @brief Whether gene was given.  */
  unsigned int geneset_idx_given ;	/**< @brief Whether geneset_idx was given.  */
  unsigned int barcode_given ;	/**< @brief Whether barcode was given.  */
  unsigned int exp_cut_given ;	/**< @brief Whether exp_cut was given.  */
  unsigned int no_exp_given ;	/**< @brief Whether no_exp was given.  */
  unsigned int backg_given ;	/**< @brief Whether backg was given.  */
  unsigned int refnet_given ;	/**< @brief Whether refnet was given.  */
  unsigned int enorm_given ;	/**< @brief Whether enorm was given.  */
  unsigned int gnorm_given ;	/**< @brief Whether gnorm was given.  */
  unsigned int nnorm_given ;	/**< @brief Whether nnorm was given.  */
  unsigned int pval_given ;	/**< @brief Whether pval was given.  */
  unsigned int zscore_given ;	/**< @brief Whether zscore was given.  */
  unsigned int log_weight_given ;	/**< @brief Whether log_weight was given.  */
  unsigned int weight_given ;	/**< @brief Whether weight was given.  */

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
int cmdline_parser_configfile (char * const filename,
  struct gengetopt_args_info *args_info,
  int override, int initialize, int check_required);

/**
 * The config file parser
 * @param filename the name of the config file
 * @param args_info the structure where option information will be stored
 * @param params additional parameters for the parser
 * @return 0 if everything went fine, NON 0 if an error took place
 */
int cmdline_parser_config_file (char * const filename,
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