/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #2 (P1)

						  DISCLAIMER

This Work is only for educational purpose, any student who comes across this 
work is not permitted to copy this work. AGAIN Any student who comes across these 
documents is warned NOT TO USE these as their homework as it is plagiarism and 
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	double ss, ms, ls;
	const double TAX = 0.13;
	const char patSize = 'S';
	int sscent, mscent, lscent, n, total, subTotal, taxes;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &ss);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &ms);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &ls);
	sscent = ss * 100;
	mscent = ms * 100;
	lscent = ls * 100;
	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf\n", sscent / 100.0f);
	printf("MEDIUM : $%.2lf\n", mscent / 100.0f);
	printf("LARGE  : $%.2lf\n", lscent / 100.0f);
	printf("\nPatty's shirt size is '%c'\n",patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &n);
	subTotal = sscent * n;
	printf("\nPatty's shopping cart...\n");
	printf("Contains : %d shirts\n", n);
	printf("Sub-total: $%.4f\n", subTotal / 100.0f);
	taxes = (TAX * subTotal);
	taxes = taxes+1; //rounding
	printf("Taxes    : $ %.4f\n", taxes / 100.0f);
	total = subTotal + taxes;
	printf("Total    : $%.4f\n", total / 100.0f);
	return 0;
}