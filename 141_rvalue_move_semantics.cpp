#include <iostream>
#include <string>

void printInt(int &i) {
    std::cout << "Called with lvalue: " << i << std::endl;
}

void printInt(int &&i) {
    std::cout << "Called with rvalue: " << i << std::endl;
}

// void printInt(int i) {
//     std::cout << "Called with lvalue: " << i << std::endl;
// }

int main() {
    int a = 5;              // a is lvalue
    int &b = a;             // b is a lvalue reference (reference)
    int &&c = std::move(a); // c is a rvalue reference

    printInt(a); // call printInt(int& i)
    printInt(6); // call printInt(int&& i)
    printInt(c);

    return 0;
}

/*

X &X::operator=(X const &rhs);
X &X::operator=(X &&rhs);
*/


