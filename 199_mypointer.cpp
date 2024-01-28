#include <stdio.h>


int main(){

    int x = 42;

    int *px = &x;
    printf("px: %p -> *px: %d\n",px, *px);
    printf("sizeof px: %d\n", sizeof(px));

    return 0;
}