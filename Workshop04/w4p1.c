/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P1)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    char loop;
    int number, a = 0;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+");
    printf("\n\n");
    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the numberber of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loop, &number);
        if (loop == 'D') {
            if (number >= 3 && number <= 20) {
                a = 0;
                printf("DO-WHILE: ");
                do {
                    printf("D");
                    a=a+1;
                } while (a < number);
                printf("\n\n");
            }
            else {
                printf("ERROR: The numberber of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loop == 'W') {
            if (number >= 3 && number <= 20) {
                a = 0;
                printf("WHILE   : ");
                while (a < number) {
                    printf("W");
                    a=a+1;
                }
                printf("\n\n");
            }
            else {
                printf("ERROR: The numberber of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loop == 'F') {
            if (number >= 3 && number <= 20) {
                printf("FOR     : ");
                for (a = 0; a < number; a++) {
                    printf("F");
                }
                printf("\n\n");
            }
            else {
                printf("ERROR: The numberber of iterations must be between 3-20 inclusive!");
                printf("\n\n");
            }
        }
        else if (loop == 'Q') {
            if (!number == 0) {
                printf("ERROR: To quit, the numberber of iterations should be 0!\n\n");
            }
            else {
                printf("\n+--------------------+");
                printf("\n");
                printf("Loop application ENDED\n");
                printf("+--------------------+\n");
            }
        }
        else {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }

    } while (!(loop == 'Q' && number == 0));
    return 0;
}
