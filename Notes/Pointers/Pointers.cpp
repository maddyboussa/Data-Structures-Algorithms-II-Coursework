// L01-ExampleCode
// Pointerand Memory

#include <stdio.h>
#include <iostream>

// pointer
void Example1() {
    int i_var;
    double d_var;
    char c_var;

    int* i_ptr;
    double* d_ptr;
    char* c_ptr;

    i_var = 16;
    d_var = 3.14;
    c_var = 'a';

    i_ptr = &i_var;
    d_ptr = &d_var;
    c_ptr = &c_var;

    printf("%d %d\n", i_var, *i_ptr);
    printf("%.2lf %.2lf\n", d_var, *d_ptr);
    printf("%c %c\n", c_var, *c_ptr);
}


void ValFunc(int arg1)
{
    arg1 = arg1 + 1;
}

void RefFunc(int* arg1_ptr) {
    *arg1_ptr = *arg1_ptr + 1;
}

void RefFuncCPP(int& arg1_ptr) {
    arg1_ptr = arg1_ptr + 1;
}

// Pointer in Function as Reference
void Example2() {
    int arg = 1;

    ValFunc(arg);
    printf("After ValFunc, arg = %d\n", arg);

    RefFunc(&arg);
    printf("After RefFunc, arg = %d\n", arg);

    RefFuncCPP(arg);
    printf("After RefFuncCPP, arg = %d\n", arg);
}



void PrintArray(int* array, int length) { // pass the starting address of the array, and the length
    for (int i = 0; i < length; i++)
        printf("%d ", *(array + i));
    printf("\n");
}

void PrintArray2(int array[], int length) {
    for (int i = length - 1; i >= 0; i--)
        printf("%d ", *(array + i));
    printf("\n");
}

// pointer and Array
void Example3() {
    int values[100]; // create the array;
    for (int i = 0; i < 100; i++)
        values[i] = i;

    PrintArray(values, 100);
    PrintArray2(values, 100);
}

// Dynamic Allocate Memory
void Example4() {
    int* i_ptr = new int;
    *i_ptr = 10;

    float* f_ptr = new float(12.0f);

    printf("%d, %.2f\n", *i_ptr, *f_ptr);

    char* c_ptr = new char[*i_ptr];
    strcpy_s(c_ptr, *i_ptr, "IGME-209"); // copy IGME-209 into the memory c_ptr pointing to
    printf("%s\n", c_ptr);
}

// delete / free memory by pointer
void Example5() {
    int* i_ptr = new int(100);
    int* i_array_ptr = new int[100];
    for (int i = 0; i < 100; i++) {
        *i_array_ptr = i;
    }

    printf("%d\n", *i_ptr);

    // delete and free the memory
    delete i_ptr;
    delete[] i_array_ptr;

    // don't do this!
    // printf("%d\n", *i_ptr);
}


int* Memory_Stack() {
    int i_array[100];
    for (int i = 0; i < 100; i++)
        i_array[i] = i;
    return i_array;
}

int* Memory_Heap() {
    int* i_array = new int[100];
    for (int i = 0; i < 100; i++)
        i_array[i] = i;
    return i_array;
}

// memory in stack and heap
void Example6() {
    int* i_array = Memory_Stack(); // memory in stack
    for (int i = 0; i < 100; i++)
        printf("%d ", *(i_array + i)); // unsafe!
    printf("\n");

    int* i_array_2 = Memory_Heap(); // memory in heap
    for (int i = 0; i < 100; i++)
        printf("%d ", *(i_array_2 + i));
    printf("\n");
}

int main()
{
    Example1();
    Example2();
    Example3();
    Example4();
    Example5();
    Example6();
    return 0;
}