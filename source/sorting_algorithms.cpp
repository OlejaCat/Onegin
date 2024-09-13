#include "sorting_algorithms.h"

#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#include "helpful_functions.h"


int bubble_sort(void*              data,
                size_t             size,
                size_t             size_of_element,
                compare_function_t compare_function)
{
    uint8_t* data_ = (uint8_t*)data;

    bool swapped = false;
    for (size_t i = 0; i < size; i++)
    {
        swapped = false;
        for (size_t j = 0; j < size - i - 1; j++)
        {
            if (compare_function(data_ + j * size_of_element, data_ + (j + 1) * size_of_element) > 0)
            {
                swap(data_ + j * size_of_element,
                     data_ + (j + 1) * size_of_element,
                     size_of_element);
                swapped = true;
            }
        }

        if (swapped == false)
        {
            break;
        }
    }

    return 0;
}
