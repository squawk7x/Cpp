
// /*###################################################################
//  *                          Learn C++ 11
//  ###################################################################*/

/*
 * 1. Initializer List
 */

#include <iostream>
#include <vector>
#include <initializer_list>

using namespace std;

class BoVector {
    vector<int> m_vec;

public:
    // Define your own initializer_list constructor:
    BoVector(const initializer_list<int> &v) {
        for (initializer_list<int>::iterator itr = v.begin(); itr != v.end();
             ++itr)
            m_vec.push_back(*itr);
    }
};

class Rectangle {
public:
    Rectangle(int height, int width, int length) {
    }
};

void draw_rect(Rectangle r) {
    cout << "Rectangle was drawn." << endl;
};

int main() {
    //C++ 03 initializer list:
    int arr[4] = {3, 2, 4, 5};

    // vector not supported in C++ 03
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);

    // C++ 11 extended the support
    // All the relevant STL containers have been updated to accept initializer_list.
    vector<int> v2 = {3, 4, 1, 9}; // Calling initializer_list constructor

    BoVector v3 = {0, 2, 3, 4};
    BoVector v4{0, 2, 3, 4}; // effectively the same

    // Automatic normal Initialization
    draw_rect({5, 6, 9}); // Rectangle{5,6,9} is automatically called
}

// Note: use it with caution.
// 1. Not very readable, even with the help of IDE.
//    Funcion name rarely indicates the type of parameter the function takes.
// 2. Function could be overloaded with differenct parameter types.

/*
 * 2. Uniform Initialization
 */

// #include <iostream>
// #include <initializer_list>

// using namespace std;

// // C++ 03
// class Dog3 { // Aggregate class or struct
// public:      // members must be public
//     int age;
//     string name;
// };

// class Dog11_1 {
// public:
//     Dog11_1(int age, string name){};
// };

// class Dog11_2 {
// public:
//     int age; // 3rd choice - Aggregat Initializer

//     Dog11_2(int a) { // 2nd choice - Regular Constructor
//         age = a;
//     }

//     Dog11_2(const initializer_list<int> &vec) { // 1st choice - Initializer_list
//         age = *(vec.begin());
//         cout << "created with initializer_list" << endl;
//     }
// };

// int main() {
//     Dog3 d3 = {5, "Henry"}; // Aggregate Initialization

//     // C++ 11 extended the scope of curly brace initialization
//     Dog11_1 d11_1 = {5, "Henry"};

//     /* Uniform Initialization Search Order:
//  * 1. Initializer_list constructor
//  * 2. Regular constructor that takes the appropriate parameters.
//  * 3. Aggregate initializer.
//  */
//     Dog11_2 d11_2{3};
// }

/*
 * 3. auto type
*/

/*
 * It's static type, no run-time cost, fat-free.
 * It also makes code easier to maintain.
 * 
 * 1. Don't use auto when type conversion is needed
 * 2. IDE becomes more important
 */

// #include <vector>
// #include <iostream>

// using namespace std;

// int main(int argc, char *argv[]) {

//     auto a = 6;       // a is a integer
//     auto b = 9.6;     // b is a double
//     auto c = a;       // c is an integer
//     auto const x = a; // int const x = a
//     auto &y = a;      // int& y = a

//     std::vector<int> vec = {2, 3, 4, 5};

//     // C++ 03
//     for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
//         cout << *it << endl;
//     }

//     // C++ 11: use auto type
//     for (auto it = vec.begin(); it != vec.end(); ++it) {
//         cout << *it << endl;
//     }

//     return 0;
// }

/*
 * 4. foreach
 */

// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main(int argc, char *argv[]) {

//     vector<int> v = {1,2,3};

//     // C++ 03:
//     for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
//         cout << (*itr);

//     // C++ 11: for each
//     for (int i : v) { // works on any class that has begin() and end()
//         cout << i;     // readonly access
//     }

//     for (auto &i : v) {
//         i++; // changes the values in v
//     }        // and also avoids copy construction

//     auto x = begin(v); // Same as: int x = v.begin();

//     int arr[4] = {3, 2, 4, 5};
//     auto y = begin(arr); // y == 3
//     auto z = end(arr);   // z == 5

//     // How this worked? Because begin() and end() are defined for array.
//     // Adapt your code to third party library by defining begin() and end()
//     // for their containers.

//     return 0;
// }

/*
 * 5. nullptr
 */
/*
 * To replace NULL in C++ 03
 */

// #include <iostream>
// #include <string>
// using namespace std;

// void foo(int i) {
//     cout << "foo_int" << endl;
// }
// void foo(char *pc) {
//     cout << "foo_char*" << endl;
// }

// int main(int argc, char *argv[]) {
//     // foo(NULL); // Ambiguity
//     // more than one instance of overloaded function "foo" matches the argument list:C/C++(308)

//     // C++ 11
//     foo(nullptr); // call foo(char*)

//     return 0;
// }

/*
 * 6. enum class
 */

// #include <iostream>
// #include <string>
// using namespace std;

// int main(int argc, char *argv[]) {

//     // C++ 03
//     enum apple { green_a, red_a };
//     enum orange { big_o, small_o };
//     apple a1 = green_a;
//     orange o1 = big_o;

//     if (a1 == o1)
//         cout << "green apple and big orange are the same\n";
//     else
//         cout << "green apple and big orange are not the same\n";

//     // C++ 11
//     enum class Apple { green, red };
//     enum class Orange { big, small };
//     Apple a2 = Apple::green;
//     Orange o2 = Orange::big;

//     // Compile fails because we haven't defined ==(Apple, Orange)
//     // if (a2 == o2) // This line will fail to compile
//     //    cout << "green apple and big orange are the same\n";
//     // else
//     //    cout << "green apple and big orange are not the same\n";

//     return 0;
// }

/*
 * 7. static_assert
 */

// #include <iostream>
// #include <string>
// #include <cassert>

// using namespace std;

// int main(int argc, char *argv[]) {
//     int a = 3;
//     int *p = &a;

//     // run-time assert
//     assert(p != nullptr);

//     // Static assert - Compile time assert (C++ 11)
//     static_assert(sizeof(int) == 4);
//     return 0;
// }

/*
 * 8. Delegating Constructor
 */

// C++ 03:
// class Dog {
// private:
//     void init() {
//         // Perform common initialization tasks here
//     }

// public:
//     // Constructors
//     Dog() {
//         init();
//     }
//     Dog(int a) {
//         init();
//         // doOtherThings();
//     }
// };

// /* Cons:
//  * 1. Cumbersome code.
//  * 2. init() could be invoked by other functions.
//  */

// // C++ 11:
// class Dog11 {
//     int age = 9;
// public:
//     Dog11() {
//     }
//     Dog11(int a) : Dog11() {
//         // doOtherThings();
//     }
// };
// // Limitation: Dog() has to be called first.

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
//     virtual void A(float); // Created a new function
//     virtual void B();      // Created a new function
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
//     virtual void bark() final; // No class can override bark()
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
//     Dog11 &operator=(const Dog11 &) = delete;
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
//     char *a = "string";

//     // C++ 11:
//     char *b = u8"string";     // to define an UTF-8 string.
//     char16_t *c = u"string";  // to define an UTF-16 string.
//     char32_t *d = U"string";  // to define an UTF-32 string.
//     char *e = R"(string \\)"; // to define raw string.

//     return 0;
// }

/*
 * 15. lambda function
 */

// #include <iostream>
// #include <string>
// # include <vector>

// using namespace std;

//     template <typename func> void filter(func f, vector<int> arr) {
//         for (auto i : arr) {
//             if (f(i))
//                 cout << i << " ";
//         }
//     }

// int main(int argc, char *argv[]) {
//     cout << [](int x, int y) { return x + y;}(3, 4) << endl; // Output: 7
//     auto f = [](int x, int y) { return x + y; };
//     cout << f(3, 4) << endl; // Output: 7

//     vector<int> v = {1, 2, 3, 4, 5, 6};

//     filter([](int x) { return (x > 3); }, v);          // Output: 4 5 6
//     filter([](int x) { return (x > 2 && x < 5); }, v); // Output: 3 4

//     int y = 4;
//     filter([&](int x) { return (x > y); }, v); // Output: 5 6
//     //Note: [&] tells compiler that we want variable capture

//     // Lambda function works almost like a language extention
//     // template for_nth_item

//     return 0;
// }

/*
 * 17. User defined Literals
 */
// C++ went a long way to make user defined types (classes) to behave same as buildin types.
// User defined literals pushes this effort even further

// #include <iostream>
// #include <string>
// using namespace std;

// // C++ 11:
// // first example:
// long double operator"" _cm(long double x) {
//     return x * 10;
// }
// long double operator"" _m(long double x) {
//     return x * 1000;
// }
// long double operator"" _mm(long double x) {
//     return x;
// }

// //Note: add constexpr to make the translation happen in compile time.
// // Restriction: it can only work with following paramters:
// // char const *unsigned long long long double char const *,
// //     std::size_t wchar_t const *, std::size_t char16_t const *,
// //     std::size_t char32_t const *,
// //     std::size_t
// // Note: return value can be of any types.

// // second Example:
// // User-defined literal for hexadecimal conversion
// int operator"" _hex(const char *str, size_t length) {
//     int result = 0;
//     for (size_t i = 0; i < length; ++i) {
//         char c = str[i];
//         int digit;
//         if (c >= '0' && c <= '9') {
//             digit = c - '0';
//         } else if (c >= 'a' && c <= 'f') {
//             digit = c - 'a' + 10;
//         } else if (c >= 'A' && c <= 'F') {
//             digit = c - 'A' + 10;
//         } else {
//             // Invalid character
//             throw std::invalid_argument("Invalid hexadecimal character");
//         }
//         result = result * 16 + digit;
//     }
//     return result;
// }

// // User-defined literal for octal conversion
// int operator"" _oct(const char *str, size_t length) {
//     int result = 0;
//     for (size_t i = 0; i < length; ++i) {
//         char c = str[i];
//         if (c < '0' || c > '7') {
//             // Invalid character
//             throw std::invalid_argument("Invalid octal character");
//         }
//         result = result * 8 + (c - '0');
//     }
//     return result;
// }

// int main(int argc, char *argv[]) {
//     //Old C++ 03:
//     long double height03 = 3.4;

//     // Remember in high school physics class?
//     // height = 3.4cm;
//     // ratio = 3.4cm / 2.1mm;

//     //Why we don't do that anymore?
//     // 1. No language support
//     // 2. Run time cost associated with the unit translation

//     long double height = 3.4_cm;
//     cout << height << endl;              // 34
//     cout << (height + 13.0_m) << endl;   // 13034
//     cout << (130.0_mm / 13.0_m) << endl; // 0.01

//     cout << "FF"_hex << endl; // 255
//     cout << "40"_oct << endl; // 32

//     return 0;
// }

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