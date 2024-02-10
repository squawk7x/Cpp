#include <iostream>

using namespace std;

// setValue function accepts a const reference to int
void setValue(const int &value) {
    printf("setValue: %d\n", value);
}

// printName function overloads for lvalues and rvalues
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
    int num = 10;

    // setValue function called with an lvalue (num)
    setValue(num); // called with lvalue;

    // setValue function called with an rvalue (literal)
    setValue(20);  // called with rvalue;

    // Strings and concatenation to create a full name
    std::string firstName = "fn";
    std::string lastName = "ln";
    std::string fullName = firstName + " " + lastName;

    // printName function called with lvalue string reference
    printName(fullName);

    // printName function called with rvalue string (temporary object)
    printName("another name");

    int v[3];
    *(v + 2) = 4; // v+2 is rvalue but *(v+2) is lvalue

    return 0;
}
