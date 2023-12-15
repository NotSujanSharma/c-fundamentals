/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)

                          DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10
int main(void)
{
    double netIncome, cost[MAX], overallCost = 0, totalCost, month;
    int choice, i, priority[MAX], selection, flag = 0, priorityFilter;
    const double maxIncome = 400000.00;
    const double minIncome = 500.00;
    int remainingMonths, year;
    char financed[MAX];
    printf("+--------------------------+\n");
    printf("+   Wish List Forecaster   |\n");
    printf("+--------------------------+\n\n");
    do
    {
        printf("Enter your monthly NET income: $");
        scanf("%lf", &netIncome);
        if (netIncome < minIncome)
        {
            printf("ERROR: You must have a consistent monthly income of at least $500.00");
            printf("\n\n");
        }
        if (netIncome > maxIncome)
        {
            printf("ERROR: Liar! I'll believe you if you enter a value no more than $400000.00\n\n");
        }
    } while (netIncome > maxIncome || netIncome < minIncome);
    printf("\n");
    do
    {
        printf("How many wish list items do you want to forecast?: ");
        scanf("%d", &choice);
        if (choice > MAX || choice < 1)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (choice > MAX || choice < 1);
    for (i = 1; i <= choice; i++)
    {
        printf("\nItem-%d Details:\n", i);
        do
        {
            printf("   Item cost: $");
            scanf("%lf", &cost[i]);
            if (cost[i] < 100)
            {
                printf("      ERROR: Cost must be at least $100.00\n");
            }
        } while (cost[i] < 100);

        do
        {
            printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
            scanf("%d", &priority[i]);
            if (priority[i] < 1 || priority[i] > 3)
            {
                printf("      ERROR: Value must be between 1 and 3\n");
            }
        } while (priority[i] < 1 || priority[i] > 3);
        do
        {
            printf("   Does this item have financing options? [y/n]: ");
            scanf(" %c", &financed[i]);
            if (!(financed[i] == 'y' || financed[i] == 'n'))
            {
                printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
            }
        } while (!(financed[i] == 'y' || financed[i] == 'n'));
    }
    printf("\nItem Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 1; i <= choice; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i, priority[i], financed[i], cost[i]);

        overallCost += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n", overallCost);
    do
    {
        totalCost = 0;
        flag = 0;
        printf("\nHow do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf("%d", &selection);
        if (selection < 0 || selection > 2)
        {
            printf("\nERROR: Invalid menu selection.\n");
        }

        if (selection == 1)
        {
            totalCost = overallCost;
            printf("\n====================================================\n");

            printf("Filter:   All items\n");
            printf("Amount:   $%.2lf\n", totalCost);
            month = (totalCost / netIncome) + 1;
            year = month / 12;
            remainingMonths = (int)month % 12;
            printf("Forecast: %d years, %d months\n", year, remainingMonths);
            for (i = 0; i < choice; i++)
            {
                if (financed[i + 1] == 'y')
                {
                    flag = 1;
                }
            }
            if (flag != 0)
            {

                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
        else if (selection == 2)
        {
            printf("\nWhat priority do you want to filter by? [1-3]: ");
            scanf("%d", &priorityFilter);

            for (i = 0; i < choice; i++)
            {
                if (priority[i + 1] == priorityFilter)
                {
                    totalCost += cost[i + 1];
                    if (financed[i + 1] == 'y')
                    {
                        flag = 1;
                    }
                }
            }
            printf("\n====================================================\n");

            printf("Filter:   by priority (%d)", priorityFilter);
            printf("\nAmount:   $%.2lf\n", totalCost);
            month = (totalCost / netIncome) + 1;
            year = month / 12;
            remainingMonths = (int)month % 12;
            printf("Forecast: %d years, %d months\n", year, remainingMonths);
            if (flag != 0)
            {

                printf("NOTE: Financing options are available on some items.\n");
                printf("      You can likely reduce the estimated months.\n");
            }
            printf("====================================================\n");
        }
    } while (selection != 0);
    printf("\nBest of luck in all your future endeavours!\n");
    return 0;
}