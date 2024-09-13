#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <stdlib.h>

typedef int (*compare_function_t) (const void* a, const void* b);

//--------------------------
//! Sorts using bubble sort
//--------------------------
int bubble_sort(void*              data,
                size_t             size,
                size_t             size_of_element,
                compare_function_t compare_function);

#endif // SORTING_ALGORITHMS_H
