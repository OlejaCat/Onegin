#include "string_functions.h"

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include "onegin_logic.h"
#include "logger.h"


void print_table_of_pointers(Text text_information)
{
    for (size_t i = 0; i < text_information.number_of_lines; i++)
    {
        printf("%s\n", text_information.line_pointers[i].start_of_line);
    }
}


int myStrcmpBackwardPointer(const void* pointer_to_first_string,
                            const void* pointer_to_second_string)
{
    const LinePointers* first_pointer  = (const LinePointers*)pointer_to_first_string;
    const LinePointers* second_pointer = (const LinePointers*)pointer_to_second_string;

    const char* p1 = first_pointer->start_of_line  + first_pointer->length_of_line;
    const char* p2 = second_pointer->start_of_line + second_pointer->length_of_line;

    const char* end_of_p1 = first_pointer->start_of_line;
    const char* end_of_p2 = second_pointer->start_of_line;

    while (p1 != end_of_p1
        && p2 != end_of_p2)
    {
        while (!isalpha(*p1) && p1 != end_of_p1)
        {
            p1--;
        }

        while (!isalpha(*p2) && p2 != end_of_p2)
        {
            p2--;
        }

        if (p1 == end_of_p1 || p2 == end_of_p2)
        {
            break;
        }

        Log(LogLevel_INFO, "p1: %c, p2: %c", *p1, *p2);

        if (tolower(*p1) != tolower(*p2))
        {
            return tolower(*p1) - tolower(*p2);
        }

        p1--;
        p2--;
    }

    if (p1 == end_of_p1 && p2 == end_of_p2)
    {
        return 0;
    }

    return tolower(*p1) - tolower(*p2);
}


int myStrcmpForwardPointer(const void* pointer_to_first_string,
                           const void* pointer_to_second_string)
{
    const LinePointers* first_pointer  = ((const LinePointers*)pointer_to_first_string);
    const LinePointers* second_pointer = ((const LinePointers*)pointer_to_second_string);

    const char* p1 = first_pointer->start_of_line;
    const char* p2 = second_pointer->start_of_line;

    size_t first_shift  = 0;
    size_t second_shift = 0;

    while (p1[first_shift] != '\0'
        && p2[second_shift] != '\0')
    {
        while (!isalpha(p1[first_shift]) && p1[first_shift] != '\0')
        {
            first_shift++;
        }

        while (!isalpha(p2[second_shift]) && p2[second_shift] != '\0')
        {
            second_shift++;
        }

        if (p1[first_shift] == '\0' || p2[second_shift] == '\0')
        {
            break;
        }


        if (tolower(p1[first_shift]) != tolower(p2[second_shift]))
        {
            return tolower(p1[first_shift]) - tolower(p2[second_shift]);
        }

        first_shift++;
        second_shift++;
    }

    if (p1[first_shift] == '\0' && p2[second_shift] == '\0')
    {
        return 0;
    }

    return tolower(p1[first_shift]) - tolower(p2[second_shift]);
}
