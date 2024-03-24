#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

void innerFunction(int& val) {
    cout << "innerFunction with lvalue = " << val << endl;
}

void innerFunction(int&& val) {
    cout << "innerFunction with rvalue = " << val << endl;
}

template <typename T>
void wrapper(T&& arg) {
    innerFunction(std::forward<T>(arg));
}

int main() {
    int x = 5;
    wrapper(x); // Calls innerFunction(int&)
    wrapper(10); // Calls innerFunction(int&&)
    
    return 0;
}