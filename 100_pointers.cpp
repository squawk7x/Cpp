#include <stdio.h>

void increment_by_value(int a)
{
    a = a + 1;
    printf("address of variable a in increment_by_value = %p\n", &a);
}

void increment_by_reference(int *pa)
{
    *pa = *pa + 1;
    printf("address of variable a in increment_by_reference = %p\n", &*pa);
}

int main()
{
    /*
    int a = 5;
    int *p;
    p = &a;

    // POINTER ARITHMETIC

    printf("address where p points to is %p\n", p);
    printf("value at adress p is %d\n", *p);
    printf("size of interger is %ld bytes\n", sizeof(int));
    printf("address where p+1 points to is %p\n", p + 1);
    printf("value at adress p+1 is %d\n", *(p + 1));
    */

    /*
    int a = 1025;

    int *p; // pointers are stored in 4 bytes
    p = &a;

    printf("size of integer is %ld byte(s)\n", sizeof(int));
    printf("address int pointer = %p, value = %d\n", p, *p);
    printf("address +1 = %p, value  = %d\n", p+1, *(p+1));

    // TYPE CASTING
    char *p0;
    p0 = (char *)p;

    printf("size of char is %ld byte(s)\n", sizeof(char));
    printf("address char pointer = %p, value = %d\n", p0, *p0);
    printf("address +1 = %p, value  = %d\n", p0+1, *(p0+1));
    // 1025 = 00000000 00000000 00000100 00000001

    // VOID POINTER - GENERIC POINTER

    void *p1;
    p1 = p;
    printf("address void pointer = %p\n", p1);  // *p1 = ... Compilation error
    // printf("address +1 = %p", p1+1); // p1+1 : Compilation error

    // POINTER TO ANOTHER POINTER

    int x = 5;
    int *px = &x;
    *px = 6;

    int **q = &px;
    int ***r= &q;

    printf("----------------------------\n");
    printf("*p = %d\n", *px);
    printf("*q = %p\n", *q);
    printf("*q = %d\n", **q);
    printf("**r = %p\n", **r);
    printf("***r = %d\n", ***r);
    ***r = 10;
    printf("x = %d\n", x);
    printf("----------------------------\n");
    */

    // POINTERS AS FUNCTION ARGUMENTS - CALL BY REFERENCE

    int a = 10;

    printf("address of variable a in main = %p\n", &a);
    printf("value of a in main = %d\n", a);

    increment_by_value(a);
    printf("value of a in main after call by value = %d\n", a);

    increment_by_reference(&a);
    printf("value of a in main after call by reference = %d\n", a);

    return 0;
}
