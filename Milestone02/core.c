/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS02)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include "core.h"
#include <stdio.h>
#include <string.h>

//
// Copy your work done from Milestone #1 (core.c) into this file
// - Organize your functions in the same order as they are listed in the core.h
// file
// - Also copy the commented "sections" to help with finding functions quickly!
//

// Clear the standard input buffer
void clearInputBuffer(void) {
  // Discard all remaining char's from the standard input buffer:
  while (getchar() != '\n') {
    ; // do nothing!
  }
}

// Wait for user to input the "enter" key to continue
void suspend(void) {
  printf("<ENTER> to continue...");
  clearInputBuffer();
  putchar('\n');
}
// get integer as input form user
int inputInt(void) {
  int tempNum;          // variable to sore number temporarily
  char newLineCharChar; // variable to store newLineChar character
  do {
    scanf("%d%c", &tempNum, &newLineCharChar); // gettting interger input along
                                               // with newLineChar character
    if (newLineCharChar != '\n')
      clearInputBuffer();
    printf("Error! Input a whole number: ");
  } while (newLineCharChar != '\n');
  return tempNum;
}
// get positive integer as input form user
int inputIntPositive(void) {
  int tempNum;
  char newLineCharChar;
  int flag = 0;
  do {
    scanf("%d%c", &tempNum, &newLineCharChar);
    if (newLineCharChar == '\n') {
      if (tempNum > 0) // checks if number entered is positive or not
      {
        flag = 1;
      } else {

        printf("ERROR! Value must be > 0: ");
      }
    } else {
      clearInputBuffer();
      printf("Error! ");
      printf("Input a whole number: ");
    }
  } while (flag == 0);
  return tempNum;
}

// get input that is between min value and max value form user
int inputIntRange(int min, int max) {
  int tempNum;
  char newLineChar;
  int flag = 0;
  do {
    scanf("%d%c", &tempNum, &newLineChar);
    if (newLineChar == '\n') {
      if (tempNum >= min &&
          tempNum <= max) // checks if entered number is within the range
      {
        flag = 1;
      } else {

        printf("ERROR! Value must be between %d and %d inclusive: ", min, max);
      }
    } else {
      clearInputBuffer();
      printf("Error! ");
      printf("Input a whole number: ");
    }
  } while (flag == 0);
  return tempNum;
}

// get character input from user
char inputCharOption(const char *strng) {
  char tempCharacter, newLineChar, *occurance;
  while (1) // loop continues until something is returned
  {
    scanf("%c%c", &tempCharacter, &newLineChar);

    if (newLineChar == '\n') {
      occurance = strchr(strng, tempCharacter);
      if (occurance != NULL) {
        return tempCharacter;
      }
    } else {
      clearInputBuffer();
    }
    printf("ERROR: Character must be one of [%s]: ", strng);
  }
}

// get string input from user
void inputCString(char *strng, int min, int max) {
  char temp[256]; // temporary variable to store user entered string(characters)
  int noOfCharacters;
  do {

    scanf("%[^\n]%*c",
          temp); // scans characters until newline character is found
    noOfCharacters = strlen(temp);
    if (min == max && max != noOfCharacters) {
      printf("ERROR: String length must be exactly %d chars: ", max);
    } else if (noOfCharacters > max) {
      printf("ERROR: String length must be no more than %d chars: ", max);
    } else if (noOfCharacters < min) // checks the length of string
    {
      printf("ERROR: String length must be between %d and %d chars: ", min,
             max);
    }
  } while (noOfCharacters < min || noOfCharacters > max);
  strcpy(strng, temp); // copies the string entered by user to the variable
}

// display formated phone
void displayFormattedPhone(const char *phone_number) {
  int i;
  int allNumbers =
      1; // checking if character is number (using ascii value), initially it is
         // supposed that all characters are number, ie. allNumbers=1;
  int noOfCharacters; // variable to store number of characters in string
  if (phone_number != NULL) {
    noOfCharacters = strlen(phone_number);

    for (i = 0; i < noOfCharacters; i++) {
      if (phone_number[i] < '0' ||
          phone_number[i] > '9') // checking if character is number or not
      {
        allNumbers = 0; // If character is not number allNumbers will be 0, that
                        // means string consists non-numeric character
      }
    }
  }

  if (noOfCharacters != 10 || allNumbers != 1) {
    printf("(___)___-____"); // if number of characters is not equal to 10 or if
                             // there is any non-numeric character, this line
                             // gets executed
  } else {
    // printing formatted phone number
    i = 0;
    printf("(");
    while (i < 3) {
      printf("%c", phone_number[i]);
      i++;
    }
    printf(")");
    while (i < 6) {
      printf("%c", phone_number[i]);
      i++;
    }
    printf("-");
    while (i < 10) {
      printf("%c", phone_number[i]);
      i++;
    }
  }
}