/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
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

#include <stdio.h>

int main(void) {

	double income = 0, totalCost = 0;
	int repeat = 0, numItems = 0, i = 0;
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

	// Tabulate && sum up the cost
	for (i = 0; i < numItems; ++i) {
		printf("%3d  %5d    %5c    %11.2lf\n",
			i + 1,
			priority[i],
			finOpt[i],
			cost[i]
		);
		totalCost += cost[i];
	}

	printf("---- -------- -------- -----------\n");
	printf("                      $%11.2lf\n\n", totalCost);
	printf("Best of luck in all your future endeavours!\n");
	
    return 0;
}

/*
    HELPER: printf formatting statements....
	=========================================
	
    Step #7:
		printf("Item Priority Financed        Cost\n");
		printf("---- -------- -------- -----------\n");
		
		printf("%3d  %5d    %5c    %11.2lf\n", ...
		

	Step #8:
		printf("---- -------- -------- -----------\n");
		printf("                      $%11.2lf\n\n", ...

*/