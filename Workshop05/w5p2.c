/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)

                          DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define LOG_DAYS 3
#define _CRT_SECURE_NO_WARNINGS
#define MIN_YEAR 2012
#define MAX_YEAR 2022
#include <stdio.h>

int main(void)
{
    int JAN = 1, DEC = 12;
    int YEAR, MONTH, i;
    double morningRating, eveningRating, totalMorningRating = 0, totalEveningRating = 0, totalRating, averageMorningRating, averageEveningRating;
    double average;
    printf("General Well-being Log\n");
    printf("======================\n");
    do
    {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf("%d %d", &YEAR, &MONTH);
        if (YEAR < MIN_YEAR || YEAR > MAX_YEAR)
        {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }
        if (MONTH < JAN || MONTH > DEC)
        {
            printf("   ERROR: Jan.(%d) - Dec.(%d)\n", JAN, DEC);
        }
    } while (!((YEAR >= MIN_YEAR && YEAR <= MAX_YEAR) && (MONTH >= JAN && MONTH <= DEC)));
    printf("\n*** Log date set! ***");
    printf("\n");
    for (i = 1; i <= LOG_DAYS; i++)
    {
        printf("\n%d-", YEAR);
        switch (MONTH)
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
        printf("-%02d", i);
        printf("\n");
        do
        {
            printf("   Morning rating (0.0-5.0): ");
            scanf("%lf", &morningRating);
            if (morningRating < 0.0 || morningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (morningRating < 0.0 || morningRating > 5.0);
        totalMorningRating = totalMorningRating + morningRating;
        do
        {
            printf("   Evening rating (0.0-5.0): ");
            scanf("%lf", &eveningRating);
            if (eveningRating < 0.0 || eveningRating > 5.0)
            {
                printf("      ERROR: Rating must be between 0.0 and 5.0 inclusive!\n");
            }
        } while (eveningRating < 0.0 || eveningRating > 5.0);
        totalEveningRating = totalEveningRating + eveningRating;
    }
    totalRating = totalMorningRating + totalEveningRating;
    printf("\nSummary\n");
    printf("=======\n");
    printf("Morning total rating: %.3lf\n", totalMorningRating);
    printf("Evening total rating:  %.3lf\n", totalEveningRating);
    printf("----------------------------\n");
    printf("Overall total rating: %.3lf\n", totalRating);
    averageMorningRating = (totalMorningRating / LOG_DAYS);
    averageEveningRating = (totalEveningRating / LOG_DAYS);
    average = (averageMorningRating + averageEveningRating) / 2;
    printf("\nAverage morning rating:  %.1lf", averageMorningRating);
    printf("\nAverage evening rating:  %.1lf", averageEveningRating);
    printf("\n----------------------------");
    printf("\nAverage overall rating:  %.1lf\n", average);
    return 0;
}