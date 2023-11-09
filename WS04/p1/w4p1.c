/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #4 (P1)
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

int main(void)
{
    char cmd = 0;
    int numItr = -1, itr = 0;
    printf("+----------------------+\n");
    printf("Loop application STARTED\n");
    printf("+----------------------+\n\n");

    while (1) {
        printf("D = do/while | W = while | F = for | Q = quit\n");
        printf("Enter loop type and the number of times to iterate (Quit=Q0): ");
        scanf(" %c%d", &cmd, &numItr);

        // Guard for `Q\d`
        if (cmd == 'Q'){
            if (!numItr)
                break;
            else {
                printf("ERROR: To quit, the number of iterations should be 0!\n\n");
                continue;
            }
        }

        // Guard for `cmd` value
        if (cmd != 'D' && cmd!= 'W' && cmd != 'F' && cmd != 'Q') {
            printf("ERROR: Invalid entered value(s)!\n\n");
            continue;
        }

        // Guard for `numItr` value
        if (numItr < 3 || numItr > 20) {
            printf("ERROR: The number of iterations must be between 3-20 inclusive!\n\n");
            continue;
        }

        switch (cmd) {
        case 'D':
            printf("DO-WHILE: ");

            do {
                printf("%c", cmd);
                ++itr;
            } while (itr < numItr);
            
            break;

        case 'W':
            printf("WHILE   : ");

            while (itr < numItr) {
                printf("%c", cmd);
                ++itr;
            }

            break;
        
        case 'F':
            printf("FOR     : ");

            for (; itr < numItr; ++itr)
                printf("%c", cmd);

            break;
        }
        printf("\n\n");
        itr = 0;
    }

    printf("\n");
    printf("+--------------------+\n");
    printf("Loop application ENDED\n");
    printf("+--------------------+\n");

    return 0;
}