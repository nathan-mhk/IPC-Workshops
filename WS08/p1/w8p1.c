/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P1)
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


// System Libraries
#include <stdio.h>

// User Libraries
#include "w8p1.h"

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr) {
	int repeat = 0;
	int val = 0;
	do {
		scanf("%d", &val);

		if (val > 0) {
			repeat = 0;
		} else {
			repeat = 1;
			printf("ERROR: Enter a positive value: ");
		}
	} while (repeat);

	if (intPtr) {
		*intPtr = val;
	}
	return val;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblPtr) {
	int repeat = 0;
	double val = 0;
	do {
		scanf("%lf", &val);

		if (val > 0) {
			repeat = 0;
		} else {
			repeat = 1;
			printf("ERROR: Enter a positive value: ");
		}
	} while (repeat);

	if (dblPtr) {
		*dblPtr = val;
	}
	return val;
}

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProds) {
	printf("Cat Food Cost Analysis\n");
	printf("======================\n");
	printf("\n");
	printf("Enter the details for %d dry food bags of product data for analysis.\n", numProds);
	printf("NOTE: A 'serving' is %dg\n", SUGG_SERV);
}

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNum) {
	struct CatFoodInfo catFood;

	int sku = 0;
	double price = 0;
	int calPerServ = 0;
	double weight = 0;

	printf("Cat Food Product #%d\n", seqNum);
	printf("--------------------\n");

	printf("SKU           : ");
	getIntPositive(&sku);

	printf("PRICE         : $");
	getDoublePositive(&price);

	printf("WEIGHT (LBS)  : ");
	weight = getDoublePositive(NULL);

	printf("CALORIES/SERV.: ");
	calPerServ = getIntPositive(NULL);

	catFood.sku = sku;
	catFood.price = price;
	catFood.calPerServ = calPerServ;
	catFood.weight = weight;

	return catFood;
}

// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("SKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data
void displayCatFoodData(
	const int sku, 
	const double* const price, 
	const int calPerServ, 
	const double* const weight
	) {
	printf("%07d %10.2lf %10.1lf %8d\n", sku, *price, *weight, calPerServ);
}

// 7. Logic entry point
void start() {
	struct CatFoodInfo catFoods[MAX_NUM_PRODS];
	int i = 0;

	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		catFoods[i].sku = 0;
		catFoods[i].price = 0;
		catFoods[i].calPerServ = 0;
		catFoods[i].weight = 0;
	}

	openingMessage(MAX_NUM_PRODS);
	printf("\n");

	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		catFoods[i] = getCatFoodInfo(i + 1);
		printf("\n");
	}

	displayCatFoodHeader();
	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		displayCatFoodData(
			catFoods[i].sku,
			&catFoods[i].price,
			catFoods[i].calPerServ,
			&catFoods[i].weight
		);
	}
	printf("\n");

}
