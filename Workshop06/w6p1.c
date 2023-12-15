/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)

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
    const double maxIncome = 400000.00;
    const double minIncome = 500.00;
    double netIncome, cost[MAX], sum = 0;
    int itemsNumber, i, priority[MAX];
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
            printf("ERROR: You must have a consistent monthly income of at least $500.00\n\n");
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
        scanf("%d", &itemsNumber);
        if (itemsNumber > MAX || itemsNumber < 1)
        {
            printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
        }
    } while (itemsNumber > MAX || itemsNumber < 1);

    for (i = 1; i <= itemsNumber; i++)
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
    printf("\n");
    printf("Item Priority Financed        Cost\n");
    printf("---- -------- -------- -----------\n");
    for (i = 1; i <= itemsNumber; i++)
    {
        printf("%3d  %5d    %5c    %11.2lf\n", i, priority[i], financed[i], cost[i]);
        sum += cost[i];
    }
    printf("---- -------- -------- -----------\n");
    printf("                      $%11.2lf\n\n", sum);
    printf("Best of luck in all your future endeavours!\n");
    return 0;
}