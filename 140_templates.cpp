#include <iostream>

template <typename T> 
T mymax(T a, T b) {
    return b < a ? a : b;
}

int main() {
    int i1 = 43;
    int i2 = 77;
    std::cout << mymax(i1, i2) << std::endl;
    std::cout << mymax("hi", "Hello") << std::endl;
}