#ifndef CONSTANTS_H
#define CONSTANTS_H

static const char* HELP_COMMAND          = "--help";
static const char* FORWARD_SORT_COMMAND  = "--forward-sort";
static const char* REVERSED_SORT_COMMAND = "--reverse-sort";
static const char* VERSION_COMMAND       = "--version";


static const char* NO_SUCH_FILE_MESSAGE = "No such file";
static const char* FEW_ARGUMENTS        = "Too few arguments";
static const char* HELP_MESSAGE         =
    "Arguments:\n"
    "    --help\t\t\t\t\tdisplays words of suppor\n"
    "    --forward_sort [input file] [output file]\tsorts lines of file\n"
    "    --reverse-sort [input file] [output file]\tsorts lines from `right to left`"
;

#endif // CONSTANTS_H
