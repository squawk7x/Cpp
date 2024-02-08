#include <iostream>

using namespace std;

// Simplified Definition
// lvalue: has an identifiable address in memory
// rvalue: is not a lvalue (temporary object)

// void setValue(int value){            // accepts lvalue and rvalue
// void setValue(int& value){           // & lvalue reference
// void setValue(int &&value) {         // && rvalue reference (since C11)
void setValue(const int &value) { // accepts lvalue and rvalue
    printf("setValue: %d\n", value);
}

/*
void printName(string name) {
    printf("[lvalue - string&] %s\n", name.c_str());
}
*/

void printName(string &name) {
    printf("[lvalue - string&] %s\n", name.c_str());
}

void printName(const string &name) {
    printf("[const string&] %s\n", name.c_str());
}

void printName(string &&name) {
    printf("[rvalue - string&&] %s\n", name.c_str());
}

int main() {
    int a = 10;

    setValue(a);  // called with lvalue;
    setValue(20); // called with rvalue;

    string firstName = "fn";
    string lastName = "ln";
    string fullName = firstName + " " + lastName;

    printName(fullName);
    printName("another name");

    int v[3];
    // v+2 = 1;  //error
    *(v + 2) = 4; // v+2 is rvalue but *(v+2) is lvalue

    int b = 5;              // b is lvalue
    int &c = b;             // c is a lvalue reference (reference)
    int &&d = std::move(b); // d is a rvalue reference

    std::cout << b << " " << c << " " << d << "\n";

    d = 42;
    std::cout << b << " " << c << " " << d << "\n";

    /*
    PERFECT FORWARDING

    Reference Collapsing Rules (C++ 11)
    T& &    ==> T&
    T& &&   ==> T&
    T&& &   ==> T&
    T&& &&  ==> T&&

    template< typename> T >
    void func (T&& arg) {...}    func can take any type of argument
 
    UNIVERSAL REFERENCE !!!
    rvalue, lvalue, const, non-const, etc.

    Conditions:
    1. T is a template type.
    2. Type deduction (reference collapsing) happens to T.
    3. T is a function template type, not class template type.

    MOVE <--> FORWARD
    std::move() vs std::forward()
    std::move<T>(arg);      // Turns arg into rvalue type
    std::forward<T>(arg);   // Turns rvalue into type of T&&
    */