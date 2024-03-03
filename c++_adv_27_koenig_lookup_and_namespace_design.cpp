//############################################################################
/*
 * Koenig Lookup
 */
//############################################################################

#include <iostream>
using namespace std;

// Example 1:
namespace A {

struct X {};

void g(X) {
    cout << " calling A::g() \n";
}

void g() {
    cout << " calling A::g() \n";
}
} // namespace A

// void g(X) {
//     cout << " calling A::g() \n";
// }

int main() {
    A::X x1;
    g(x1); // Koenig Lookup, or Argument Dependent Lookup (ADL)
    // g(); // Error
}

// Notes:
// 1. Remove A:: from A::g(x);
// 2. Add a global g(A::X);
// Argument Dependent Lookup (ADL)

// Example 2:
// class C {
// public:
//     struct Y {};
//     static void h(Y) {
//         cout << "calling C::h() \n";
//     }
// };

// int main() {
//     C::Y y;
//     C::h(y); // Error
// }

// Notes:
// Remove C::

// Example 3:
// namespace A {
// struct X {};
// void g(X) {
//     cout << " calling A::g() \n";
// }
// } // namespace A

// class B {
//     // public:
//     void g(A::X) {
//         cout << "calling B::g() \n";
//     }
// };

// class C : public B {
// public:
//     void j() {
//         A::X x;
//         g(x);
//     }
// };

// int main() {
//     C c;
//     c.j();
// }

// Notes:
// 1. Ambiguous call to g();
// 2. Change C to a class, no more ambiguity.
// 3. Derive C from B, move C::g() to B, still no ambiguity.

// Name hiding: namespace example

// namespace A {
// struct X {};
// void g(X) {
//     std::cout << " calling A::g() \n";
// }

// namespace C {
// void g() {
//     std::cout << "calling C:g() \n";
// }
// void j() {
//     //using A::g;
//     X x;
//     g(x);
// }
// } // namespace C
// } // namespace A

// int main() {
//     A::C::j();
// }

// Notes:
// 1. add using A::g;
// 2. change g(int) to g(X)

/*
 *  Name Lookup Sequence
 *
 *  With namespaces:
 *  current scope => next enclosed scope => ... => global scope 
 *
 *  To override the sequence:
 *  1. Qualifier or using declaration
 *  2. Koenig lookup
 *
 *  With classes:
 *  current class scope => parent scope => ... => global scope
 *
 *  To override the sequence:
 *   - Qualifier or using declaration
 *
 *
 *  Name hiding
 */

/*
 * Why Koenig Lookup?
 */

// Example 1:
// namespace A {
// struct X {};
// void g(X) {
//     cout << " calling A::g() \n";
// }
// void g() {
//     cout << " calling A::g() \n";
// }
// } // namespace A

// int main() {
//     A::X x1;
//     g(x1); // Koenig Lookup, or Argument Dependent Lookup (ADL)
//     // g();   // Error
//     A::g();   // Error
// }

/*
 * 1. The Practical Reason
 */

// int main(int argc, char* argv[]) {
//     std::cout << "Hi.\n"; // calls std::operator<<
//     // std::cout std:: << "Hi.\n"; // calls std::operator<<
//     // std::operator<<(std : cout, "Hi,\n");

//     return 0;
// }

// Notes:
// std::cout std::<< "hello\n";
// std::operator<<(std::cout, "hello\n");

/*
 * 2. Theoretical Reason: 
 *       -- What is the interface of a class?
 */

// namespace A {
// class C {
// public:
//     // void f() = 0;
//     // void g() = 0;
//     virtual void f() = 0;
//     virtual void g() = 0;
// };
// void h(C);
// ostream& operator<<(ostream&, const C&);
// } // namespace A

/*
 * Definition of class: 
 * 	A class describes a set of data, along with the functions that operate 
 * 	on that data.
 */

//Note:
//1. void h(C);
//2. ostream& operator<<( ostream&, const C& );
//3. void j(C);

/* 
 * Engineering Principle: 
 * 1. Functions that operate on class C and in a same namespace with C are 
 *    part of C's interface.
 * 2. Functions that are part of C's interface should be in the same namespace
 *    as C.
 */

// A::C c;
// c.f();
// h(c);

// namespace A {
// class C {};
// int operator+(int n, A::C) {
//     return n + 1;
// }
// } // namespace A

// int main() {
//     A::C arr[3];
//     std::accumulate(arr, arr + 3, 0); // return 3
// }

// // Defined in C++ standard library <numeric>
// namespace std {
// template <class InputIterator, class T>
// T accumulate(InputIterator first, InputIterator last, T init) {
//     while (first != last)
//         init = init + *first++;
//     return init;
// }
// } // namespace std
