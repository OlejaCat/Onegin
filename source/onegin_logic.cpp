#include "onegin_logic.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "logger.h"
#include "sorting_algorithms.h"
#include "string_functions.h"

const size_t SIZE_OF_POINT_ARRAY = 4;
const size_t SCALE_FACTOR        = 2;

int clearAllBuffers(Text text)
{
    free(text.text_buffer);
    free(text.line_pointers);

    return 0;
}

int processeBuffer(Text* text)
{
    assert(text != NULL);

    size_t size_of_array = SIZE_OF_POINT_ARRAY;
    LinePointers* pointer_array = (LinePointers*)calloc(size_of_array, sizeof(LinePointers));
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

            if (number_of_line == size_of_array)
            {
                size_of_array *= SCALE_FACTOR;
                pointer_array = (LinePointers*)realloc(pointer_array, size_of_array * sizeof(LinePointers));
            }

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
    bubbleSort(text.line_pointers,
               text.number_of_lines,
               sizeof(LinePointers),
               myStrcmpBackwardPointer);
}


void callBubbleSortForward(Text text)
{
    bubbleSort(text.line_pointers,
               text.number_of_lines,
               sizeof(LinePointers),
               myStrcmpForwardPointer);
}


void callQuickSortBackward(Text text)
{
    quickSort(text.line_pointers,
              text.number_of_lines,
              sizeof(LinePointers),
              myStrcmpBackwardPointer);
}


void callQuickSortForward(Text text)
{
    quickSort(text.line_pointers,
              text.number_of_lines,
              sizeof(LinePointers),
              myStrcmpForwardPointer);
}
