#include<stdio.h>

int main() {
    // const char* const GRC_NAME[] = {"APPLES", "ORANGES", "PEARS", "TOMATOES", "CABBAGES"};
    // int size = sizeof(GRC_NAME) / sizeof(GRC_NAME[0]);
    // printf("size: [%d]\n\n", size);
    // return 0;

    char choice;
    double cost;

    printf("Enter your selection (a, b or c) ? ");
    scanf("%c", &choice);

    switch (choice)
    {
    case 'A' :
    case 'a' :
        cost = 1.50;
        break;
    case 'B' :
    case 'b' :
        cost = 1.10;
        break;
    case 'C' :
    case 'c' :
        cost = 0.75;
        break;
    default:
        choice = '?';
        cost = 0.0;
    }

    printf("%c costs %.2lf\n", choice, cost);

    return 0;
}