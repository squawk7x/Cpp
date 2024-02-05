#include <iostream>

using namespace std;

// Simplified Definition
// lvalue: has an identifiable address in memory
// rvalue: is not a lvalue (temporary object)

// void setValue(int value){            // accepts lvalue and rvalue
// void setValue(int& value){           // & lvalue reference
//void setValue(int &&value) {          // && rvalue reference (since C11)
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
   *(v+2) = 4;  // v+2 is rvalue but *(v+2) is lvalue

   int b = 5;   // b is lvalue
   int &c = b; // c is a lvalue reference (reference)
   int && d = 6; // d is a rvalue reference
}