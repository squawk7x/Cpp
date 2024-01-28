#include <stdio.h>
#include <string.h>

// A STRING HAS TO BE TERMINATED BY '\0'

int main(){
    char C[4];
    C[0] = 'J';
    C[1] = 'O';
    C[2] = 'H';
    C[3] = 'N';
    printf("%s\n", C);
    printf("length = %d\n", strlen(C));

    C[4] = '\0';
    printf("%s\n", C);
    printf("length = %d\n", strlen(C));

    char D[] = "JOHN";  // automatic '\0'
    printf("%s\n", D);
    printf("size in bytes = %ld\n", sizeof(D));

    char E[5] = {'J', 'O', 'H', 'N', '\0'}; 
    printf("%s\n", E);
    printf("size in bytes = %ld\n", sizeof(E));

    // ARRAYS AND POINTERS ARE DIFFERENT TYPES 
    // THAT ARE USED IN A SIMILIAR MANNER

    char c1[6] = "Hello";
    char *c2;
    c2 = c1;    // here this assignment is valid
    printf("%s\n", c1);
    printf("%c\n", c2[1]);
    c2[0] = 'B'; 
    printf("%s\n", c1);





    return 0;
}