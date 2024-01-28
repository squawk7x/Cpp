#include <stdio.h>

int main()
{
    /*
    int a = 5;
    int *p;
    p = &a; 

    // POINTER ARITHMETIC

    printf("adress where p points to is %p\n", p);
    printf("value at adress p is %d\n", *p);
    printf("size of interger is %ld bytes\n", sizeof(int));
    printf("adress where p+1 points to is %p\n", p + 1);
    printf("value at adress p+1 is %d\n", *(p + 1));

    */
    int a = 1025;

    int *p;
    p = &a; 

    printf("size of integer is %ld byte(s)\n", sizeof(int));
    printf("address int pointer = %p, value = %d\n", p, *p);
    printf("address +1 = %p, value  = %d\n", p+1, *(p+1));

    char *p0;
    p0 = (char *)p;

    printf("size of char is %ld byte(s)\n", sizeof(char));
    printf("address char pointer = %p, value = %d\n", p0, *p0);
    printf("address +1 = %p, value  = %d\n", p0+1, *(p0+1));
    // 1025 = 00000000 00000000 00000100 00000001

    // void pointer - Generic pointer
    void *p1;
    p1 = p;
    printf("address void pointer = %p", p1);  // *p1 = ... Compilation error
    // printf("address +1 = %p", p1+1); // p1+1 : Compilation error



    return 0;
}

