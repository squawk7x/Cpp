/* 
 * Note 1: the most useful place for rvalue reference is overloading copy 
 * constructor and copy assignment operator, to achieve move semantics.
 *
 * X& X::operator=(X const & rhs);  // copy assignment operator
 * X& X::operator=(X&& rhs);        // move assignment operator
 * 
 * Note 2: Move semantics is implemented for all STL containers, which means:
 *    a. Move to C++ 11, Your code will be faster without changing a thing.
 *    b. Passing by value can be used for STL containers.
 *
*/

/* Move constructor/Move assignment operator:
 *    Purpose: avoid costly and unnecessary deep copying.

 * 1. Move constructor is particularly powerful where passing by reference and 
 *    passing by value are both needed.
 * 
 * 2. Move constructor give you finer control of which part of your object to 
 *    be moved.
 */

// #include <iostream>
// #include <string>

// /*
//  * Function Signature:
//  *
//  *    int and int& are indistinguishable.
//  *    int and int&& are indistinguishable.
//  *
//  *    int& and int&& are distinguishable.
//  */

// // parameter overloading by lvalue / rvalue
// void printInt(int &i) {
//     std::cout << "Called with lvalue: " << i << std::endl;
// }

// void printInt(int &&i) {
//     std::cout << "Called with rvalue: " << i << std::endl;
// }

// // void printInt(int i) {
// //     std::cout << "Called with lvalue: " << i << std::endl;
// // }

// int main() {
//     int a = 5;              // a is lvalue
//     int &b = a;             // b is a lvalue reference (reference)
//     int &&c = std::move(a); // c is a rvalue reference

//     printInt(a); // call printInt(int& i)
//     printInt(6); // call printInt(int&& i)
//     printInt(c);

//     return 0;
// }

#include <iostream>
#include <string>

class BoVector {
    int size;
    double* arr_;

public:
    // Copy constructor - deep copy
    BoVector(const BoVector& rhs) {
        size = rhs.size;
        arr_ = new double[size];
        for (int i = 0; i < size; i++) {
            arr_[i] = rhs.arr_[i];
        }
    }

    // Move constructor - shallow copy
    BoVector(BoVector&& rhs) {
        size = rhs.size;
        arr_ = rhs.arr_;
        rhs.arr_ = nullptr;
    }

    // Constructor with initializer_list
    BoVector(std::initializer_list<double> values)
        : size(values.size()), arr_(new double[size]) {
        int i = 0;
        for (auto value : values) {
            arr_[i++] = value;
        }
    }

    ~BoVector() {
        delete[] arr_;
    }
};

// void foo(BoVector v);
void foo(BoVector v){};

void foo_by_reference(BoVector& v){};

BoVector createBoVector() { // creates a BoVector
    BoVector bv{1, 2, 3};
    return bv;
}

int main() {
    // copy
    BoVector reusable = createBoVector(); // lvalue

    // Call no constructor
    foo_by_reference(reusable);

    // Call copy constructor
    foo(reusable); // returns  // reusable still exists

    // Call move constructor
    foo(std::move(reusable)); // reusable.arr_ == nullptr
    // reusable destroyed

    return 0;
}