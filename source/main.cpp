#include "logger.h"
#include "assert.h"
#include "user_interaction.h"


int main(const int argc, const char** argv)
{
    openLogFile("logger.txt");
    Log(LogLevel_DEBUG, "Start");

    if (argc <= 1)
    {
        printHelpMessage();
        return 0;
    }

    CalledFlag flag = proccess_flags(argc, argv);

    switch(flag)
    {
        case CalledFlag_HELP:
            printHelpMessage();
            break;

        case CalledFlag_NO_FLAG:
            emptyInputMessage(argv[1], argv[0]);
            break;

        case CalledFlag_FORWARD_SORT:
            forward_sort(argv);
            break;

        case CalledFlag_REVERSED_SORT:
            reverse_sort(argv);
            break;

        case CalledFlag_FEW_ARGUMENTS:
            printFewArguments();
            break;

        default:
            assert(0 && "Something went wrong");
            break;
    }

    return 0;
}
