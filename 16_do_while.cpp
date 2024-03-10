#include <cmath>
#include <iostream>

int main() {
    int number;
    do {
        std::cout << "enter positive number: ";
        std::cin >> number;

    } while (number < 0);

    std::cout << number;
    return 0;
}