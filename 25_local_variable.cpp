#include <ctime>
#include <iostream>

void printnum();

int main() {

    int num = 1;

    std::cout << num << "\n";

    printnum();

    return 0;
}

void printnum() {
    int num = 2;
    std::cout << num << "\n";
}