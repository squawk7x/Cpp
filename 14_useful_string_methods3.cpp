#include <cmath>
#include <iostream>

int main() {
    std::string name;

    std::cout << "Enter name";
    std::getline(std::cin, name);

    name.clear();

    std::cout << "Welcome" << name;

    return 0;
}