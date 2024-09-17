#include "work_with_files.h"

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "logger.h"
#include "helpful_functions.h"

FileState readDataFromFile(Text*       fill_text_information,
                           const char* input_file_path)
{
    assert(fill_text_information != NULL);
    assert(input_file_path       != NULL);

    FILE* input_file = fopen(input_file_path, "r");
    if (input_file == NULL)
    {
        Log(LogLevel_ERROR, "Error reading file %s", input_file_path);
        return FileState_NO_SUCH_FILE;
    }

    size_t size_of_file = getFileSize(input_file);

    char* text_of_file = (char*)calloc(size_of_file, sizeof(char));
    if (text_of_file == NULL)
    {
        Log(LogLevel_ERROR, "Failed to alloc memory to variable: %s", STRINGIFY(text_of_file));

        FCLOSE_NULL(input_file);

        return FileState_FAILED;
    }

    const size_t return_code = fread(text_of_file,
                                     sizeof(text_of_file[0]),
                                     size_of_file,
                                     input_file);
    if (return_code != size_of_file)
    {
        Log(LogLevel_ERROR, "Error read file: %s", input_file_path);

        FREE_NULL(text_of_file);
        FCLOSE_NULL(input_file);

        return FileState_FAILED;
    }

    FCLOSE_NULL(input_file);

    fill_text_information->text_buffer  = text_of_file;
    fill_text_information->size_of_file = size_of_file;

    processeBuffer(fill_text_information);

    return FileState_WORKING;
}

FileState writeDataToFile(Text        text_information,
                          const char* output_file_path)
{
    assert(output_file_path != NULL);

    FILE* output_file = fopen(output_file_path, "w");
    if (output_file == NULL)
    {
        Log(LogLevel_ERROR, "Error opening file %s", output_file_path);
        return FileState_FAILED;
    }

    for (size_t line = 0; line < text_information.number_of_lines; line++)
    {
        fputs(text_information.line_pointers[line].start_of_line, output_file);
        fputs("\n", output_file);
    }

    return FileState_WORKING;
}


FileState writeOriginalDataToFile(Text        text_information,
                                  const char* output_file_path)
{
    assert(output_file_path  != NULL);

    FILE* output_file = fopen(output_file_path, "w");
    if (output_file == NULL)
    {
        Log(LogLevel_ERROR, "Error opening file %s", output_file_path);
        return FileState_FAILED;
    }

    char* output_data = (char*)calloc(text_information.size_of_file, sizeof(char));
    if (output_data == NULL)
    {
        Log(LogLevel_ERROR, "Failed to calloc memory to variable: %s", STRINGIFY(output_data));
        FCLOSE_NULL(output_file);
        return FileState_FAILED;
    }

    for (size_t element = 0; element < text_information.size_of_file; element++)
    {
        output_data[element] = text_information.text_buffer[element] == '\0'
                                    ? '\n'
                                    : text_information.text_buffer[element];
    }

    size_t writed = fwrite(output_data,
                           sizeof(output_data[0]),
                           text_information.size_of_file,
                           output_file);

    FREE_NULL(output_data);
    FCLOSE_NULL(output_file);

    if (writed != text_information.size_of_file)
    {
        Log(LogLevel_ERROR, "Error writing to output file path: %s", output_file_path);
        return FileState_FAILED;
    }

    return FileState_WORKING;
}
