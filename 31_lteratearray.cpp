#include <ctime>
#include <iomanip>
#include <iostream>

int main() {
    std ::string students[] = {"Patric", "Sandy", "spanbob", "asus"};

    for (int i = 0; i <= sizeof(students) / sizeof(std ::string); i++) {
        std::cout << students[i] << '\n';
    }
    return 0;
}