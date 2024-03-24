//###################################################################
//  Learn C++ 11 in 20 minutes - 1
//###################################################################

/*
 * 1. Initializer List
 */

#include <initializer_list>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class BoVector {
    vector<int> m_vec;

public:
    // Define your own initializer_list constructor:
    BoVector(const initializer_list<int>& v) {
        for (initializer_list<int>::iterator itr = v.begin(); itr != v.end(); ++itr)
            m_vec.push_back(*itr);
    }
};

class Rectangle {
public:
    Rectangle(int height, int width, int length) {}
};

void draw_rect(Rectangle r) { cout << "Rectangle was drawn." << endl; };

// int main() {
//     //C++ 03 initializer list:
//     int arr[4] = {3, 2, 4, 5};

//     // vector not supported in C++ 03
//     vector<int> v;
//     v.push_back(3);
//     v.push_back(2);
//     v.push_back(4);
//     v.push_back(5);

//     // C++ 11 extended the support
//     // All the relevant STL containers have been updated to accept initializer_list.
//     vector<int> v2 = {3, 4, 1, 9}; // Calling initializer_list constructor

//     BoVector v3 = {0, 2, 3, 4};
//     BoVector v4{0, 2, 3, 4}; // effectively the same

//     // Automatic normal Initialization
//     draw_rect({5, 6, 9}); // Rectangle{5,6,9} is automatically called
// }

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

// // C++ 11 extended the scope of curly brace initialization
// class Dog11_1 {
// public:
//     Dog11_1(int age, string name){};
// };

/* Uniform Initialization Search Order:
 * 1. Initializer_list constructor
 * 2. Regular constructor that takes the appropriate parameters.
 * 3. Aggregate initializer.
 */

// class Dog11_2 {
// public:

// 3rd choice - Aggregat Initializer
//     int age;

// 2nd choice - Regular Constructor
//     Dog11_2(int a) {
//         age = a;
//     }

// 1st choice - Initializer_list
//     Dog11_2(const initializer_list<int> &vec) {
//         age = *(vec.begin());
//         cout << "created with initializer_list" << endl;
//     }
// };

// int main() {
//     Dog3 d3 = {5, "Henry"}; // Aggregate Initialization

//     // C++ 11 extended the scope of curly brace initialization
//     Dog11_1 d11_1 = {5, "Henry"};

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
//         cout << i;    // readonly access
//     }

//     for (auto& i : v) {
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

/* Cons:
 * 1. Cumbersome code.
 * 2. init() could be invoked by other functions.
 */

// // C++ 11:
// class Dog11 {
//     int age = 9; // in class datamember initialization
// public:
//     Dog11() {
//     }
//     Dog11(int a) : Dog11() {
//         // doOtherThings();
//     }
// };
// // Limitation: Dog() has to be called first.
