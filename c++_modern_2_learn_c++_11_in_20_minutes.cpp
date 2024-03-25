//###################################################################
//  Learn C++ 11 in 20 minutes - 2
//###################################################################

#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * 9. override (for virtual function)
 */

/*
 * To avoid inadvertently create new function in derived classes.
 */

// C++ 03
// class Dog03 {
//     virtual void A(int);
//     virtual void B() const;
// };

// class Yellowdog03 : public Dog03 {
//     virtual void A(float); // no overwrite - Created a new function
//     virtual void B();      // no overwrite - Created a new function
// };

// // C++ 11 new keyword 'override'
// class Dog11 {
//     virtual void A(int);
//     virtual void B() const;
//     void C();
// };

// class Yellowdog11 : public Dog11 {
//     // virtual void A(float) override; // Error: no function to override
//     // virtual void B() override;      // Error: no function to override
//     // void C() override;              // Error: not a virtual function
// };

/*
 * 10. final (for virtual function and for class)
 */

// class Dog final { // no class can be derived from Dog
// };

// class Dog {
//     virtual void bark() final; // No child of Dog can override bark()
// };

/*
 * 11. Compiler Generated Default Constructor
 */
// C++ 03:
// class Dog {
//     Dog(int age) {
//     }
// };

// // Dog d1; // Error: compiler will not generate the default constructor

// // C++ 11:
// class Dog {
//     Dog(int age);
//     Dog() = default; // Force compiler to generate the default constructor
// };

/*
 * 12. delete
 */

// // C++ 03:
// class Dog03 {
// public:
//     Dog03(int age) {
//     }
// };

// // C++ 11:
// class Dog11 {
// public:
//     Dog11() = default;
//     Dog11(int age) {
//     }
//     Dog11(double) = delete;
//     Dog11 &operator= (const Dog11 &) = delete;
// };

// int main() {
//     Dog11 a;
//     Dog11 b(2);
//     // Dog11 c(3.0); // 3.0 is converted from double to int
//     // a = b;        // Compiler generated assignment operator
// }

/*
 * 13. constexpr
 */

// #include <iostream>
// #include <string>
// using namespace std;

// int A() {
//     return 3;
// }

// constexpr int B() {
//     return 3;
// }

// Write faster program with constexpr  // computed at compile time
// constexpr int cubed(int x) {
//     return x * x * x;
// }

// int main(int argc, char *argv[]) {
//     int arrA[6]; //OK
//     // int arr[A() + 3]; // Compile Error

//     // C++ 11
//     // Forces the computation to happen at compile time.

//     int arrB[B() + 3]; // Create an array of size 6

//     int y = cubed(1789); // computed at compile time

//     //Function cubed() is:
//     //1. Super fast. It will not consume run-time cycles
//     //2. Super small. It will not occupy space in binary.

//     cout << y << endl;

//     return 0;
// }

/*
 * 14. New String Literals
 */

// #include <iostream>
// #include <string>
// using namespace std;

// int main(int argc, char *argv[]) {
//     // C++ 03:
//     char* a = "string";

//     // C++ 11:
//     char* b = u8"string";     // to define an UTF-8 string.
//     char16_t* c = u"string";  // to define an UTF-16 string.
//     char32_t* d = U"string";  // to define an UTF-32 string.
//     char* e = R"(string \\)"; // to define raw string.

//     return 0;
// }

/*
 * 15. lambda function
 */

template <typename func>
void filter(func f, vector<int> arr) {
    for (auto i : arr) {
        if (f(i))
            cout << i << " ";
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    cout << [](int x, int y) { return x + y; }(3, 4) << endl; // Output: 7
    auto f = [](int x, int y) { return x + y; };
    cout << f(3, 4) << endl; // Output: 7

    vector<int> v = {1, 2, 3, 4, 5, 6};
    filter([](int x) { return (x > 3); }, v);          // Output: 4 5 6
    filter([](int x) { return (x > 2 && x < 5); }, v); // Output: 3 4

    int y = 4;
    filter([&](int x) { return (x > y); }, v); // Output: 5 6
    // Note: [&] tells compiler that we want variable capture

    // Lambda function works almost like a language extention
    // template for_nth_item

    return 0;
}

/*
 * Variadic Template
 */

/*
 * A template that can take any number of template arguments of any type.
 * Both class and function templates can be variadic.
 */

// #include <iostream>
// #include <string>
// #include <vector>
// using namespace std;

// // Template class with variadic template parameters
// template <typename... Args>
// class BoTemplate;

// // Combination of variadic and non-variadic argument
// template <typename T, typename... Args>
// class BoTemplate<T, Args...>;

// // Define a default template argument
// template <typename T = int, typename... Args>
// class BoTemplate3;

// int main() {
//     BoTemplate<float> t1();                           // OK
//     BoTemplate<int, long, double, float> t2();        // OK
//     BoTemplate<int, vector<double>> t3();             // OK
//     BoTemplate<> t4();                                // OK

//     return 0;
// }

/*
 * Template Alias
 */
// template <class T> class Dog { /* ... */
// };
// template <class T> using DogVec = std::vector<T, Dog<T>>;

// DogVec<int> v; // Same as: std::vector<int, Dog<int>>

/*
 * decltype
 */

/*
 * It is equivalent of GNU typeof
 */

// #include <iostream>
// #include <string>
// #include <memory>

// using namespace std;

// // decltype turns out to be very useful for template generic programming
// // Declare a function foo()
// template <typename X, typename Y> X foo(X x, Y y) {
//     decltype(x + y) z;
// }

// // Combining auto and decltype to implement templates with trailing return type
// template <typename X, typename Y> auto goo(X x, Y y) -> decltype(x + y) {
//     return x + y;
// }

// // How about return type needs to use decltype?
// // template <typename X, typename Y>
// // decltype(x + y) goo(X x, Y y) { // Error: x & y are undefined
// //     return x + y;
// // }

// struct S {
//     double x;
// };

// int main(int argc, char *argv[]) {
//     decltype(foo(3, 4)) x1 = 10; //  type is const int&

//     decltype(S::x) x2; //  x2 is double

//     auto s = make_shared<S>();
//     decltype(s->x) x3; //  x3 is double

//     int i;
//     decltype(i) x4; //  x4 is int

//     float f;
//     decltype(i + f) x5; // x5 is float

//     return 0;
// }

/*
//  * Thread Memory Model
//  *
//  * Why people use thread?
//  * 1. Process multiple event stream
//  * 2. Take advantage of multiple cores.
//  *
//  *                 THE END
//  *
//  * Notes are downloadable from: boqian.weebly.com
//  */