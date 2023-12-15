/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #3 (P2)

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
    const double GRAMS_IN_LBS = 453.5924;

    char coffeeType1, coffeeType2, coffeeType3;
    char cream1, cream2, cream3;
    char coffeeStrength, likeCream;
    int coffeeWeight1, coffeeWeight2, coffeeWeight3;
    int totalServings;
    
    printf("Take a Break - Coffee Shop");
    printf("\n==========================");
    printf("\n\nEnter the coffee product information being sold today...");
    printf("\n\nCOFFEE-1...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType1);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight1);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream1);
    printf("\nCOFFEE-2...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType2);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight2);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream2);
    printf("\nCOFFEE-3...");
    printf("\nType ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffeeType3);
    printf("Bag weight (g): ");
    scanf("%d", &coffeeWeight3);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &cream3);
    printf("\n");
    printf("---+------------------------+---------------+-------+");
    printf("\n   |    Coffee              |   Packaged    | Best  |");
    printf("\n   |     Type               |  Bag Weight   | Served|");
    printf("\n   +------------------------+---------------+ With  |");
    printf("\nID | Light | Medium | Rich  |  (G) | Lbs    | Cream |");
    printf("\n---+------------------------+---------------+-------|");
    printf("\n 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |",
        (coffeeType1 == 'L' || coffeeType1 == 'l'),
        (coffeeType1 == 'M' || coffeeType1 == 'm'),
        (coffeeType1 == 'R' || coffeeType1 == 'r'),
        (coffeeWeight1),
        (coffeeWeight1 / GRAMS_IN_LBS),
        (cream1 == 'Y' || cream1 == 'y'));
    printf("\n 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |",
        (coffeeType2 == 'L' || coffeeType2 == 'l'),
        (coffeeType2 == 'M' || coffeeType2 == 'm'),
        (coffeeType2 == 'R' || coffeeType2 == 'r'),
        (coffeeWeight2),
        (coffeeWeight2 / GRAMS_IN_LBS),
        (cream1 == 'Y' || cream2 == 'y'));
    printf("\n 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |",
        (coffeeType3 == 'L' || coffeeType3 == 'l'),
        (coffeeType3 == 'M' || coffeeType3 == 'm'),
        (coffeeType3 == 'R' || coffeeType3 == 'r'),
        (coffeeWeight3),
        (coffeeWeight3 / GRAMS_IN_LBS),
        (cream1 == 'Y' || cream3 == 'y'));

    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &likeCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &totalServings);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType1 == 'L' || coffeeType1 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType1 == 'M' || coffeeType1 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType1 == 'R' || coffeeType1 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight1 >= 250 && coffeeWeight1 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight1 >= 500 && coffeeWeight1 < 1000)) || ((totalServings >= 10) && (coffeeWeight1 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream1 == 'Y' || cream1 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream1 == 'n' || cream1 == 'N')));
    printf("\n 2|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType2 == 'L' || coffeeType2 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType2 == 'M' || coffeeType2 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType2 == 'R' || coffeeType2 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight2 >= 250 && coffeeWeight2 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight2 >= 500 && coffeeWeight2 < 1000)) || ((totalServings >= 10) && (coffeeWeight2 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream2 == 'Y' || cream2 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream2 == 'n' || cream2 == 'N')));
    printf("\n 3|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType3 == 'L' || coffeeType3 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType3 == 'M' || coffeeType3 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType3 == 'R' || coffeeType3 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight3 >= 250 && coffeeWeight3 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight3 >= 500 && coffeeWeight3 < 1000)) || ((totalServings >= 10) && (coffeeWeight3 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream3 == 'Y' || cream3 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream3 == 'n' || cream3 == 'N')));

    printf("\n\nEnter how you like your coffee...");
    printf("\n\nCoffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &coffeeStrength);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &likeCream);
    printf("Typical number of daily servings: ");
    scanf("%d", &totalServings);
    printf("\nThe below table shows how your preferences align to the available products:");
    printf("\n\n--------------------+-------------+-------+");
    printf("\n  |     Coffee      |  Packaged   | With  |");
    printf("\nID|      Type       | Bag Weight  | Cream |");
    printf("\n--+-----------------+-------------+-------+");
    printf("\n 1|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType1 == 'L' || coffeeType1 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType1 == 'M' || coffeeType1 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType1 == 'R' || coffeeType1 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight1 >= 250 && coffeeWeight1 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight1 >= 500 && coffeeWeight1 < 1000)) || ((totalServings >= 10) && (coffeeWeight1 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream1 == 'Y' || cream1 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream1 == 'n' || cream1 == 'N')));
    printf("\n 2|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType2 == 'L' || coffeeType2 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType2 == 'M' || coffeeType2 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType2 == 'R' || coffeeType2 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight2 >= 250 && coffeeWeight2 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight2 >= 500 && coffeeWeight2 < 1000)) || ((totalServings >= 10) && (coffeeWeight2 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream2 == 'Y' || cream2 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream2 == 'n' || cream2 == 'N')));
    printf("\n 3|       %d         |      %d      |   %d   |",
        ((coffeeStrength == 'L' || coffeeStrength == 'l') && (coffeeType3 == 'L' || coffeeType3 == 'l')) || ((coffeeStrength == 'M' || coffeeStrength == 'm') && (coffeeType3 == 'M' || coffeeType3 == 'm')) || ((coffeeStrength == 'R' || coffeeStrength == 'r') && (coffeeType3 == 'R' || coffeeType3 == 'r')),
        ((totalServings >= 1 && totalServings <= 4) && (coffeeWeight3 >= 250 && coffeeWeight3 < 500)) || ((totalServings >= 5 && totalServings <= 9) && (coffeeWeight3 >= 500 && coffeeWeight3 < 1000)) || ((totalServings >= 10) && (coffeeWeight3 >= 1000)),
        ((likeCream == 'y' || likeCream == 'Y') && (cream3 == 'Y' || cream3 == 'y')) || ((likeCream == 'n' || likeCream == 'N') && (cream3 == 'n' || cream3 == 'N')));


    printf("\n\nHope you found a product that suits your likes!");
    printf("\n");

    return 0;
}