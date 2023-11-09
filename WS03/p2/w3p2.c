/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #3 (P2)
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
    // You will need this when converting from grams to pounds (lbs)
    const double GRAMS_IN_LBS = 453.5924;

    char coffee1Type, coffee2Type, coffee3Type;
    int coffee1Weight, coffee2Weight, coffee3Weight;
    char coffee1Cream, coffee2Cream, coffee3Cream;

    char ctmCoffeeTyp;
    int ctmCoffeeWgt;
    char ctmCoffeeCrm;

    printf("Take a Break - Coffee Shop\n");
    printf("==========================\n\n");
    printf("Enter the coffee product information being sold today...\n\n");

    printf("COFFEE-1...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee1Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee1Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee1Cream);
    printf("\n");

    printf("COFFEE-2...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee2Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee2Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee2Cream);
    printf("\n");

    printf("COFFEE-3...\n");
    printf("Type ([L]ight,[M]edium,[R]ich): ");
    scanf(" %c", &coffee3Type);
    printf("Bag weight (g): ");
    scanf(" %d", &coffee3Weight);
    printf("Best served with cream ([Y]es,[N]o): ");
    scanf(" %c", &coffee3Cream);
    printf("\n");

    printf("---+------------------------+---------------+-------+\n");
    printf("   |    Coffee              |   Packaged    | Best  |\n");
    printf("   |     Type               |  Bag Weight   | Served|\n");
    printf("   +------------------------+---------------+ With  |\n");
    printf("ID | Light | Medium | Rich  |  (G) | Lbs    | Cream |\n");
    printf("---+------------------------+---------------+-------|\n");
    printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", 
            coffee1Type == 'l' || coffee1Type == 'L',
            coffee1Type == 'm' || coffee1Type == 'M',
            coffee1Type == 'r' || coffee1Type == 'R',
            coffee1Weight,
            coffee1Weight / GRAMS_IN_LBS,
            coffee1Cream == 'y' || coffee1Cream == 'Y'
    );
    printf(" 2 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n", 
            coffee2Type == 'l' || coffee2Type == 'L',
            coffee2Type == 'm' || coffee2Type == 'M',
            coffee2Type == 'r' || coffee2Type == 'R',
            coffee2Weight,
            coffee2Weight / GRAMS_IN_LBS,
            coffee2Cream == 'y' || coffee2Cream == 'Y'
    );
    printf(" 3 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n\n", 
            coffee3Type == 'l' || coffee3Type == 'L',
            coffee3Type == 'm' || coffee3Type == 'M',
            coffee3Type == 'r' || coffee3Type == 'R',
            coffee3Weight,
            coffee3Weight / GRAMS_IN_LBS,
            coffee3Cream == 'y' || coffee3Cream == 'Y'
    );

    // for (int i = 0; i <= 1; ++i) {
        printf("Enter how you like your coffee...\n\n");
        printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
        scanf(" %c", &ctmCoffeeTyp);
        printf("Do you like your coffee with cream ([Y]es,[N]o): ");
        scanf(" %c", &ctmCoffeeCrm);
        printf("Typical number of daily servings: ");
        scanf(" %d", &ctmCoffeeWgt);
        printf("\n");

        printf("The below table shows how your preferences align to the available products:\n\n");
        printf("--------------------+-------------+-------+\n");
        printf("  |     Coffee      |  Packaged   | With  |\n");
        printf("ID|      Type       | Bag Weight  | Cream |\n");
        printf("--+-----------------+-------------+-------+\n");
        printf(" 1|       %d         |      %d      |   %d   |\n",
            (coffee1Type == ctmCoffeeTyp) ||
            (coffee1Type - ctmCoffeeTyp == 32) ||
            (coffee1Type - ctmCoffeeTyp == -32),

            (coffee1Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
            (coffee1Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
            (coffee1Weight == 1000 && ctmCoffeeWgt >= 10),

            (coffee1Cream == ctmCoffeeCrm) ||
            (coffee1Cream - ctmCoffeeCrm == 32) ||
            (coffee1Cream - ctmCoffeeCrm == -32)
        );
        printf(" 2|       %d         |      %d      |   %d   |\n",
            (coffee2Type == ctmCoffeeTyp) ||
            (coffee2Type - ctmCoffeeTyp == 32) ||
            (coffee2Type - ctmCoffeeTyp == -32),

            (coffee2Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
            (coffee2Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
            (coffee2Weight == 1000 && ctmCoffeeWgt >= 10),
            
            (coffee2Cream == ctmCoffeeCrm) ||
            (coffee2Cream - ctmCoffeeCrm == 32) ||
            (coffee2Cream - ctmCoffeeCrm == -32)
        );
        printf(" 3|       %d         |      %d      |   %d   |\n\n",
            (coffee3Type == ctmCoffeeTyp) ||
            (coffee3Type - ctmCoffeeTyp == 32) ||
            (coffee3Type - ctmCoffeeTyp == -32),

            (coffee3Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
            (coffee3Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
            (coffee3Weight == 1000 && ctmCoffeeWgt >= 10),
            
            (coffee3Cream == ctmCoffeeCrm) ||
            (coffee3Cream - ctmCoffeeCrm == 32) ||
            (coffee3Cream - ctmCoffeeCrm == -32)
        );
    // }

    printf("Enter how you like your coffee...\n\n");
    printf("Coffee strength ([L]ight, [M]edium, [R]ich): ");
    scanf(" %c", &ctmCoffeeTyp);
    printf("Do you like your coffee with cream ([Y]es,[N]o): ");
    scanf(" %c", &ctmCoffeeCrm);
    printf("Typical number of daily servings: ");
    scanf(" %d", &ctmCoffeeWgt);
    printf("\n");

    printf("The below table shows how your preferences align to the available products:\n\n");
    printf("--------------------+-------------+-------+\n");
    printf("  |     Coffee      |  Packaged   | With  |\n");
    printf("ID|      Type       | Bag Weight  | Cream |\n");
    printf("--+-----------------+-------------+-------+\n");
    printf(" 1|       %d         |      %d      |   %d   |\n",
        (coffee1Type == ctmCoffeeTyp) ||
        (coffee1Type - ctmCoffeeTyp == 32) ||
        (coffee1Type - ctmCoffeeTyp == -32),

        (coffee1Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
        (coffee1Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
        (coffee1Weight == 1000 && ctmCoffeeWgt >= 10),

        (coffee1Cream == ctmCoffeeCrm) ||
        (coffee1Cream - ctmCoffeeCrm == 32) ||
        (coffee1Cream - ctmCoffeeCrm == -32)
    );
    printf(" 2|       %d         |      %d      |   %d   |\n",
        (coffee2Type == ctmCoffeeTyp) ||
        (coffee2Type - ctmCoffeeTyp == 32) ||
        (coffee2Type - ctmCoffeeTyp == -32),

        (coffee2Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
        (coffee2Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
        (coffee2Weight == 1000 && ctmCoffeeWgt >= 10),
        
        (coffee2Cream == ctmCoffeeCrm) ||
        (coffee2Cream - ctmCoffeeCrm == 32) ||
        (coffee2Cream - ctmCoffeeCrm == -32)
    );
    printf(" 3|       %d         |      %d      |   %d   |\n\n",
        (coffee3Type == ctmCoffeeTyp) ||
        (coffee3Type - ctmCoffeeTyp == 32) ||
        (coffee3Type - ctmCoffeeTyp == -32),

        (coffee3Weight == 250 && ctmCoffeeWgt >= 1 && ctmCoffeeWgt <= 4) ||
        (coffee3Weight == 500 && ctmCoffeeWgt >= 5 && ctmCoffeeWgt <= 9) ||
        (coffee3Weight == 1000 && ctmCoffeeWgt >= 10),
        
        (coffee3Cream == ctmCoffeeCrm) ||
        (coffee3Cream - ctmCoffeeCrm == 32) ||
        (coffee3Cream - ctmCoffeeCrm == -32)
    );

    printf("Hope you found a product that suits your likes!\n");

    return 0;
}


/*

Provided formatting parts for printf statements:

As described in step-7
======================
printf(" 1 |   %d   |   %d    |   %d   | %4d | %6.3lf |   %d   |\n",

As described in step-10
=======================
printf(" 1|       %d         |      %d      |   %d   |\n",

*/