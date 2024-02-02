#include <stdio.h>
#include <iostream>
#include <typeinfo>

int sumOfElements(int *arr) {
    printf("sizeof A = %lu\n", sizeof(&arr));
    return 0;
}

int main() {
    int A[5] = {2, 4, 5, 8, 1};

    printf("sizeof A = %lu\n", sizeof(A));

    sumOfElements(A);

    return 0;
}
