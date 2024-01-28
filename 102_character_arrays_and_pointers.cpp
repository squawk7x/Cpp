#include <stdio.h>
#include <string.h>

// A STRING HAS TO BE TERMINATED BY '\0'

void print(char *C)
{
    while (*C != '\0')
    {
        printf("%c", *C);
        C++;
    }
    printf("\n");
}

int main()
{
    char C[20] = "Hello";
    print(C);

    return 0;
}