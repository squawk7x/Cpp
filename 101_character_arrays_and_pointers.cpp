#include <stdio.h>
#include <string.h>

// A STRING HAS TO BE TERMINATED BY '\0'

void print(char *C)
{
    int i = 0;
    while (C[i] != '\0') // C[i] = *(C+i)
    {
        printf("%c", C[i]);
        i++;
    }
    printf("\n");
}

void print2(char *C)
{
    while (*C != '\0') // C[i] = *(C+i)
    {
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main()
{
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

    char D[] = "JOHN"; // automatic '\0'
    printf("%s\n", D);
    printf("size in bytes = %ld\n", sizeof(D));

    char E[5] = {'J', 'O', 'H', 'N', '\0'};
    printf("%s\n", E);
    printf("size in bytes = %ld\n", sizeof(E));

    // ARRAYS AND POINTERS ARE DIFFERENT TYPES
    // THAT ARE USED IN A SIMILIAR MANNER

    char c1[6] = "Hello";
    char *c2;
    c2 = c1; // here this assignment is valid
    printf("%s\n", c1);
    printf("%c\n", c2[1]);
    c2[0] = 'B';
    printf("%s\n", c1);

    // ARRAYS ARE PASSED TO FUNCTION BY REFERENCE

    char F[20] = "Hello";
    print(F);
    print2(F);

    return 0;
}