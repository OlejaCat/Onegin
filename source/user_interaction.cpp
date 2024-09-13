#include "user_interaction.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "work_with_files.h"
#include "string_functions.h"
#include "sorting_algorithms.h"
#include "constants.h"


CalledFlag proccess_flags(const int argc, const char **argv)
{
    if (!strcmp(argv[1], HELP_COMMAND))
    {
        return CalledFlag_HELP;
    }
    else if (!strcmp(argv[1], VERSION_COMMAND))
    {
        return CalledFlag_VERSION;
    }
    else if (!strcmp(argv[1], FORWARD_SORT_COMMAND))
    {
        return (argc == 4) ? CalledFlag_FORWARD_SORT : CalledFlag_FEW_ARGUMENTS;
    }
    else if (!strcmp(argv[1], REVERSED_SORT_COMMAND))
    {
        return (argc == 4) ? CalledFlag_REVERSED_SORT : CalledFlag_FEW_ARGUMENTS;
    }
    else
    {
        return CalledFlag_NO_FLAG;
    }
}

void printFewArguments(void)
{
    puts(FEW_ARGUMENTS);
}

void printHelpMessage(void)
{
    puts(HELP_MESSAGE);
}

void printNoSuchFile(void)
{
    puts(NO_SUCH_FILE_MESSAGE);
}

void forward_sort(const char** argv)
{
    Text text_of_file = {};
    FileState response = readDataFromFile(&text_of_file, argv[2]);
    if (response == FileState_NO_SUCH_FILE)
    {
        printNoSuchFile();
    }
    else
    {
        bubble_sort(text_of_file.line_pointers,
              text_of_file.number_of_lines,
              sizeof(LinePointers),
              myStrcmpForward);

        writeDataToFile(text_of_file, argv[3]);
    }
}

void reverse_sort(const char** argv)
{
    Text text_of_file = {};
    FileState response = readDataFromFile(&text_of_file, argv[2]);
    if (response == FileState_NO_SUCH_FILE)
    {
        printNoSuchFile();
    }
    else
    {
        bubble_sort(text_of_file.line_pointers,
              text_of_file.number_of_lines,
              sizeof(LinePointers),
              myStrcmpBackward);

        writeDataToFile(text_of_file, argv[3]);
    }
}


void emptyInputMessage(const char* input_parameter,
                       const char* solver)
{
    printf("Unknown parameter: '%s'. Type %s %s for help.\n",
           input_parameter,
           solver,
           HELP_COMMAND);
}
