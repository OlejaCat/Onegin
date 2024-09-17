#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdlib.h>
#include <stdint.h>

typedef int (*compare_function_t) (const void* a, const void* b);

//-------------------------------------------------------------
//! Sorts using bubble sort
//!
//! @param [out] data             Data that we will sort
//! @param [in]  size             `Length` of data
//! @param [in]  size_of_element  Size of element of the array
//! @param [in]  compare_function Compare function
//!
//-------------------------------------------------------------
void bubbleSort(void*              data,
                size_t             size,
                size_t             size_of_element,
                compare_function_t compare_function);

//----------------------------------------------------
//! Quick sort
//!
//! @param [out] data             Data that we will sort
//! @param [in]  size             `Length` of data
//! @param [in]  size_of_element  Size of element of the array
//! @param [in]  compare_function Compare function
//!
//-------------------------------------------------------------
void quickSort(void*              data,
               size_t             size,
               size_t             size_of_element,
               compare_function_t compare_function);

#endif // SORTING_ALGORITHMS_H
