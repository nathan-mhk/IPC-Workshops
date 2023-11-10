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


// ----------------------------------------------------------------------------
// defines/macros
#define MAX_NUM_PRODS 3
#define SUGG_SERV 64
#define LBS_IN_KG 2.20462

// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    int calPerServ;
    double weight;
};

struct ReportData {
    int sku;
    double price;
    int calPerServ;
    double weightLbs;
    double weightKg;
    int weightG;
    double totalServ;
    double costPerServ;
    double costPerCal;
};


// ----------------------------------------------------------------------------
// function prototypes

// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* intPtr);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* dblPtr);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int numProds);

// 4. Get user input for the details of cat food product
struct CatFoodInfo getCatFoodInfo(const int seqNum);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(
    const int sku, 
    const double* const price, 
    const int calPerServ, 
    const double* const weight
);

// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double* const lbs, double* kg);

// 9. convert lbs: g
int convertLbsG(const double* const lbs, int* g);

// 10. convert lbs: kg / g
void convertLbs(const double* const lbs, double* kg, int* g);

// 11. calculate: servings based on gPerServ
double calculateServings(const int gPerServ, const int totalG, double* numServ);

// 12. calculate: cost per serving
double calculateCostPerServing(
    const double* const price,
    const double* const totalNumServ,
    double* costPerServ
);

// 13. calculate: cost per calorie
double calculateCostPerCal(
    const double* const price,
    const double* const totalCals,
    double* costPerCal
);

// 14. Derive a reporting detail record based on the cat food product data
struct ReportData calculateReportData(const struct CatFoodInfo catFoodInfo);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const struct ReportData reportData, const int isCheapest);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const struct CatFoodInfo catFoodInfo);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start();
