/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)

                          DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#include <stdio.h>

int main(void)
{
    int JAN = 1, DEC = 12;
    int year, month;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &year, &month);
        if (year < MIN_YEAR || year > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (month < JAN || month > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
    } while (!((year >= MIN_YEAR && year <= MAX_YEAR) && (month >= JAN && month <= DEC)));
    printf("\n*** Log date set! ***\n");
    printf("\nLog starting date: ");
    printf("%d-", year);
    switch (month)
    {
    case 1:
        printf("JAN");
        break;
    case 2:
        printf("FEB");
        break;
    case 3:
        printf("MAR");
        break;
    case 4:
        printf("APR");
        break;
    case 5:
        printf("MAY");
        break;
    case 6:
        printf("JUN");
        break;
    case 7:
        printf("JUL");
        break;
    case 8:
        printf("AUG");
        break;
    case 9:
        printf("SEP");
        break;
    case 10:
        printf("OCT");
        break;
    case 11:
        printf("NOV");
        break;
    case 12:
        printf("DEC");
        break;
    default:
        break;
    }
    printf("-%02d\n", 1);
    return 0;
}