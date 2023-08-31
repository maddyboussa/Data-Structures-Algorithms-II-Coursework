// L01-ExampleCode
// Input/Output

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
	int a1, a2;

	// Input
	printf("Input one integer:"); // consider using printf_s and scanf_s for safety reason
	scanf("%d", &a1);

	cout << "Input another integer:";
	cin >> a2;

	// Output
	printf("The first integer is %d.\n", a1);
	cout << "The second integer is " << a2 << "." << endl;

	return 0;
}