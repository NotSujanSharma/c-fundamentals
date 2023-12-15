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
    int reqApples, reqOranges, reqPears, reqTomatoes, reqCabbages;
    int apples=0, oranges=0, pears=0, tomatoes=0, cabbages=0;
    int again;
    do{
        printf("Grocery Shopping\n");
        printf("================\n");
        do
        {
            printf("How many APPLES do you need? : ");
            scanf("%d",&reqApples);
            if(reqApples<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (reqApples<0);
        printf("\n");
        do
        {
            printf("How many ORANGES do you need? : ");
            scanf("%d",&reqOranges);
            if(reqOranges<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (reqOranges<0);
        printf("\n");
        do
        {
            printf("How many PEARS do you need? : ");
            scanf("%d",&reqPears);
            if(reqPears<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (reqPears<0);
        printf("\n");
        do
        {
            printf("How many TOMATOES do you need? : ");
            scanf("%d",&reqTomatoes);
            if(reqTomatoes<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (reqTomatoes<0);
        printf("\n");
        do
        {
            printf("How many CABBAGES do you need? : ");
            scanf("%d",&reqCabbages);
            if(reqCabbages<0){printf("ERROR: Value must be 0 or more.\n");}
        } while (reqCabbages<0);
        printf("\n--------------------------\n");
        printf("Time to pick the products!");
        printf("\n--------------------------\n\n");
        if(reqApples>0){
            do{
                printf("Pick some APPLES... how many did you pick? : ");
                scanf("%d",&apples);
                if(apples>reqApples){
                    printf("You picked too many... only %d more APPLE(S) are needed.\n",reqApples);
                }
                else if((apples<reqApples)&&apples>0){
                    printf("Looks like we still need some APPLES...\n");
                    reqApples-=apples;
                }
                else if(apples<=0){
                    printf("ERROR: You must pick at least 1!\n");
                }
                else{
                    printf("Great, that's the apples done!\n");
                    printf("\n");
                    reqApples-=apples;
                }
            }while(reqApples);
        }
        if (reqOranges > 0) {
            do {
                printf("Pick some ORANGES... how many did you pick? : ");
                scanf("%d", &oranges);
                if (oranges > reqOranges) {
                    printf("You picked too many... only %d more ORANGE(S) are needed.\n", reqOranges);
                }
                else if ((oranges < reqOranges)&&oranges>0) {
                    printf("Looks like we still need some ORANGES...\n");
                    reqOranges -= oranges;
                }
                else if (oranges <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the oranges done!\n");
                    printf("\n");
                    reqOranges -= oranges;
                }
            } while (reqOranges);
        }
        if(reqPears>0){
            do {
                printf("Pick some PEARS... how many did you pick? : ");
                scanf("%d", &pears);
                if (pears > reqPears) {
                    printf("You picked too many... only %d more PEAR(S) are needed.\n", reqPears);
                }
                else if ((pears < reqPears)&&pears>0) {
                    printf("Looks like we still need some PEARS...\n");
                    reqPears -= pears;
                }
                else if (pears <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the pears done!\n");
                    printf("\n");
                    reqPears -= pears;
                }
            } while (reqPears);
        }
        if(reqCabbages>0){
            do {
                printf("Pick some CABBAGES... how many did you pick? : ");
                scanf("%d", &cabbages);
                if (cabbages > reqCabbages) {
                    printf("You picked too many... only %d more CABBAGE(S) are needed.\n", reqCabbages);
                }
                else if ((cabbages < reqCabbages)&&cabbages>0) {
                    printf("Looks like we still need some CABBAGES...\n");
                    reqCabbages -= cabbages;
                }
                else if (cabbages <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the cabbages done!\n");
                    printf("\n");
                    reqCabbages -= cabbages;
                }
            } while (reqCabbages);
        }
        if (reqTomatoes > 0) {
            do {
                printf("Pick some TOMATOES... how many did you pick? : ");
                scanf("%d", &tomatoes);
                if (tomatoes > reqTomatoes) {
                    printf("You picked too many... only %d more TOMATO(ES) are needed.\n", reqTomatoes);
                }
                else if ((tomatoes < reqTomatoes)&&tomatoes>0) {
                    printf("Looks like we still need some TOMATOES...\n");
                    reqTomatoes -= tomatoes;
                }
                else if (tomatoes <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                }
                else {
                    printf("Great, that's the tomatoes done!\n\n");
                    reqTomatoes -= tomatoes;
                }
            } while (reqTomatoes);
        }
        printf("All the items are picked!");
        printf("\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf("%d",&again);
        printf("\n");
    }while(again);
    printf("Your tasks are done for today - enjoy your free time!");
    printf("\n");
    return 0;
}