#include <iostream>

int main() {

    int a = 5;
    int &b = a; // Reference to variable a
    int &&c = std::move(a); // Rvalue reference initialized with std::move

    std::cout << a << " " << b << " " << c <<"\n";

    c= 42;
    std::cout << a << " " << b << " " << c <<"\n";


    return 0;
}
