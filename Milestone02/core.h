/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS02)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

// SAFE-GUARD:
// It is good practice to apply safe-guards to header files
// Safe-guard's ensures only 1 copy of the header file is used in the project
// build The macro name should be mirroring the file name with _ for spaces,
// dots, etc.

// !!! DO NOT DELETE THE BELOW 2 LINES !!!
#ifndef CORE_H
#define CORE_H

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
// Copy your work done from Milestone #1 (core.h) into this file
//
// NOTE:
// - Organize your functions into the below categories
// - Make sure the core.c file also lists these functions in the same order!
// - Be sure to provide a BRIEF comment for each function prototype
// - The comment should also be copied to the core.c function definition
//
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//////////////////////////////////////
// USER INTERFACE FUNCTIONS
//////////////////////////////////////

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// get integer as input from user
int inputInt(void);

// get positive integer from user
int inputIntPositive(void);

// get input that is between min value and max value form user
int inputIntRange(int min, int max);

// get character input from user
char inputCharOption(const char *strng);

// get string input from user
void inputCString(char *strng, int min, int max);

// display Phone (formatted)
void displayFormattedPhone(const char *phone_number);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);

// !!! DO NOT DELETE THE BELOW LINE !!!
#endif // !CORE_H
