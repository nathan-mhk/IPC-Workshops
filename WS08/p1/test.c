#define _CRT_SECURE_NO_WARNINGS

// System Libraries
#include <stdio.h>
#define TEST_INT	24

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* integer) {
	int repeat = 0, val = 0;
	do {
		scanf("%d", &val);

		if (val > 0) {
			repeat = 0;
		} else {
			repeat = 1;
			printf("ERROR: Enter a positive value: ");
		}
	} while (repeat);

    // Prevent nullptr
    if (integer) {
        *integer = val;
    }
	return val;
}

int main() {
    int intA = 0, intB = 0;

    printf("TEST-1: ");
    intB = getIntPositive(&intA);
    if (intA == intB && intA == TEST_INT)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
	}

	//-----------------------------------
	// Test-2: return value only
	intA = intB = 0;
	printf("TEST-2: ");
	intA = getIntPositive(NULL);
	if (intA == TEST_INT)
	{
		printf("<PASSED>\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
	}

	//-----------------------------------
	// Test-3: argument only
	intA = intB = 0;
	printf("TEST-3: ");
	getIntPositive(&intA);
	if (intA == TEST_INT)
	{
		printf("<PASSED>\n\n");
	}
	else
	{
		printf("<!!! FAILED !!!>\n");
	}

    return 0;
}