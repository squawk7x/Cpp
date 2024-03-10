#include <ctime>
#include <iostream>

// scope operation operator ::

int num = 3;

void printnum();

int main() {

    int num = 1;
    printnum();
    std::cout << ::num << "\n";

    return 0;
}

void printnum() {
    int num = 2;
    std::cout << ::num << "\n";
}