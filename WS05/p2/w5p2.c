/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #5 (P2)
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
#define LOG_DAYS 3

int main(void) {
    const int JAN = 1, DEC = 12;

    int year, month, day;
    int invalidInput;
    char monthChar1, monthChar2, monthChar3;
    double morningRatingSum, eveningRatingSum;
    double morningRating, eveningRating;
    const double MIN_RATING = 0, MAX_RATING = 5.0;

    printf("General Well-being Log\n");
    printf("======================\n");
    
    do {
        invalidInput = 0;

        printf("Set the year and month for the well-being log (YYYY MM): ");
        scanf(" %d %d", &year, &month);

        if (year < MIN_YEAR || year > MAX_YEAR) {
            invalidInput = 1;
            printf("   ERROR: The year must be between %d and %d inclusive\n", MIN_YEAR, MAX_YEAR);
        }

        if (month < JAN || month > DEC) {
            invalidInput = 1;
            printf("   ERROR: Jan.(1) - Dec.(12)\n");
        }

    } while (invalidInput);

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

    for (day = 1; day <= LOG_DAYS; ++day) {
        printf("%d-%c%c%c-%02d\n", year, monthChar1, monthChar2, monthChar3, day);

        do {
            invalidInput = 0;

            printf("   Morning rating (%.1lf-%.1lf): ", MIN_RATING, MAX_RATING);
            scanf(" %lf", &morningRating);

            if (morningRating < MIN_RATING || morningRating > MAX_RATING) {
                invalidInput = 1;
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RATING, MAX_RATING);
            }
            
        } while (invalidInput);

        do {
            invalidInput = 0;
            
            printf("   Evening rating (%.1lf-%.1lf): ", MIN_RATING, MAX_RATING);
            scanf(" %lf", &eveningRating);

            if (eveningRating < MIN_RATING || eveningRating > MAX_RATING) {
                invalidInput = 1;
                printf("      ERROR: Rating must be between %.1lf and %.1lf inclusive!\n", MIN_RATING, MAX_RATING);
            }

        } while (invalidInput);

        morningRatingSum += morningRating;
        eveningRatingSum += eveningRating;

        printf("\n");
    }

    printf("Summary\n");
    printf("=======\n");
    printf("Morning total rating: %6.3lf\n", morningRatingSum);
    printf("Evening total rating: %6.3lf\n", eveningRatingSum);
    printf("----------------------------\n");
    printf("Overall total rating: %6.3lf\n", morningRatingSum + eveningRatingSum);
    printf("\n");
    printf("Average morning rating: %4.1lf\n", morningRatingSum / LOG_DAYS);
    printf("Average evening rating: %4.1lf\n", eveningRatingSum / LOG_DAYS);
    printf("----------------------------\n");
    printf("Average overall rating: %4.1lf\n", (morningRatingSum + eveningRatingSum) / (LOG_DAYS * 2));

    return 0;
}