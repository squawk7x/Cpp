//############################################################################
// Understanding Rvalue and Lvalue
//############################################################################

#include <iostream>
#include <array>

using namespace std;

class dog {
    public:
    void bark(){}
};

int square(int& x) {
    return x * x;
}

int square(const int& x) {
    return x * x;
}

int square(int&& x) {
    return x * x;
}

int myglobal;

int& foo() {
    return myglobal;
}

// setValue function accepts a const reference to int
void setValue(const int& value) {
    printf("setValue: %d\n", value);
}

// printName function overloads for lvalues and rvalues
void printName(string& name) {
    printf("[lvalue - string&] %s\n", name.c_str());
}

void printName(const string& name) {
    printf("[const string&] %s\n", name.c_str());
}

void printName(string&& name) {
    printf("[rvalue - string&&] %s\n", name.c_str());
}

int main() {
    // Lvalue examples:
    int i;       // i is a lvalue because
    int* p = &i; // i's address is identifiable
    i = 2;       // Memory content is modified

    dog d1; // lvalue of user defined class
    // most variables in C++ code are lvalues

    // Rvalue examples:

    int x = 2; // 2 is a rvalue
    x = i + 2; // (i+2) is a rvalue
    // int p* = &(i + 2); // Error
    // i + 2 = 4;         // Error
    // 2 = i;             // Error
    d1 = dog();

    // Reference (or lvalue reference):
    int j;
    int& r = j;
    // int& r = 5; // Error
    const int& s = 5;

    // int square(int& x) {
    //     return x * x;
    // }

    square(x);
    // square(40); //Error

    // Workaround:
    // int square(const int& x)
    // int square(int&& x)

    /*
    lvalue can be used to create a rvalue
    */

    int k = 1;
    int z = k + 2;
    z = k;

    /*
    rvalue can be used to create a lvalue
    */
    int v[3];
    *(v + 2) = 4; // v+2 is rvalue but *(v+2) is lvalue

    /*
    Misconception 1: function or operator always yield rvalues
    */
    int l = i + 3;
    int y = square(5);
    // but:
    foo() = 50;

    // A more common example:
    int array[6];  // operator [] almost always generates lvalue
    array[3] = 50; // operator

    /*
    Misconception 2: lvalues are modifiable
    C++ <> C language: lvalue means "value suitable for left-hand-side assignment"
    */
    const int c = 1; // c is a lvalue
                     // c = 2;           //Error

    /*
    Misconception 3: rvalues are not modifiable
    */
    // i + 3 = 6; // Error
    // square(5) = 25; // Error
    // it is not true for user defined type (class):
    // but:
    dog().bark();// bark may change the state of the dog object.


    int num = 10;

    // setValue function called with an lvalue (num)
    setValue(num); // called with lvalue;

    // setValue function called with an rvalue (literal)
    setValue(20); // called with rvalue;

    // Strings and concatenation to create a full name
    std::string firstName = "fn";
    std::string lastName = "ln";
    std::string fullName = firstName + " " + lastName;

    // printName function called with lvalue string reference
    printName(fullName);

    // printName function called with rvalue string (temporary object)
    printName("another name");

    return 0;
}

/*
 * Summary:
 * 1. Every C++ expression yield either a rvalue or a lvalue.
 * 2. If the expression has an identifiable memory address, 
 *      it is a lvalue
 *      otherwise it is a rvalue.
*/