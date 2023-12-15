/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)

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
    ////////////initializing variables
    int requiredApples, requiredOranges, requiredPears, requiredTomatoes, requiredCabbages;
    int pickedApples=0, pickedOranges=0, pickedPears=0, pickedTomatoes=0, pickedCabbages=0;
    int anotherShopping;
    do{
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d",&requiredApples);
            if(requiredApples<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (requiredApples<0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d",&requiredOranges);
            if(requiredOranges<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (requiredOranges<0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d",&requiredPears);
            if(requiredPears<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (requiredPears<0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d",&requiredTomatoes);
            if(requiredTomatoes<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (requiredTomatoes<0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d",&requiredCabbages);
            if(requiredCabbages<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (requiredCabbages<0);
        printf("\n--------------------------\n");
        printf("Time to pick the products!");
        printf("\n--------------------------\n\n");
        /////apple
        if(requiredApples>0){
            do{
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d",&pickedApples);
                if(pickedApples>requiredApples){
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",requiredApples);
                }
                else if((pickedApples<requiredApples)&&pickedApples>0){
                    printf("Looks like we still need some APPLES...\n");
                    requiredApples=requiredApples-pickedApples;
                }
                else if(pickedApples<=0){
                    /////error
                    printf("ERROR: You must pick at least 1!\n");
                }
                else{
                    printf("Great, that's the apples done!\n\n");
                    requiredApples=requiredApples-pickedApples;
                }
            }while(requiredApples!=0);
        }
        /////////oranges
        if (requiredOranges > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &pickedOranges);
                if (pickedOranges > requiredOranges) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", requiredOranges);
                }
                else if ((pickedOranges < requiredOranges)&&pickedOranges>0) {
                    printf("Looks like we still need some ORANGES...\n");
                    requiredOranges = requiredOranges - pickedOranges;
                }
                else if (pickedOranges <= 0) {
                    /////error
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the oranges done!\n\n");
                    requiredOranges = requiredOranges - pickedOranges;
                }
            } while (requiredOranges != 0);
        }
        ///////////Pears
        if(requiredPears>0){
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pickedPears);
                if (pickedPears > requiredPears) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", requiredPears);
                }
                else if ((pickedPears < requiredPears)&&pickedPears>0) {
                    printf("Looks like we still need some PEARS...\n");
                    requiredPears = requiredPears - pickedPears;
                }
                else if (pickedPears <= 0) {
                    /////error
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the pears done!\n\n");
                    requiredPears = requiredPears - pickedPears;
                }
            } while (requiredPears != 0);
        }
        //////cabbages
        if(requiredCabbages>0){
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &pickedCabbages);
                if (pickedCabbages > requiredCabbages) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", requiredCabbages);
                }
                else if ((pickedCabbages < requiredCabbages)&&pickedCabbages>0) {
                    printf("Looks like we still need some CABBAGES...\n");
                    requiredCabbages = requiredCabbages - pickedCabbages;
                }
                else if (pickedCabbages <= 0) {
                    /////error
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the cabbages done!\n\n");
                    requiredCabbages = requiredCabbages - pickedCabbages;
                }
            } while (requiredCabbages != 0);
        }
        ////////////Tomatoes
        if (requiredTomatoes > 0) {
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &pickedTomatoes);
                if (pickedTomatoes > requiredTomatoes) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", requiredTomatoes);
                }
                else if ((pickedTomatoes < requiredTomatoes)&&pickedTomatoes>0) {
                    printf("Looks like we still need some TOMATOES...\n");
                    requiredTomatoes = requiredTomatoes - pickedTomatoes;
                }
                else if (pickedTomatoes <= 0) {
                    /////error
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the tomatoes done!\n\n");
                    requiredTomatoes = requiredTomatoes - pickedTomatoes;
                }
            } while (requiredTomatoes != 0);
        }
        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d",&anotherShopping);
        printf("\n");
    }while(anotherShopping!=0);
    ////Success
    printf("Your tasks are done for today - enjoy your free time!\n");
    return 0;
}