/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #3 (P1)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    const double testValue = 330.99;
    int productID1 = 111, productID2 = 222, productID3 = 111;
    double productPrice1 = 111.49, productPrice2 = 222.99, productPrice3 = 334.49, average;
    char productTaxed1 = 'Y', productTaxed2 = 'N', productTaxed3 = 'N';
    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", productID1);
    printf("  Taxed: %c\n", productTaxed1);
    printf("  Price: $%.4lf\n\n", productPrice1);
    printf("Product-2 (ID:%d)\n", productID2);
    printf("  Taxed: %c\n", productTaxed2);
    printf("  Price: $%.4lf\n\n", productPrice2);
    printf("Product-3 (ID:%d)\n", productID3);
    printf("  Taxed: %c\n", productTaxed3);
    printf("  Price: $%.4lf", productPrice3);
    printf("\n\n");
    average = (productPrice1 + productPrice2 + productPrice3) / 3;
    printf("The average of all prices is: $%.4lf", average);
    printf("\n\n");
    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");
    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", (productTaxed1=='Y'));
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", (productTaxed2 == 'N' && productTaxed3 == 'N'));
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, (productPrice3 < testValue));
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", (productPrice3 > (productPrice1 + productPrice2)));
    printf("5. Is the price of product 1 equal to or more than the price difference\n   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n",(productPrice1>=(productPrice3-productPrice2)),(productPrice3-productPrice2));
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n",(productPrice2>=average));
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", !(productID1==productID2||productID1==productID3));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", !(productID2 == productID1 || productID2 == productID3));
    printf("9. Based on product ID, product 3 is unique -> %d\n", !(productID3 == productID1 || productID3 == productID2));
    return 0;
}