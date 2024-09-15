#include "sorting_algorithms.h"

#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#include "helpful_functions.h"
#include "logger.h"


size_t quick_sort_partition(uint8_t*           data,
                            size_t             size,
                            size_t             size_of_element,
                            compare_function_t compare_function)
{
    assertStrict(data != NULL);
    assertStrict(size > 1);

    int size_of_element_ = (int)size_of_element;
    int size_            = (int)size;

    uint8_t* pivot = data + (size_ - 1) * size_of_element_;

    Log(LogLevel_INFO, "pivot: %d", *pivot);
    int i = -1;

    for (int j = 0; j < size_ - 1; j++)
    {
        if (compare_function(pivot, data + j * size_of_element_) > 0)
        {
            i++;
            swap(data + i * size_of_element_,
                 data + j * size_of_element_,
                 size_of_element);
        }
    }

    swap(data + (i + 1) * size_of_element_,
         data + (size_ - 1) * size_of_element_,
         size_of_element);

    Log(LogLevel_INFO, "partition is: %d", i + 1);
    return (size_t)i + 1;
}



void quick_sort(void*              data,
                size_t             size,
                size_t             size_of_element,
                compare_function_t compare_function)
{
    uint8_t* data_ = (uint8_t*)data;

    if (size > 1)
    {
        size_t partion = quick_sort_partition(data_,
                                              size,
                                              size_of_element,
                                              compare_function);

        quick_sort(data_,
                   partion,
                   size_of_element,
                   compare_function);

        quick_sort(data_ + (partion + 1) * size_of_element,
                   size - partion - 1,
                   size_of_element,
                   compare_function);
    }
}


void bubble_sort(void*              data,
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
}
