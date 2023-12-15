/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #A1 (MS01)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>
#include "core.h"

// Clear the standard input buffer
void clearInputBuffer(void)
{
    // Discard all remaining char's from the standard input buffer:
    while (getchar() != '\n')
    {
        ; // do nothing!
    }
}

// Wait for user to input the "enter" key to continue
void suspend(void)
{
    printf("<ENTER> to continue...");
    clearInputBuffer();
    putchar('\n');
}
// get integer as input form user
int inputInt(void)
{
    int tempNum; //variable to sore number temporarily
    char newLineCharChar; //variable to store newLineChar character
    while (1)//Loop continues forever ultil somenthig is returned
    {
        scanf("%d%c", &tempNum, &newLineCharChar);//gettting interger input along with newLineChar character
        if (newLineCharChar == '\n')
        {
            return tempNum;//if last characte is newLineChar character(enter key) number gets returned.
        }
        else
        {
            clearInputBuffer();
            printf("Error! Input a whole number: ");
        }
    }
}
// get positive integer as input form user
int inputIntPositive(void)
{
    int tempNum;
    char newLineCharChar;
    while (1)
    {
        scanf("%d%c", &tempNum, &newLineCharChar);
        if (newLineCharChar == '\n')
        {
            if (tempNum > 0)//checks if number entered is positive or not
            {
                return tempNum;
            }
            else
            {

                printf("ERROR! Value must be > 0: ");
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! ");
            printf("Input a whole number: ");
        }
    }
}

//get input that is between min value and max value form user
int inputIntRange(int min, int max)
{
    int tempNum;
    char newLineChar;
    while (1)
    {
        scanf("%d%c", &tempNum, &newLineChar);
        if (newLineChar == '\n')
        {
            if (tempNum >= min && tempNum <= max)//checks if entered number is within the range
            {
                return tempNum;
            }
            else
            {

                printf("ERROR! Value must be between %d and %d inclusive: ",min,max);
            }
        }
        else
        {
            clearInputBuffer();
            printf("Error! ");
            printf("Input a whole number: ");
        }
    }
}

//get character input from user
char inputCharOption(const char *strng)
{
    int i, noOfCharacters = 0;
    char tempCharacter, newLineChar;
    while (strng[noOfCharacters] != '\0')//checking if end of the string is reached or not
    {
        noOfCharacters++; //increasing noOfCharacters until end of the string is reached
    }
    while (1)// loop continues until something is returned
    {
        scanf("%c%c", &tempCharacter, &newLineChar);
        if (newLineChar == '\n')
        {
            for (i = 0; i < noOfCharacters; i++)
            {
                if (strng[i] == tempCharacter)//checking if character lies in the string or not
                {
                    return tempCharacter;
                }
            }
        }
        else{
            clearInputBuffer();
        }
        printf("ERROR: Character must be one of [%s]: ", strng);
    }
}

//get string input from user
void inputCString(char *strng, int min, int max)
{
    char temp[256];//temporary variable to store user entered string(characters)
    int i, noOfCharacters;
    do
    {
        noOfCharacters = 0;
        scanf("%[^\n]%*c", temp);//scans characters until newline character is found
        while (temp[noOfCharacters] != '\0')
        {
            noOfCharacters++;//increases value of noOfCharacters until last character is reached
        }
        if(min==max && max!=noOfCharacters){
            printf("ERROR: String length must be exactly %d chars: ",max);
        }
        else if (noOfCharacters > max){
            printf("ERROR: String length must be no more than %d chars: ",max);
        }
        else if (noOfCharacters < min)//checks the length of string
        {
            printf("ERROR: String length must be between %d and %d chars: ", min, max);
        }
    } while (noOfCharacters < min || noOfCharacters > max);

    for (i = 0; i < noOfCharacters; i++)
    {
        strng[i] = temp[i];
    }
}

// display formated phone
void displayFormattedPhone(const char *phone_number)
{
    int i;
    int allNumbers = 1;//checking if character is number (using ascii value), initially it is supposed that all characters are number, ie. allNumbers=1;
    int noOfCharacters = 0;//variable to store number of characters in string
    if (phone_number != NULL)
    {
        while(phone_number[noOfCharacters]!='\0'){
            if (phone_number[noOfCharacters] <='0' || phone_number[noOfCharacters] >='9')//checking if character is number or not
            {
                allNumbers = 0;//If character is not number allNumbers will be 0, that means string consists non-numeric character
            }
            noOfCharacters++;
        }
    }

    if (noOfCharacters != 10 || allNumbers != 1)
    {
        printf("(___)___-____");//if number of characters is not equal to 10 or if there is any non-numeric character, this line gets executed
    }
    else
    {
        //printing formatted phone number
        i=0;
        printf("(");
        while(i<3){
            printf("%c",phone_number[i]);
            i++;
        }
        printf(")");
        while(i<6){
            printf("%c",phone_number[i]);
            i++;
        }
        printf("-");
        while(i<10){
            printf("%c",phone_number[i]);
            i++;
        }
    }
}