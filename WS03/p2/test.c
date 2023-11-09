#include<stdio.h>

int main() {
    char test;
    printf(">");
    scanf(" %c", &test);
    printf("%d\n", test > 90);
}