#include <iostream>
#include <stdio.h>
#include <typeinfo>

int main() {
    int a = 1025;

    int* pint;
    pint = &a;

    char* pchar;
    pchar = (char*)pint;

    *pchar = 5; // Assigning 5 to the least significant byte of 'a'

    // Printing the value of 'a' using both 'pint' and 'pchar'
    printf("a = %d\n", *pint);
    printf("a = %d\n", *pchar);

    // Printing the size of '*pint' and '*pchar'
    printf("size of *pint = %lu\n", sizeof(*pint)); // 'sizeof' returns 'size_t'
    printf("size of *pchar = %lu\n",
           sizeof(*pchar)); // 'sizeof' returns 'size_t'
    std::cout << "typeid *pint = " << typeid(*pint).name() << std::endl;
    std::cout << "typeid *pchar = " << typeid(*pchar).name() << std::endl;

    // Printing the size of 'pint' and 'pchar'
    printf("size of pint = %lu\n", sizeof(pint));   // 'sizeof' returns 'size_t'
    printf("size of pchar = %lu\n", sizeof(pchar)); // 'sizeof' returns 'size_t'
    std::cout << "typeid pint = " << typeid(pint).name() << std::endl;
    std::cout << "typeid pchar = " << typeid(pchar).name() << std::endl;

    return 0;
}
