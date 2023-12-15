/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #8 (P1)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#ifndef W8P1_H
#define W8P1_H
#define MAX 3
#define SERVING 64

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo{
    int sku;
    double price;
    int cal;
    double weight;
};

// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int *ptr);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double *ptr);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int noOfProducts);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNum);

// 5. Display the formatted table header
void displayCatFoodHeader();

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int sku, const double *price, const int cal, const double *weight);

// 7. Logic entry point
void start();
#endif