/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P2)
Full Name  : Nathan Kong
Student ID#: 150950236
Email      : nkong@myseneca.ca
Section    : NDD

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const double TAX = 0.13;
    const char patSize = 'S', salSize = 'M', tomSize = 'L';

    double sPrice, mPrice, lPrice;
    int patNumShirts, salNumShirts, tomNumShirts, totalNumShirts,
        patSubTotal, patTaxes, patTotal,
        salSubTotal, salTaxes, salTotal,
        tomSubTotal, tomTaxes, tomTotal,
        subTotal, total;

    printf("Set Shirt Prices\n================\n");

    printf("Enter the price for a SMALL shirt: $");     // 17.96
    scanf("%lf", &sPrice);
    printf("Enter the price for a MEDIUM shirt: $");    // 26.96
    scanf("%lf", &mPrice);
    printf("Enter the price for a LARGE shirt: $");     // 35.97
    scanf("%lf", &lPrice);

    printf("\nShirt Store Price List\n======================\n");
    printf("SMALL  : $%.2lf\n", sPrice);
    printf("MEDIUM : $%.2lf\n", mPrice);
    printf("LARGE  : $%.2lf\n", lPrice);

    printf("\nPatty's shirt size is '%c'\n", patSize);
    printf("Number of shirts Patty is buying: ");       // 6
    scanf("%d", &patNumShirts);

    printf("\nTommy's shirt size is '%c'\n", tomSize);
    printf("Number of shirts Tommy is buying: ");       // 3
    scanf("%d", &tomNumShirts);

    printf("\nSally's shirt size is '%c'\n", salSize);
    printf("Number of shirts Sally is buying: ");       // 4
    scanf("%d", &salNumShirts);

    totalNumShirts = patNumShirts + tomNumShirts + salNumShirts;

    patSubTotal = sPrice * 100 * patNumShirts + 0.5;
    patTaxes = patSubTotal * TAX + 0.5;
    patTotal = patSubTotal + patTaxes;

    salSubTotal = mPrice * 100 * salNumShirts + 0.5;
    salTaxes = salSubTotal * TAX + 0.5;
    salTotal = salSubTotal + salTaxes;

    tomSubTotal = lPrice * 100 * tomNumShirts + 0.5;
    tomTaxes = tomSubTotal * TAX + 0.5;
    tomTotal = tomSubTotal + tomTaxes;

    subTotal = patSubTotal + salSubTotal + tomSubTotal;
    total = patTotal + salTotal + tomTotal;

    printf("\n");
    printf("Customer Size Price Qty Sub-Total       Tax     Total\n");
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("Patty    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        patSize, sPrice, patNumShirts,
        patSubTotal / 100.0, patTaxes / 100.0, patTotal / 100.0
    );
    printf("Sally    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        salSize, mPrice, salNumShirts,
        salSubTotal / 100.0, salTaxes / 100.0, salTotal / 100.0
    );
    printf("Tommy    %-4c %5.2lf %3d %9.4lf %9.4lf %9.4lf\n", 
        tomSize, lPrice, tomNumShirts,
        tomSubTotal / 100.0, tomTaxes / 100.0, tomTotal / 100.0
    );
    printf("-------- ---- ----- --- --------- --------- ---------\n");
    printf("%33.4lf %9.4lf %9.4lf\n\n", 
        subTotal / 100.0, 
        (patTaxes + salTaxes + tomTaxes) / 100.0, 
        total / 100.0
    );

    int quotient, remainder;
    double avgCstPerShrt;

    printf("Daily retail sales represented by coins\n");
    printf("=======================================\n\n");
    printf("Sales EXCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", subTotal / 100.0);

    quotient = subTotal / 200;
    remainder = subTotal % 200;
    printf("Toonies  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 100;
    remainder = remainder % 100;
    printf("Loonies  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 25;
    remainder = remainder % 25;
    printf("Quarters %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 10;
    remainder = remainder % 10;
    printf("Dimes    %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 5;
    remainder = remainder % 5;
    printf("Nickels  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 1;
    remainder = remainder % 1;
    printf("Pennies  %3d %9.4lf\n", quotient, remainder / 100.0);

    avgCstPerShrt = (double)subTotal / totalNumShirts / 100;
    printf("\nAverage cost/shirt: $%.4lf\n\n", avgCstPerShrt);

    printf("Sales INCLUDING tax\n");
    printf("Coin     Qty   Balance\n");
    printf("-------- --- ---------\n");
    printf("%22.4lf\n", total / 100.0);

    quotient = total / 200;
    remainder = total % 200;
    printf("Toonies  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 100;
    remainder = remainder % 100;
    printf("Loonies  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 25;
    remainder = remainder % 25;
    printf("Quarters %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 10;
    remainder = remainder % 10;
    printf("Dimes    %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 5;
    remainder = remainder % 5;
    printf("Nickels  %3d %9.4lf\n", quotient, remainder / 100.0);

    quotient = remainder / 1;
    remainder = remainder % 1;
    printf("Pennies  %3d %9.4lf\n", quotient, remainder / 100.0);

    avgCstPerShrt = (double)total / totalNumShirts / 100;
    printf("\nAverage cost/shirt: $%.4lf\n", avgCstPerShrt);
    return 0;
}