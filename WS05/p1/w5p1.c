/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P1)
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

#define MIN_YEAR 2012
#define MAX_YEAR 2022

int main(void) {
    const int JAN = 1, DEC = 12;

    printf("General Well-being Log\n");
    printf("======================\n");

    int year, month;
    int invalidYear, invalidMonth;
    char monthChar1, monthChar2, monthChar3;
    
    do {
        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &month);

        invalidYear = year < MIN_YEAR || year > MAX_YEAR;
        invalidMonth = month < JAN || month > DEC;

        if (invalidYear) {
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (invalidMonth) {
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (invalidYear || invalidMonth);

    printf("\n*** Log date set! ***\n\n");

    switch (month) {
        case 1:
            monthChar1 = 'J';
            monthChar2 = 'A';
            monthChar3 = 'N';
            break;
        
        case 2:
            monthChar1 = 'F';
            monthChar2 = 'E';
            monthChar3 = 'B';
            break;

        case 3:
            monthChar1 = 'M';
            monthChar2 = 'A';
            monthChar3 = 'R';
            break;
        
        case 4:
            monthChar1 = 'A';
            monthChar2 = 'P';
            monthChar3 = 'L';
            break;
        
        case 5:
            monthChar1 = 'M';
            monthChar2 = 'A';
            monthChar3 = 'Y';
            break;

        case 6:
            monthChar1 = 'J';
            monthChar2 = 'U';
            monthChar3 = 'N';
            break;

        case 7:
            monthChar1 = 'J';
            monthChar2 = 'U';
            monthChar3 = 'L';
            break;

        case 8:
            monthChar1 = 'A';
            monthChar2 = 'U';
            monthChar3 = 'G';
            break;

        case 9:
            monthChar1 = 'S';
            monthChar2 = 'E';
            monthChar3 = 'P';
            break;

        case 10:
            monthChar1 = 'O';
            monthChar2 = 'C';
            monthChar3 = 'T';
            break;

        case 11:
            monthChar1 = 'N';
            monthChar2 = 'O';
            monthChar3 = 'V';
            break;

        case 12:
            monthChar1 = 'D';
            monthChar2 = 'E';
            monthChar3 = 'C';
            break;
    }

    printf("Log starting date: %d-%c%c%c-%02d\n", year, monthChar1, monthChar2, monthChar3, 1);

    return 0;
}