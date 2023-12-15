/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
// User Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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
	if (ptr != NULL)
	{
		*ptr = input;
	}
	return input;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr)
{
	double input;
	do
	{
		scanf("%lf", &input);
		if (input <= 0)
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while (input <= 0);
	if (ptr != NULL)
	{
		*ptr = input;
	}
	return input;
}
// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts)
{
	printf("Cat Food Cost Analysis\n======================\n\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", noOfProducts);
	printf("NOTE: A 'serving' is %dg\n", GRAMINSERVING);
}
// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int seqNum)
{
	struct CatFoodInfo info;
	printf("\nCat Food Product #%d\n", seqNum + 1);
	printf("--------------------\n");
	printf("SKU           : ");
	getIntPositive(&info.sku);
	printf("PRICE         : $");
	info.price = getDoublePositive(NULL);
	printf("WEIGHT (LBS)  : ");
	getDoublePositive(&info.weight);
	printf("CALORIES/SERV.: ");
	info.cal = getIntPositive(NULL);
	return info;
};
// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int cal, const double *weight)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price,  *weight,cal);
}

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double *pounds, double *kgs)
{
	double kgsValue = *pounds / LBTOKG;
	if (kgs != NULL)
	{
		*kgs = kgsValue;
	}
	return kgsValue;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double *pounds, int *grams)
{
	double lbs = *pounds;
	double gramsValue = convertLbsKg(&lbs, NULL);
	double gramsValueInt = gramsValue * 1000;
	if (grams != NULL)
	{
		*grams = (int)gramsValueInt;
	}
	return (int)gramsValueInt;
}

// 10. convert lbs: kg and g
void convertLbs(const double *pounds, double *kgs, int *grams)
{
	double lbs = *pounds;
	double kgsValue = convertLbsKg(&lbs, NULL);
	int gramsValue = convertLbsG(&lbs, NULL);
	if (kgs != NULL && grams != NULL)
	{
		*kgs = kgsValue;
		*grams = gramsValue;
	}
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gramInAServing, const int totalGrams, double *noOfServings)
{
	double totalServings = (double)totalGrams / (double)gramInAServing;
	if (noOfServings != NULL)
	{
		*noOfServings = totalServings;
	}
	return totalServings;
}
// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *noOfServings, double *costPerServing)
{
	double costPerServ = (*price) / (*noOfServings);
	if (costPerServing != NULL)
	{
		*costPerServing = costPerServ;
	}
	return costPerServ;
}
// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCal, double *costPerCal)
{
	double costCalories = (*price) / (*totalCal);
	if (costPerCal != NULL)
	{
		*costPerCal = costCalories;
	}
	return costCalories;
}
// 14. Derive a reporting detail record based on the cat food product data

struct ReportData calculateReportData(const struct CatFoodInfo catFood)
{
	struct ReportData data;
	data.sku = catFood.sku;
	data.price = catFood.price;
	data.cal = catFood.cal;
	data.weightLbs = catFood.weight;
	data.weightKgs = convertLbsKg(&data.weightLbs, NULL);
	data.gram = convertLbsG(&data.weightLbs, NULL);
	data.totalServing = calculateServings(GRAMINSERVING, data.gram, NULL);
	data.costPerServing = calculateCostPerServing(&data.price, &data.totalServing, NULL);
	double totalCalo=data.totalServing*data.cal;
	data.calCostPerServing = calculateCostPerCal(&data.price, &totalCalo, NULL);
	return data;
}


// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", GRAMINSERVING);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct  ReportData data, const int cheapest){
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf",data.sku, data.price, data.weightLbs,data.weightKgs,data.gram,data.cal,data.totalServing,data.costPerServing,data.calCostPerServing);
	if(cheapest!=0){
		printf(" ***");
	}
	printf("\n");
}
// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood){
	printf("Final Analysis\n--------------\nBased on the comparison data, the PURRR-fect economical option is:\nSKU:%07d Price: $%.2lf\n\nHappy shopping!\n",catFood.sku,catFood.price);
}
// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	struct CatFoodInfo catFood[MAX] = {{0}};
	struct ReportData data[MAX]={{0}};
	int cheapestProduct,i;
	openingMessage(MAX);
	for (i = 0; i < MAX; i++)
	{
		catFood[i] = getCatFoodInfo(i);
		data[i]=calculateReportData(catFood[i]);
		if(data[i-1].costPerServing){
			if(data[i].costPerServing<data[i-1].costPerServing){
				cheapestProduct=i;
			}
		}
		else{
			cheapestProduct=i;
		}

	}
	printf("\n");
	displayCatFoodHeader();
	for (i = 0; i < MAX; i++)
	{
		displayCatFoodData(catFood[i].sku, &catFood[i].price, catFood[i].cal, &catFood[i].weight);
	}
	printf("\n");
	displayReportHeader();
	for(i =0;i <MAX; i++){
		displayReportData(data[i],(i==cheapestProduct));
	}
	printf("\n");
	displayFinalAnalysis(catFood[cheapestProduct]);
}
