#include <stdio.h>

// pointers can point to data 
// pointers can point to functions

int add(int a, int b){

    return a + b;
}

int main(){
    int c;
    int (*p)(int, int);
    p = &add;  // or p = add works as well
    c = (*p)(2,3);  // p(2,3) works as well
    printf("%d\n", c);
}

