#include <stdio.h>

void increment_by_value(int a) {
    a = a + 1;
    printf("address of variable a in increment_by_value = %p\n", &a);
}

void increment_by_reference(int *pa) {
    *pa = *pa + 1;
    printf("address of variable a in increment_by_reference = %p\n", &*pa);
}

int sumOfElements(int B[], int size) {
    int i, sum = 0;
    // int size = sizeof(B) / sizeof(B[0]);
    // with array as argument is call by reference !!!
    // A[] interpreted as int *B (pointer to integer)
    printf("sumOfElements: size of B = %ld, size of B[0] = %ld\n", sizeof(B),
           sizeof(B[0]));
    for (i = 0; i < size; i++) {
        sum += B[i]; // B[i] = *(B+i)
    }

    return sum;
}

void doubleElements(int *B, int size) {
    int i, sum = 0;
    for (i = 0; i < size; i++) {
        B[i] = 2 * B[i];
    }
}

int main() {
    int a = 1025;
    int *p;
    p = &a;

    // POINTER ARITHMETIC

    printf("address where p points to is %p\n", p);
    printf("value at adress p is %d\n", *p);
    printf("size of interger is %ld bytes\n", sizeof(int));
    printf("address where p+1 points to is %p\n", p + 1);
    printf("value at adress p+1 is %d\n", *(p + 1));

    printf("size of integer is %ld byte(s)\n", sizeof(int));
    printf("address int pointer = %p, value = %d\n", p, *p);
    printf("address +1 = %p, value  = %d\n", p + 1, *(p + 1));

    // TYPE CASTING
    char *p0;
    p0 = (char *)p;

    printf("size of char is %ld byte(s)\n", sizeof(char));
    printf("address char pointer = %p, value = %d\n", p0, *p0);
    printf("address +1 = %p, value  = %d\n", p0 + 1, *(p0 + 1));
    // 1025 = 00000000 00000000 00000100 00000001

    // VOID POINTER - GENERIC POINTER

    void *p1;
    p1 = p;
    printf("address void pointer = %p\n", p1); // *p1 = ... Compilation error
    // printf("address +1 = %p", p1+1); // p1+1 : Compilation error

    // POINTER TO ANOTHER POINTER

    int x = 5;
    int *px = &x;
    *px = 6;

    int **q = &px;
    int ***r = &q;

    printf("----------------------------\n");
    printf("*p = %d\n", *px);
    printf("*q = %p\n", *q);
    printf("*q = %d\n", **q);
    printf("**r = %p\n", **r);
    printf("***r = %d\n", ***r);
    ***r = 10;
    printf("x = %d\n", x);
    printf("----------------------------\n");

    // POINTERS AS FUNCTION ARGUMENTS - CALL BY REFERENCE

    printf("address of variable a in main = %p\n", &a);
    printf("value of a in main = %d\n", a);

    increment_by_value(a);
    printf("value of a in main after call by value = %d\n", a);

    increment_by_reference(&a);
    printf("value of a in main after call by reference = %d\n", a);

    // POINTERS AND ARRAYS
    int A[] = {2, 4, 5, 8, 1};
    int *pA = A;

    printf("%p\n", A); // A == &A[0]   !!!

    for (int i = 0; i < 5; i++) {
        printf("address = %p\n", &A[i]);
        printf("address = %p\n", A + i);
        printf("value = %d\n", A[i]);
        printf("value = %d\n", *(A + i));
    }

    // ARRAYS AS FUNCTION ARGUMENTS
    int B[] = {1, 2, 3, 4, 5};
    int size = sizeof(B) / sizeof(B[0]);
    int total = sumOfElements(B, size);
    printf("main: size of B = %ld, size of B[0] = %ld\n", sizeof(B),
           sizeof(B[0]));
    printf("sum of elements = %d\n", total);

    doubleElements(B, size);
    for (int i = 0; i < size; i++) {
        printf("%d ", B[i]);
    }

    return 0;
}
