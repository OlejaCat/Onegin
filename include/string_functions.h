#ifndef STRING_FUNCTIONS_H
#define STRING_FUNCTIONS_H

#include "onegin_logic.h"

//-----------------------------------------
//! Prints changed text
//!
//! @param [in] text Text
//!
//-----------------------------------------
void print_table_of_pointers(Text text);

//---------------------------------------------------------------------------
//! Compare two strings from left to right (only compare alphabetic letters)
//!
//! @param [in] pointer_to_first_string  Pointer first
//! @param [in] pointer_to_second_string Pointer second
//!
//! @return Difference of strings
//---------------------------------------------------------------------------
int myStrcmpForwardPointer(const void* pointer_to_first_string,
                           const void* pointer_to_second_string);

//---------------------------------------------------------------------------
//! Compare two strings from right to left (only compare alphabetic letters)
//!
//! @param [in] pointer_to_first_string  Pointer first
//! @param [in] pointer_to_second_string Pointer second
//!
//! @return Difference of strings
//---------------------------------------------------------------------------
int myStrcmpBackwardPointer(const void* pointer_to_first_string,
                            const void* pointer_to_second_string);

#endif // STRING_FUNCTIONS_H
