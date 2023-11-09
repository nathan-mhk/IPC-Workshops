/*
*****************************************************************************
                          Workshop - #4 (P2)
Full Name  : Nathan Kong
Student ID#: 150950236
Email      : nkong@myseneca.ca
Section    : NDD

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main(void)
{
    const char* const GRCRY_NAME[] = {"APPLES", "ORANGES", "PEARS", "TOMATOES", "CABBAGES"};
    const char* const GRCRY_NAME_LOWER[] = {"apples", "oranges", "pears", "tomatoes", "cabbages"};
    const char* const GRCRY_NAME_PLRL[] = {"APPLE(S)", "ORANGE(S)", "PEAR(S)", "TOMATO(ES)", "CABBAGE(S)"};

    const int NUM_GRCRY = sizeof(GRCRY_NAME) / sizeof(GRCRY_NAME[0]);
    int numItems[NUM_GRCRY];

    int shopAgain = 0;
    int i;

    do {
        printf("Grocery Shopping\n");
        printf("================\n");

        // Grocery shopping
        for (i = 0; i < NUM_GRCRY; ++i) {
            do {
                printf("How many %s do you need? : ", GRCRY_NAME[i]);
                scanf(" %d", &numItems[i]);

                if (numItems[i] < 0)
                    printf("ERROR: Value must be 0 or more.\n");

            } while (numItems[i] < 0);
            printf("\n");
        }

        // Pick the products
        printf("--------------------------\n");
        printf("Time to pick the products!\n");
        printf("--------------------------\n\n");

        for (i = 0; i < NUM_GRCRY; ++i) {

            // Skipping items w/ 0 qty
            while (numItems[i] > 0) {

                int pickCount = 0;
                printf("Pick some %s... how many did you pick? : ", GRCRY_NAME[i]);
                scanf(" %d", &pickCount);

                if (pickCount <= 0) {
                    printf("ERROR: You must pick at least 1!\n");
                    continue;
                }

                if (pickCount > numItems[i]) {
                    printf("You picked too many... only %d more %s are needed.\n", numItems[i], GRCRY_NAME_PLRL[i]);
                    continue;
                }

                // pickCount <= numItems
                numItems[i] -= pickCount;

                if (numItems[i] > 0)
                    printf("Looks like we still need some %s...\n", GRCRY_NAME[i]);
                else
                    // numItems[i] == 0
                    printf("Great, that's the %s done!\n\n", GRCRY_NAME_LOWER[i]);
            }
        }

        printf("All the items are picked!\n\n");
        printf("Do another shopping? (0=NO): ");
        scanf(" %d", &shopAgain);
        printf("\n");

    } while (shopAgain);

    printf("Your tasks are done for today - enjoy your free time!\n");

    return 0;
}