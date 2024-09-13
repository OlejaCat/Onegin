#ifndef USER_INTERACTION_H
#define USER_INTERACTION_H


typedef enum CalledFlag
{
    CalledFlag_HELP           =  0,
    CalledFlag_VERSION        =  1,
    CalledFlag_NO_FLAG        =  2,
    CalledFlag_FEW_ARGUMENTS  =  3,
    CalledFlag_FORWARD_SORT   =  4,
    CalledFlag_REVERSED_SORT  =  5,
} CalledFlag;

//----------------------------------------
//! Parses terminal arguments
//!
//! @param [in] argc Number of arguments
//! @param [in] argv Arguments
//!
//! @return enum CalledFlag
//----------------------------------------
CalledFlag proccess_flags(const int argc, const char **argv);

//----------------------------------------
//! Print help message
//!
//----------------------------------------
void printHelpMessage(void);

//----------------------------------------
//! Print message if no such file
//!
//----------------------------------------
void printNoSuchFile(void);

//----------------------------------------
//! Print if there are no arguments
//!
//----------------------------------------
void printFewArguments(void);

//----------------------------------------
//! Sorts lines in `left to right` way
//!
//! @param [in] argv Arguments
//!
//----------------------------------------
void forward_sort(const char** argv);

//-----------------------------------------
//! Sprts arguments in `right to left` way
//!
//! @param [in] argv Arguments
//!
//-----------------------------------------
void reverse_sort(const char** argv);

//-----------------------------------------------------
//! Prints that flag input is empty or no sush flag
//!
//! @param [in] input_parameter  flag that was inputed
//! @param [in] solver           solver idk
//!
//-----------------------------------------------------
void emptyInputMessage(const char* input_parameter,
                       const char* solver);

#endif // USER_INTERACTION_H
