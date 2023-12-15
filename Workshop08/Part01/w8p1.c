/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS
// System Libraries
#include <stdio.h>
#define TEST_INT 24
// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptr)
{
	int input;
	do
	{
		scanf("%d", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	if(ptr!=NULL){
		*ptr=input;
	}
	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr){
	double input;
	do{
		scanf("%lf",&input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	if(ptr!=NULL){
		*ptr=input;
	}
	return input;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts)
{
	printf("Cat Food Cost Analysis\n======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n",noOfProducts);
	printf("NOTE: A 'serving' is %dg\n",SERVING);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNum){
	struct CatFoodInfo info;
	printf("\nCat Food Product #%d\n",seqNum+1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&info.sku);
	printf("PRICE         : $");
	info.price=getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.weight);
	printf("CALORIES/SERV.: ");
	info.cal=getIntPositive(NULL);
	return info;
};
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int cal, const double *weight){
	printf("%07d %10.2lf %10.1lf %8d\n",sku,*price,*weight,cal);
}

// 7. Logic entry point
void start(){
	int i;
	struct CatFoodInfo catFood[MAX]={{0}};
	openingMessage(MAX);
	for(i=0;i<MAX;i++){
		catFood[i]=getCatFoodInfo(i);
	}
	displayCatFoodHeader();
	for(i=0;i<MAX;i++){
	displayCatFoodData(catFood[i].sku,&catFood[i].price,catFood[i].cal,&catFood[i].weight);
	}
}
