#include <iostream>
#include <string>
using namespace std;

std::string lookup1() {
    return "Hello from lookup1";
}

std::string &lookup2() {
    static std::string str = "Hello from lookup2";
    return str;
}

std::string look_up_a_string_1() {
    return lookup1();
}

std::string &look_up_a_string_2() {
    return lookup2();
}

// from C++ 14:
// decltype(auto) look_up_a_string_1() {
//     return lookup1();
// }
// decltype(auto) look_up_a_string_2() {
//     return lookup2();
// }

int main(int argc, char *argv[]) {
    // Call the functions and print the results
    std::cout << "Result of lookup1(): " << lookup1() << std::endl;
    std::cout << "Result of lookup2(): " << lookup2() << std::endl;

    std::string str1 = look_up_a_string_1();
    std::string &str2 = look_up_a_string_2();

    std::cout << "Result of look_up_a_string_1(): " << str1 << std::endl;
    std::cout << "Result of look_up_a_string_2(): " << str2 << std::endl;

    // Modify the string returned by lookup2()
    str2 += " - Modified";
    std::cout << "Modified result of lookup2(): " << lookup2() << std::endl;

    return 0;
}
