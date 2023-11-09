/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P2)
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

#define MIN_INCOME 500.00
#define MAX_INCOME 400000.00

#define MIN_ITEMS 1
#define MAX_ITEMS 10

#define MIN_COST 100.00
#define MIN_PRI 1
#define MAX_PRI 3
#define FIN_OPT_Y 'y'
#define FIN_OPT_N 'n'

// Menu Options
#define OPT_ALL 1
#define OPT_PRI 2
#define OPT_EXT 0

#define mInY 12     // monthsInYear
#define cInD 100    // centsInDollar

#include <stdio.h>

int main(void) {

	double income = 0, totalCost = 0;
	int repeat = 0, numItems = 0, i = 0;

    double subtotalCost = 0;
    int menuOpt = 0, finOptAvl = 0, priOpt = 0;
    int totalCents = 0, incomeCents = 0, numYears = 0, numMonths = 0;

	double cost[MAX_ITEMS] = {};
	int priority[MAX_ITEMS] = {};
	char finOpt[MAX_ITEMS] = {};


	printf("+--------------------------+\n");
	printf("+   Wish List Forecaster   |\n");
	printf("+--------------------------+\n\n");

	// Validate net monthly income
	do {
		printf("Enter your monthly NET income: $");
		scanf(" %lf", &income);

		if (income < MIN_INCOME) {
			repeat = 1;
			printf("ERROR: You must have a consistent monthly income of at least $%.2lf\n\n", MIN_INCOME);

		} else if (income > MAX_INCOME) {
			repeat = 1;
			printf("ERROR: Liar! I'll believe you if you enter a value no more than $%.2lf\n\n", MAX_INCOME);

		} else {
            repeat = 0;
            incomeCents = income * cInD;
        }
	} while (repeat);

	printf("\n");

	// Validate number of wish list items
	do {
		printf("How many wish list items do you want to forecast?: ");
		scanf(" %d", &numItems);

		if (numItems < MIN_ITEMS || numItems > MAX_ITEMS) {
			repeat = 1;
			printf("ERROR: List is restricted to between 1 and 10 items.\n\n");
		} else {
            repeat = 0;
        }
	} while (repeat);

	for (i = 0; i < numItems; ++i) {
		printf("\n");
		printf("Item-%d Details:\n", i + 1);

		// Validate cost
		do {
			printf("   Item cost: $");
			scanf("%lf", &cost[i]);

			if (cost[i] < MIN_COST) {
				repeat = 1;
				printf("      ERROR: Cost must be at least $%.2lf\n", MIN_COST);
			} else {
                repeat = 0;
            }
		} while (repeat);

		// Validate priority
		do {
			printf("   How important is it to you? [1=must have, 2=important, 3=want]: ");
			scanf(" %d", &priority[i]);

			if (priority[i] < MIN_PRI || priority[i] > MAX_PRI) {
				repeat = 1;
				printf("      ERROR: Value must be between %d and %d\n", MIN_PRI, MAX_PRI);
			} else {
                repeat = 0;
            }
        } while (repeat);

		// Validate finance options
		do {
			printf("   Does this item have financing options? [y/n]: ");
			scanf(" %c", &finOpt[i]);

			if (finOpt[i] != FIN_OPT_Y && finOpt[i] != FIN_OPT_N) {
				repeat = 1;
				printf("      ERROR: Must be a lowercase 'y' or 'n'\n");
			} else {
                repeat = 0;
            }
		} while (repeat);
	}

	printf("\n");
	printf("Item Priority Financed        Cost\n");
	printf("---- -------- -------- -----------\n");

	// Tabulate, sum up the cost, and check if financing options are available
	for (i = 0; i < numItems; ++i) {

        // Tabulate
		printf("%3d  %5d    %5c    %11.2lf\n",
			i + 1,
			priority[i],
			finOpt[i],
			cost[i]
		);

        // Sum up the cost
		totalCost += cost[i];

        // If financing options are available
        if (finOpt[i] == FIN_OPT_Y)
            finOptAvl = 1;
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);

    do {
        printf("How do you want to forecast your wish list?\n");
        printf(" 1. All items (no filter)\n");
        printf(" 2. By priority\n");
        printf(" 0. Quit/Exit\n");
        printf("Selection: ");
        scanf(" %d", &menuOpt);
        printf("\n");

        repeat = 1;

        switch (menuOpt) {
            case OPT_ALL:
                // Total cost and financing options is already calculated in the previous for loop
                totalCents = totalCost * cInD;

                numYears = totalCents / (mInY * incomeCents);
                numMonths = (totalCents / incomeCents + !!(totalCents % incomeCents)) % mInY;

                printf("====================================================\n");
                printf("Filter:   All items\n");
                printf("Amount:   $%1.2lf\n", totalCost);
                printf("Forecast: %d years, %d months\n", numYears, numMonths);

                if (finOptAvl){
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                
                printf("====================================================\n\n");

                break;

            case OPT_PRI:
                do {
                    printf("What priority do you want to filter by? [1-3]: ");
                    scanf(" %d", &priOpt);
                    printf("\n");

                    if (priOpt < MIN_PRI || priOpt > MAX_PRI) {
                        printf("ERROR: Value must be between %d and %d\n", MIN_PRI, MAX_PRI);
                    } else {
                        repeat = 0;
                    }
                } while (repeat);

                // Reset the `repeat` flag, `finOptAvl` boolean, and `subtotalCost`
                repeat = 1;
                finOptAvl = 0;
                subtotalCost = 0;

                for (i = 0; i < numItems; ++i) {
                    
                    // For matching priority
                    if (priority[i] == priOpt) {

                        // Sum up the cost
                        subtotalCost += cost[i];

                        // If financing options are available
                        if (finOpt[i] == FIN_OPT_Y)
                            finOptAvl = 1;
                    }
                }

                totalCents = subtotalCost * cInD;

                numYears = totalCents / (mInY * incomeCents);
                numMonths = (totalCents / incomeCents + !!(totalCents % incomeCents)) % mInY;
                
                printf("====================================================\n");
                printf("Filter:   by priority (%d)\n", priOpt);
                printf("Amount:   $%1.2lf\n", subtotalCost);
                printf("Forecast: %d years, %d months\n", numYears, numMonths);

                if (finOptAvl){
                    printf("NOTE: Financing options are available on some items.\n");
                    printf("      You can likely reduce the estimated months.\n");
                }
                
                printf("====================================================\n\n");
                break;

            case OPT_EXT:
                repeat = 0;
	            printf("Best of luck in all your future endeavours!\n");
                break;

            default:
                printf("ERROR: Invalid menu selection.\n\n");
                break;
        }

    } while (repeat);


    return 0;
}
