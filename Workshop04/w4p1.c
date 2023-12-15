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
    char loopType;
    int num,i=0;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");
    do {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &loopType, &num);
        if (loopType == 'D') {
            if (num >= 3 && num <= 20) {
                i = 0;
                printf("DO-WHILE: ");
                do {
                    printf("D");
                    i++;
                } while (i < num);
                printf("\n\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loopType == 'W') {
            if (num >= 3 && num <= 20) {
                i = 0;
                printf("WHILE   : ");
                while (i < num) {
                    printf("W");
                    i++;
                }
                printf("\n\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            }
        }
        else if (loopType == 'F') {
            if (num >= 3 && num <= 20) {
                printf("FOR     : ");
                for (i = 0; i < num; i++) {
                    printf("F");
                }
                printf("\n\n");
            }
            else {
                printf("ERROR: The number of iterations must be between 3-20 inclusive!");
                printf("\n\n");
            }
        }
        else if (loopType == 'Q') {
            if (!num == 0) {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
            }
        }
        else {
            printf("ERROR: Invalid entered value(s)!\n\n");
        }
        
    } while (!(loopType=='Q'&&num==0));
    printf("\n+--------------------+");
    printf("\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");
    return 0;
}