#ifndef ONEGIN_LOGIC_H
#define ONEGIN_LOGIC_H

#include <stdio.h>

// structures

typedef struct LinePointers
{
    char*  start_of_line;
    size_t length_of_line;
} LinePointers;

typedef struct Text
{
    char*         text_buffer;
    size_t        size_of_file;
    LinePointers* line_pointers;
    size_t        number_of_lines;
} Text;

//----------------------------------------
//! Gets text and turn it into structure
//!
//! @param [out] text Structure
//!
//! @return state
//-----------------------------------------
int processeBuffer(Text* text);

#endif // ONEGIN_LOGIC_H
