#include <iostream>
// This is comment
/*another comment*/

int func(int a, int b) {
    while (a < 10) {
        a++;
        ++b;
    }
    return a + b;
}

int main() {
    int x = 1;
    int y = 2;

    std::cout << "I love Pizza!" << std::endl;
    std::cout << "this is Really good!"
              << "\n";
    std::cout << "try it!\n";
    std::cout << func(x, y) << std::endl;

    return 0;
}