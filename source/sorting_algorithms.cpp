#include "sorting_algorithms.h"

#include <stdbool.h>
#include <assert.h>
#include <stdint.h>

#include "helpful_functions.h"
#include "logger.h"


// static --------------------------------------------------------------------------------------------------------------

//----------------------------------------------------------------
//! Quick sort partition
//!
//! @param [out] data             Data that we will sort
//! @param [in]  size             `Length` of data
//! @param [in]  size_of_element  Size of element of the array
//! @param [in]  compare_function Compare function
//!
//! @return Number of the partition
//----------------------------------------------------------------
static size_t quickSortPartition(uint8_t*           data,
                                 size_t             size,
                                 size_t             size_of_element,
                                 compare_function_t compare_function)
{
    assertStrict(data != NULL);
    assertStrict(size > 1);

    int size_of_element_ = (int)size_of_element;
    int size_            = (int)size;

    uint8_t* pivot = data + (rand() % size_) * size_of_element_;
    uint8_t* end   = data + (size_ - 1) * size_of_element_;

    if (end != pivot)
    {
        swap(pivot, end, size_of_element);
        pivot = end;
    }

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

// public --------------------------------------------------------------------------------------------------------------

void quickSort(void*              data,
               size_t             size,
               size_t             size_of_element,
               compare_function_t compare_function)
{
    assertStrict(data != NULL);

    uint8_t* data_ = (uint8_t*)data;

    if (size > 1)
    {
        size_t partion = quickSortPartition(data_,
                                            size,
                                            size_of_element,
                                            compare_function);

        quickSort(data_,
                   partion,
                   size_of_element,
                   compare_function);

        quickSort(data_ + (partion + 1) * size_of_element,
                   size - partion - 1,
                   size_of_element,
                   compare_function);
    }
}


void bubbleSort(void*              data,
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
