// L01-ExampleCode
// Data types
// Operators

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	printf("Have Fun!\n");

	// size of Data type
	printf("The size of int is %d\n", sizeof(int));
	printf("The size of short is %d\n", sizeof(short));
	printf("The size of long is %d\n", sizeof(long)); // long or long long in different system / C version.

	printf("The size of float is %d\n", sizeof(float));
	printf("The size of double is %d\n", sizeof(double));

	printf("The size of char is %d\n", sizeof(char));

	// operations
	int a = 10;
	int b = a - 3;
	printf("a = %d, b = %d\n", a, b);
	printf("a + b = %d\n", a + b);
	printf("a - b = %d\n", a - b);
	printf("a * b = %d\n", a * b);
	printf("a / b = %d\n", a / b);
	printf("a %% b = %d\n", a % b); // use %% to print %, why?

	// char data type, ASCII number
	char c = 'A';
	printf("The character in variable a is %c.\n", c);
	printf("The corresponding ASCII number is %d.\n", c);

	// boolean
	printf("Is 10 > 9? %d\n", 10 > 9);

	// casting
	int total = 5, count = 2;
	double average = total / count;
	printf("average = %.2lf, incorrect\n", average);

	average = (double)(total) / count;
	printf("average = %.2lf, correct\n", average);

	return 0;
}