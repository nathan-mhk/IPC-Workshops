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

// ----------------------------------------------------------------------------
// macros
#define MAX_NUM_PRODS 3
#define SUGG_SERV 64


// ----------------------------------------------------------------------------
// structures
struct CatFoodInfo {
    int sku;
    double price;
    int calPerServ;
    double weight;
};


// ----------------------------------------------------------------------------
// function prototypes

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

// 7. Logic entry point
void start();
