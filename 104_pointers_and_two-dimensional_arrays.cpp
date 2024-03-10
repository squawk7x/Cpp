#include <stdio.h>
#include <string.h>

// A STRING HAS TO BE TERMINATED BY '\0'

int main() {

    int B[2][3] = {{2, 3, 6}, {4, 5, 8}};
    // int* pB = B; //  Comilation error
    // B returns a pointer to a 1-D array of 3 integers

    printf("--------------------------\n");
    printf("B: %p\n", B); // B points to first array of 3 integers
    printf("&B: %p\n", &B);
    printf("*B: %p\n", *B);
    printf("sizeof B: %ld\n", sizeof(B));
    printf("--------------------------\n");

    printf("B[0]: %p\n", B[0]);
    printf("&B[0]: %p\n", &B[0]);
    printf("*B[0]: %d\n", *B[0]);
    printf("sizeof B[0]: %ld\n", sizeof(B[0]));
    printf("--------------------------\n");

    printf("B[0][0]: %d\n", B[0][0]);
    printf("&B[0][0]: %p\n", &B[0][0]);
    // printf("*B[0][0]: %d\n", (void *)B[0][0]);
    printf("sizeof B[0][0]: %ld\n", sizeof(B[0][0]));
    printf("--------------------------\n");

    printf("B+1: %p\n", B + 1);   // B+1 points to second array of 3 integers
    printf("&B[1]: %p\n", &B[1]); // B+1 points to second array of 3 integers
    printf("*(B+1): %p\n", *(B + 1));
    printf("B[1]: %p\n", B[1]);
    printf("&B[1][0]: %p\n", &B[1][0]);
    printf("--------------------------\n");

    printf("*(B+1)+2: %p\n", *(B + 1) + 2);
    printf("B[1]+2: %p\n", B[1] + 2);
    printf("&B[1][2]: %p\n", &B[1][2]);
    printf("--------------------------\n");

    int(*p)[3] = B;

    return 0;
}