#include <stdio.h>
#include <string.h>

// A STRING HAS TO BE TERMINATED BY '\0'

int main() {
    // int x = 10;
    // int *ptr = &x;               // Pointer to an integer

    int A[5] = {2, 4, 6, 8, 10}; // type int(*)[5]
    int* pA = A;                 // not &A,
    // A refers to address of first array element

    printf("A: %p\n", A);
    printf("&A: %p\n", &A);
    printf("sizeof A: %ld\n", sizeof(A));

    printf("pa: %p\n", pA);
    printf("*pa: %d\n", *pA);
    printf("pa+1: %p\n", pA + 1);
    printf("*(pa+1): %d\n", *(pA + 1));

    printf("A: %p\n", A);
    printf("*A: %d\n", *A);
    printf("A+1: %p\n", A + 1);       //   (A+i) same as &A[i]
    printf("*(A+1): %d\n", *(A + 1)); //  *(A+i) same as  A[i]

    return 0;
}