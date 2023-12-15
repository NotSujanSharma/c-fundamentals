/*/////////////////////////////////////////////////////////////////////////
                                                  Workshop - #2 (P2)

                                                  DISCLAIMER

This Work is only for educational purpose, any student who comes across this
work is not permitted to copy this work. AGAIN Any student who comes across these
documents is warned NOT TO USE these as their homework as it is plagiarism and
a clear violation of Seneca's Academic Integrity!

/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main(void) {
	double smallShirt, mediumShirt, largeShirt, average;
	const double TAX = 0.13;
	const char patSize = 'S', salSize = 'M', tomSize = 'L';
	int patShirts, patSubTotal, patTotal, patTaxes;
	int ssCent, msCent, lsCent, total, subTotal,totalTaxes;
	int toonies, loonies, quaters, dimes, nickels, pennies, balance;
	int sallyShirts, sallySubTotal, sallyTaxes, sallyTotal;
	int tommyShirts, tommySubTotal, tommyTaxes, tommyTotal;
	printf("Set Shirt Prices\n");
	printf("================\n");
	printf("Enter the price for a SMALL shirt: $");
	scanf("%lf", &smallShirt);
	printf("Enter the price for a MEDIUM shirt: $");
	scanf("%lf", &mediumShirt);
	printf("Enter the price for a LARGE shirt: $");
	scanf("%lf", &largeShirt);
	ssCent = smallShirt * 100;
	msCent = mediumShirt * 100;
	lsCent = largeShirt * 100;
	printf("\nShirt Store Price List\n");
	printf("======================\n");
	printf("SMALL  : $%.2lf\n", ssCent / 100.0f);
	printf("MEDIUM : $%.2lf\n", msCent / 100.0f);
	printf("LARGE  : $%.2lf\n", lsCent / 100.0f);
	printf("\nPatty's shirt size is '%c'\n", patSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &patShirts);
	printf("\nPatty's shirt size is '%c'\n", tomSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &tommyShirts);
	printf("\nPatty's shirt size is '%c'\n", salSize);
	printf("Number of shirts Patty is buying: ");
	scanf("%d", &sallyShirts);
	printf("\nCustomer Size Price Qty Sub-Total       Tax     Total\n");
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	patSubTotal = ssCent * patShirts;
	patTaxes = (TAX * patSubTotal);
	patTaxes = patTaxes + 1; //rounding
	patTotal = patSubTotal + patTaxes;
	printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", patSize, ssCent / 100.0f, patShirts,patSubTotal/100.0f,patTaxes/100.0f,patTotal/100.0f );

	sallySubTotal = msCent * sallyShirts;
	sallyTaxes = (TAX * sallySubTotal);
	sallyTaxes = sallyTaxes + 1; //rounding
	sallyTotal = sallySubTotal + sallyTaxes;
	printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", salSize, msCent / 100.0f, sallyShirts, sallySubTotal / 100.0f, sallyTaxes / 100.0f, sallyTotal / 100.0f);

	tommySubTotal = lsCent * tommyShirts;
	tommyTaxes = (TAX * tommySubTotal);
	tommyTaxes = tommyTaxes + 1; //rounding
	tommyTotal = tommySubTotal + tommyTaxes;
	printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", tomSize, lsCent / 100.0f, tommyShirts, tommySubTotal / 100.0f, tommyTaxes / 100.0f, tommyTotal / 100.0f);
	printf("-------- ---- ----- --- --------- --------- ---------\n");
	subTotal = patSubTotal + tommySubTotal + sallySubTotal;
	totalTaxes = patTaxes + tommyTaxes + sallyTaxes;
	total = patTotal + tommyTotal + sallyTotal;
	printf("%33.4lf %9.4lf %9.4lf\n\n", subTotal / 100.0f, totalTaxes / 100.0f, total / 100.0f);
	printf("Daily retail sales represented by coins\n");
	printf("=======================================\n\n");
	printf("Sales EXCLUDING tax\n");
	printf("Coin     Qty   Balance\n");
	printf("-------- --- ---------\n");
	balance = subTotal;
	printf("%22.4lf\n", balance / 100.0f);
	toonies = balance / 200;
	balance = balance % 200;
	printf("Toonies  %3d %9.4lf\n", toonies, balance/100.0f);
	loonies = balance / 100.0f;
	balance = balance % 100;
	printf("Loonies  %3d %9.4lf\n", loonies, balance / 100.0f);
	quaters = balance / 25.0f;
	balance = balance % 25;
	printf("Quaters  %3d %9.4lf\n", quaters, balance / 100.0f);
	dimes = balance / 10.0f;
	balance = balance % 10;
	printf("Dimes  %5d %9.4lf\n", dimes, balance / 100.0f);
	nickels = balance / 5.0f;
	balance = balance % 5;
	printf("Nickles  %3d %9.4lf\n", nickels, balance / 100.0f);
	pennies = balance / 1.0f;
	balance = balance % 1;
	printf("Pennies  %3d %9.4lf\n\n", pennies, balance / 100.0f);
	average = (double)subTotal / (patShirts + sallyShirts + tommyShirts);
	printf("Average cost/shirt: $%.4lf\n\n",average/100);


	printf("Sales INCLUDING tax\n");
	printf("Coin     Qty   Balance\n--------- --- ---------\n");
	balance = total;
	printf("%22.4lf\n", balance / 100.0f);
	toonies = balance / 200;
	balance = balance % 200;
	printf("Toonies  %3d %9.4lf\n", toonies, balance / 100.0f);
	loonies = balance / 100.0f;
	balance = balance % 100;
	printf("Loonies  %3d %9.4lf\n", loonies, balance / 100.0f);
	quaters = balance / 25.0f;
	balance = balance % 25;
	printf("Quaters  %3d %9.4lf\n", quaters, balance / 100.0f);
	dimes = balance / 10.0f;
	balance = balance % 10;
	printf("Dimes  %5d %9.4lf\n", dimes, balance / 100.0f);
	nickels = balance / 5.0f;
	balance = balance % 5;
	printf("Nickles  %3d %9.4lf\n", nickels, balance / 100.0f);
	pennies = balance / 1.0f;
	balance = balance % 1;
	printf("Pennies  %3d %9.4lf\n\n", pennies, balance / 100.0f);
	average = (double)total / (patShirts + sallyShirts + tommyShirts);
	printf("Average cost/shirt: $%.4lf\n", average / 100);

	return 0;
}
