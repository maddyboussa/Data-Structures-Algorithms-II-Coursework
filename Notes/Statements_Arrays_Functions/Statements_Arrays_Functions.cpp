// L01-ExampleCode
// Statement
// Array
// Function

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>


void IfStatement() {
    // if Statement 
    int a = -3;
    if (a > 3) {
        printf("a is larger than 3\n");
    }
    else {
        printf("a is not larger than 3\n");
    }
}

void ConditionalOperator() {
    // The Conditional Operator(?:)
    int a = -3;
    int b = a > 0 ? a : -a;//if a > 0, b = a, else b = -a.
    printf("b = %d\n", b);

    // The switch Statement
    switch (b) {
    case 1:
        printf("b is 1\n");
        break;
    case 2:
        printf("b is 2\n");
        break;
    case 3:
        printf("b is 3\n");
        break;
    default:
        printf("b is not 1, 2, or 3\n");
    }
}

void WhileLoop() {
    // while and do/while Loop
    int c = 4;
    while (c < 4) {
        c *= 2;
    }

    int d = 4;
    do {
        d *= 2;//execute at least once
    } while (d < 4);

    printf("c = %d, d = %d\n", c, d);
}

void ForLoop() {
    // for Loop
    for (int i = 0; i < 5; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < 3; i++) //Nested Loops
    {
        for (int j = 0; j < 3; j++)
        {
            printf("(%d %d) ", i, j);
        }
        printf("\n");
    }
}

// Array example
void Array() {
    // Array
    int array1[10];
    for (int i = 0; i < 10; i++) {
        array1[i] = i * 3;
    }
    // Print array1
    printf("array1:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", array1[i]);
    }
    printf("\n");

    int array2[] = { 1,3,5,7,9,2,4,6,8,10 };
    // Print array2
    printf("array2:");
    for (int i = 0; i < 10; i++) {
        printf(" %d", array2[i]);
    }
    printf("\n");

    int array3[3];
    for (int i = 0; i < 3; i++) {
        printf("Please enter the element (%d/3): ", i + 1);
        // could use scanf_s if the visual studio said "function may not be safe".
        // Receive input from the user. & means address. &array3[i] is the adress of array3[i] in the memory
        scanf("%d", &array3[i]);
    }
    // Print array3
    printf("array3:");
    for (int i = 0; i < 3; i++) {
        printf(" %d", array3[i]);
    }
    printf("\n");
}

// C/C++ string example
void Strings() {
    // C string by char array
    char className[] = "IGME-309";
    printf("size of className is %d\n", sizeof(className) / sizeof(char));
    printf("class name: %s\n", className);
    printf("The first character is % c\n", className[0]);


    // print alphabet
    char alphabet[100];
    for (int i = 0; i < 26; i++)
        alphabet[i] = 'A' + i;
    alphabet[26] = '\0';
    printf("Alpha beta: %s\n", alphabet);

    // C++ String
    std::string s = "This is a string.";
    printf("String: %s\n", s.c_str());
}

// 2D array example
void Array2D() {
    int array2D[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    printf("array2D:\n");

    // Print array2D
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", array2D[i][j]);
        }
        printf("\n");
    }
}

int sum(int value1, int value2) {
    return value1 + value2;
}

// function example
void Function() {
    int a = 2, b = 3;
    printf("%d + %d = %d\n", a, b, sum(a, b));
}

// ++a & a++ example
void Count() {
    int count = 0;
    printf("count++ = %d, count = %d\n", count++, count);
    count = 0;
    printf("++count = %d, count = %d\n", ++count, count);
}

int main()
{
    IfStatement();
    ConditionalOperator();
    WhileLoop();
    ForLoop();
    Array();
    Strings();
    Array2D();
    Function();
    Count();

    return 0;
}