/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #8 (P2)
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

// User-Defined Libraries
#include "w8p2.h"

// ----------------------------------------------------------------------------
// PART-1

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


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* const lbs, double* kg) {
	double result = *lbs / LBS_IN_KG;

	if (kg) {
		*kg = result;
	}
	return result;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* const lbs, int* g) {
	int result = convertLbsKg(lbs, NULL) * 1000;

	if (g) {
		*g = result;
	}
	return result;
}

// 10. convert lbs: kg and g
void convertLbs(const double* const lbs, double* kg, int* g) {
	*kg = convertLbsKg(lbs, NULL);
	*g = convertLbsG(lbs, NULL);
}

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalG, double* numServ) {
	double result = (double)totalG / gPerServ;

	if (numServ) {
		*numServ = result;
	}
	return result;
}

// 12. calculate: cost per serving
double calculateCostPerServing(
    const double* const price,
    const double* const totalNumServ,
    double* costPerServ
) {
	double result = *price / *totalNumServ;

	if (costPerServ) {
		*costPerServ = result;
	}
	return result;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(
    const double* const price,
    const double* const totalCals,
    double* costPerCal
) {
	double result = *price / *totalCals;

	if (costPerCal) {
		*costPerCal = result;
	}
	return result;
}

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo) {
	struct ReportData reportData;
	
	reportData.sku = catFoodInfo.sku;
	reportData.price = catFoodInfo.price;
	reportData.calPerServ = catFoodInfo.calPerServ;
	reportData.weightLbs = catFoodInfo.weight;

	convertLbsKg(&reportData.weightLbs, &reportData.weightKg);
	convertLbsG(&reportData.weightLbs, &reportData.weightG);
	calculateServings(SUGG_SERV, reportData.weightG, &reportData.totalServ);
	calculateCostPerServing(&reportData.price, &reportData.totalServ, &reportData.costPerServ);
	
	const double totalCals = reportData.calPerServ * reportData.totalServ;
	calculateCostPerCal(&reportData.price, &totalCals, &reportData.costPerCal);

	return reportData;
}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("Analysis Report (Note: Serving = %dg)\n", SUGG_SERV);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest) {
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", 
		reportData.sku,
		reportData.price,
		reportData.weightLbs,
		reportData.weightKg,
		reportData.weightG,
		reportData.calPerServ,
		reportData.totalServ,
		reportData.costPerServ,
		reportData.costPerCal
	);

	if (isCheapest) {
		printf(" ***");
	}
	printf("\n");
}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo) {
	printf("Final Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", catFoodInfo.sku, catFoodInfo.price);
	printf("\n");
	printf("Happy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start() {
	struct CatFoodInfo catFoods[MAX_NUM_PRODS];
	struct ReportData reportData[MAX_NUM_PRODS];
	double minCostPerServ = -1;
	int cheapestIndex = 0;
	int i = 0;

	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		catFoods[i].sku = 0;
		catFoods[i].price = 0;
		catFoods[i].calPerServ = 0;
		catFoods[i].weight = 0;

		reportData[i].sku = 0;
		reportData[i].price = 0;
		reportData[i].calPerServ = 0;
		reportData[i].weightLbs = 0;
		reportData[i].weightKg = 0;
		reportData[i].weightG = 0;
		reportData[i].totalServ = 0;
		reportData[i].costPerServ = 0;
		reportData[i].costPerCal = 0;
	}

	openingMessage(MAX_NUM_PRODS);
	printf("\n");

	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		catFoods[i] = getCatFoodInfo(i + 1);
		reportData[i] = calculateReportData(catFoods[i]);

		if (minCostPerServ == -1 || reportData[i].costPerServ < minCostPerServ) {
			minCostPerServ = reportData[i].costPerServ;
			cheapestIndex = i;
		}
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

	displayReportHeader();
	for (i = 0; i < MAX_NUM_PRODS; ++i) {
		displayReportData(reportData[i], i == cheapestIndex);
	}

	printf("\n");
	displayFinalAnalysis(catFoods[cheapestIndex]);
	printf("\n");
}
