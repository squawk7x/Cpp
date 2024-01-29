#include <stdio.h>

int main()
{

    int x = 42;
    int *px = &x;

    printf("x: %d\n", x);
    printf("&x: %p\n", &x);
    printf("sizeof x: %ld\n", sizeof(x));
    printf("px: %p\n", px);
    printf("sizeof px: %ld\n", sizeof(px));
    printf("*px: %d\n", *px);

    return 0;
}