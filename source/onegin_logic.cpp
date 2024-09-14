#include "onegin_logic.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "logger.h"
#include "sorting_algorithms.h"
#include "string_functions.h"

const size_t SIZE_OF_POINT_ARRAY = 512;

int processeBuffer(Text* text)
{
    assert(text != NULL);

    LinePointers* pointer_array = (LinePointers*)calloc(SIZE_OF_POINT_ARRAY, sizeof(LinePointers));
    size_t number_of_line = 0;

    LinePointers temp_pointer = {};

    size_t number_of_element = 0;

    bool start_of_line_flag = true;
    while (number_of_element < text->size_of_file)
    {
        if (start_of_line_flag)
        {
            temp_pointer.start_of_line = text->text_buffer + number_of_element;
            start_of_line_flag = false;
        }

        if (text->text_buffer[number_of_element] == '\n')
        {
            text->text_buffer[number_of_element] = '\0';

            temp_pointer.length_of_line = (size_t)(text->text_buffer + number_of_element - temp_pointer.start_of_line);
            pointer_array[number_of_line] = temp_pointer;

            Log(LogLevel_INFO, "Length of line %lu", temp_pointer.length_of_line);

            number_of_line++;

            start_of_line_flag = true;
        }

        number_of_element++;
    }

    Log(LogLevel_INFO, "%lu", number_of_line);

    text->line_pointers   = pointer_array;
    text->number_of_lines = number_of_line;

    return EXIT_SUCCESS;
}


void callBubbleSortBackward(Text text)
{
    bubble_sort(text.line_pointers,
                text.number_of_lines,
                sizeof(LinePointers),
                myStrcmpBackwardPointer);
}


void callBubbleSortForward(Text text)
{
    bubble_sort(text.line_pointers,
                text.number_of_lines,
                sizeof(LinePointers),
                myStrcmpForwardPointer);
}
