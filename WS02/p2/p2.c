#include<stdio.h>

int main() {
    // float price1 = 17.96f, price3 = 17.98f;
    // double price2 = 17.96, price4 = 17.98;
    // printf("1. 17.96 = %f (as cents:%d)\n", price1, (int)(price1 * 100));
    // printf("2. 17.96 = %lf (as cents:%d)\n", price2, (int)(price2 * 100));
    // printf("3. 17.98 = %f (as cents:%d)\n", price3, (int)(price3 * 100));
    // printf("4. 17.98 = %lf (as cents:%d)\n", price4, (int)(price4 * 100));

    // int money = 7245; 
    // printf("1. $%.2lf\n", money / 100.0); 
    // printf("2. $%.2lf\n", money / (double)100); 
    // printf("3. $%.2lf\n", (double)money / 100); 

    int result, money = 7245; 
    
    result = money / 100;               // 72
    
    printf("1. $%.2lf\n", money / 100); // 72 -> double
    printf("2. $%d\n", money / 100);    // 72 -> decimal
    printf("3. $%.2lf\n", result);      // 72 -> double
    printf("4. $%d\n", result);         // 72 -> decimal
    printf("%d\n", money / 100.0);

    return 0;
}