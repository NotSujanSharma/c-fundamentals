/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P2)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/
#ifndef W8P1_H
#define W8P1_H


// ----------------------------------------------------------------------------
// defines/macros
#define MAX 3
#define GRAMINSERVING 64
#define LBTOKG 2.20462
// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo{
    int sku;
    double price;
    int cal;
    double weight;
};
struct ReportData{
    int sku;
    double price;
    int cal;
    double weightLbs;
    double weightKgs;
    int gram;
    double totalServing;
    double costPerServing;
    double calCostPerServing;
};

// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptr);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(int seqNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int cal, const double *weight);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double *pounds, double *kgs);

// 9. convert lbs: g
int convertLbsG(const double *pounds, int *grams);

// 10. convert lbs: kg / g
void convertLbs(const double *pounds,double *kgs, int *grams);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gramInAServing, const int totalGrams, double *noOfServings);

// 12. calculate: cost per serving
double calculateCostPerServing(const double *price, const double *noOfServings, double *costPerServing);

// 13. calculate: cost per calorie
double calculateCostPerCal(const double *price, const double *totalCal, double *costPerCal);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFood);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct  ReportData data, const int cheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFood);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
#endif
