/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS01)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

// get integer as input from user
int inputInt(void);

// get positive integer from user
int inputIntPositive(void);

//get input that is between min value and max value form user
int inputIntRange(int min, int max);

//get character input from user
int inputCharOption(const char *strng);

//get string input from user
void inputCString(char *strng, int min, int max);

//display Phone (formatted)
void displayFormattedPhone(const char *phone_number);

// Clear the standard input buffer
void clearInputBuffer(void);

// Wait for user to input the "enter" key to continue
void suspend(void);
