/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P1)
Full Name  : Nathan Kong
Student ID#: 150950236
Email      : nkong@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
/////////////////////////////////////////////////////////////////////////*/

#include <stdio.h>

int main(void)
{
    // You must use this variable in #3 data analysis section!
    const double testValue = 330.99;
    
    const int prod1Id = 111;
    const double prod1Price = 111.49;
    const char prod1Taxed = 'Y';

    const int prod2Id = 222;
    const double prod2Price = 222.99;
    const char prod2Taxed = 'N';

    const int prod3Id = 111;
    const double prod3Price = 334.49;
    const char prod3Taxed = 'N';

    double avgPrice = (prod1Price + prod2Price + prod3Price) / 3;

    printf("Product Information\n");
    printf("===================\n");
    printf("Product-1 (ID:%d)\n", prod1Id);
    printf("  Taxed: %c\n", prod1Taxed);
    printf("  Price: $%.4lf\n\n", prod1Price);

    printf("Product-2 (ID:%d)\n", prod2Id);
    printf("  Taxed: %c\n", prod2Taxed);
    printf("  Price: $%.4lf\n\n", prod2Price);

    printf("Product-3 (ID:%d)\n", prod3Id);
    printf("  Taxed: %c\n", prod3Taxed);
    printf("  Price: $%.4lf\n\n", prod3Price);

    printf("The average of all prices is: $%.4lf\n\n", avgPrice);

    printf("About Relational and Logical Expressions!\n");
    printf("========================================\n");
    printf("1. These expressions evaluate to TRUE or FALSE\n");
    printf("2. FALSE: is always represented by integer value 0\n");
    printf("3. TRUE : is represented by any integer value other than 0\n\n");

    printf("Some Data Analysis...\n");
    printf("=====================\n");
    printf("1. Is product 1 taxable? -> %d\n\n", prod1Taxed == 'Y');
    printf("2. Are products 2 and 3 both NOT taxable (N)? -> %d\n\n", prod2Taxed == 'N' && prod3Taxed == 'N');
    printf("3. Is product 3 less than testValue ($%.2lf)? -> %d\n\n", testValue, prod3Price < testValue);
    printf("4. Is the price of product 3 more than both product 1 and 2 combined? -> %d\n\n", prod3Price > (prod1Price + prod2Price));
    printf("5. Is the price of product 1 equal to or more than the price difference\n");
    printf("   of product 3 LESS product 2? ->  %d (price difference: $%.2lf)\n\n", prod1Price >= (prod3Price - prod2Price), prod3Price - prod2Price);
    printf("6. Is the price of product 2 equal to or more than the average price? -> %d\n\n", prod2Price >= avgPrice);
    printf("7. Based on product ID, product 1 is unique -> %d\n\n", (prod1Id != prod2Id) && (prod1Id != prod3Id));
    printf("8. Based on product ID, product 2 is unique -> %d\n\n", (prod2Id != prod1Id) && (prod2Id != prod3Id));
    printf("9. Based on product ID, product 3 is unique -> %d\n", (prod3Id != prod1Id) && (prod3Id != prod2Id));

    return 0;
}