/*
PERFECT FORWARDING
1. no costly and unnecessary copy construction of boVector is made.
2. rvalue is forwarded as rvalue, and lvalue is forwarded as lvalue.
*/

#include <iostream>
#include <string>
#include <type_traits>

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

// // void foo(BoVector arg);
void foo(BoVector arg){};

BoVector createBoVector() { // creates a BoVector
    BoVector bv{1, 2, 3};
    return bv;
}

// T&& - Universal Reference
template <typename T>
void relay(T&& arg) { // Universal Reference, works for lvalues and rvalues
    foo(std::forward<T>(arg)); // argument forwarding
}

/*
    Reference Collapsing Rules (C++ 11)
    T& &    ==> T&
    T& &&   ==> T&
    T&& &   ==> T&
    T&& &&  ==> T&&

    template< typename> T >
    void func (T&& arg) {...}    func can take any type of argument

    if arg is initialized with rvalue ==> T&& arg is rvalue reference
    func(9); => T = int&& => T&& = int&& && = int&&
    if arg is initialized with lvalue ==> T&& arg is lvalue reference
    func(x); => T = int& => T&& = int& && = int&

    UNIVERSAL REFERENCE !!! (Scott Meyer)
    rvalue, lvalue, const, non-const, etc.

    Conditions:
    1. T is a template type. 
    2. Type deduction (reference collapsing) happens to T.
       - T is a function template type, not class template type.
*/

int main() {
    BoVector reusable = createBoVector();

    relay(reusable);
    relay(createBoVector());
}

/*
            MOVE <----------------------> FORWARD
    std::move<T>(arg);              std::forward<T>(arg);
    Turns arg into rvalue type      Turns rvalue into type of T&&
*/

/*
Summary:
Usage of rvalue reference:
1. Move semantics
2. Perfect forwarding
*/