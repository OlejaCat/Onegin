#ifndef WORK_WITH_FILES_H
#define WORK_WITH_FILES_H

#include "onegin_logic.h"

typedef enum FileState
{
    FileState_WORKING      = 0,
    FileState_FAILED       = 1,
    FileState_NO_SUCH_FILE = 2,
} FileState;

//----------------------------------------------------------------------------------
//! Reads data from file and convert it to array of pointers
//!
//! @param[out] fill_text_information Pointer to struct with information about text
//! @param[in]  input_file_path       File
//!
//----------------------------------------------------------------------------------
FileState readDataFromFile(Text*       fill_text_information,
                           const char* input_file_path);

//----------------------------------------------------------------------------------
//! Writes data from buffer to file
//!
//! @param[out] text_information Text sttucture
//! @param[in]  output_file_path Output file
//!
//----------------------------------------------------------------------------------
FileState writeOriginalDataToFile(Text        text_information,
                                  const char* output_file_path);

//----------------------------------------------------------------------------------
//! Writes changed data to file
//!
//! @param[out] text_information Text sttucture
//! @param[in]  output_file_path Output file
//!
//----------------------------------------------------------------------------------
FileState writeDataToFile(Text        text_information,
                          const char* output_file_path);

#endif // WORK_WITH_FILES_H
