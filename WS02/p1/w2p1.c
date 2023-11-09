<<<<<<< Updated upstream
//
// Float issues, casting, rounding, working in cents...
//
=======
/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #2 (P1)
Full Name  : Nathan Kong
Student ID#: 150950236
Email      : nkong@myseneca.ca
Section    : NDD

Authenticity Declaration:

I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/
>>>>>>> Stashed changes

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

/*  Canadian Coin Denominations
    Coin    $val    Cents
    ------- ------- -----------
    Toonie  $2.00   200
    Loonie  $1.00   100
    Quarter $0.25    25
    Dime    $0.10    10
    Nickel  $0.05     5
    Penny   $0.01     1
*/

int main(void)
{
    const double TAX = 0.13;
    double price = 17.97;
    int qty = 8;

    // Rounding... for handling inaccurate floating-point values!
    // Method-1:
    //int subTotal = ((price * qty) * 100) + 0.5;
    // Method-2:
    int subTotal = ((price * qty) + 0.005) * 100;

    double subTotalWrong = price * qty;
    int coins, remaining;

    printf("Product price     : $%.2lf\n", price);
    printf("Number of products: %d\n", qty);
    printf("Subtotal          : %d\n", subTotal);
    // 3 ways to get the same result: make just 1 of the operands
    //                                a double type (cast) and all
    //                                will become double!
    printf("Subtotal          : $%.2lf\n", (double)subTotal / 100);
    printf("Subtotal          : $%.4lf\n", subTotal / 100.0);
    //printf("Subtotal          : $%.4lf\n", subTotal / (double)100);

    // Quarters:
    coins = subTotal / 25;
    //remaining = subTotal - (coins * 25); // NO!!! bad!! Horse!
    remaining = subTotal % 25; // Use Modulus operator %!!!
    printf("Quarters: %d (Remaining: %d)\n", coins, remaining);
    printf("Quarters: %d (Remaining: $%.2lf)\n", coins, remaining/100.0);

    double sPrice, mPrice, lPrice;
    int numShirts, subTotal, taxes, total;

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
    printf("Number of shirts Patty is buying: ");
    scanf("%d", &numShirts);

    subTotal = sPrice * 100 * numShirts + 0.5;
    taxes = subTotal * TAX + 0.5;
    total = subTotal + taxes;

    printf("\nPatty's shopping cart...\n");
    printf("Contains : %d shirts\n", numShirts);
    printf("Sub-total: $%8.4lf\n", subTotal / 100.0);
    printf("Taxes    : $%8.4lf\n", taxes / 100.0);
    printf("Total    : $%8.4lf\n", total / 100.0);

    return 0;
}