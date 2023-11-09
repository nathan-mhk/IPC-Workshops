/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #7 (P1)
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

#define MIN_NUM_LIVES 1
#define MAX_NUM_LIVES 10

#define MIN_PATH_LEN 10
#define MAX_PATH_LEN 70
#define PATH_LEN_MUL 5
#define MAX_PATH_PER 0.75

#include <stdio.h>

int main(void) {
    int i = 0, j = 0;
    int bombs[35];

    printf("BOMB Placement\n");
    printf("--------------\n");

    for (i = 0; i < 35; i += PATH_LEN_MUL) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_LEN_MUL);

        for (j = 0; j < PATH_LEN_MUL; ++j) {
            scanf("%d", &bombs[i + j]);
        }
    }

    printf("\n");

    for (i = 0; i < 35; i += PATH_LEN_MUL) {
        printf("   Positions [%2d-%2d]: ", i + 1, i + PATH_LEN_MUL);

        for (j = 0; j < PATH_LEN_MUL; ++j) {
            printf("%d ", bombs[i + j]);
        }
        printf("\n");
    }

    return 0;
}
