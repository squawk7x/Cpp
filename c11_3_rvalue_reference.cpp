#include <iostream>
#include <string>
#include <type_traits>
#include <vector>
using namespace std;

// std::vector<int> foo() {
//     std::vector<int> temp = {1, 2, 3, 4};
//     return temp;    // C++3: prvalue // C++11: auto move optimization
// }

// int main() {
//     // Correct. The type of "01234" is const char [6], so it is an lvalue
//     const char(&left)[6] = "01234";
//     // Assert success. It is a const char [6] indeed. Note that decltype(expr)
//     // yields lvalue reference if expr is an lvalue and neither an unparenthesized
//     // id-expression nor an unparenthesized class member access expression.

//     static_assert(std::is_same<decltype("01234"), const char(&)[6]>::value, "");
//     // Error. "01234" is an lvalue, which cannot be referenced by an rvalue reference
//     // const char (&&right)[6] = "01234";

//     const char *p = "01234";
//     cout << *(p + 2) << std::endl;
//     // Correct. "01234" is implicitly converted to const char*

//     const char *&&pr = "01234";
//     cout << *(pr + 2) << std::endl;
//     // Correct. "01234" is implicitly converted to const char*, which is a

//     // const char*& pl = "01234";
//     // Error. There is no type const char* lvalue

//     std::vector<int> v = foo();
//     cout << v.size() << std::endl;  // C++3: copy of temp   // C++11: moved by compiler
//     automatically
// }

// with rvalue reference T&& you get a xvalue
// std::move can convert lvalue to rvalue

// void reference(std::string &str) {
//     std::cout << "lvalue" << std::endl;
// }

// void reference(std::string &&str) {
//     std::cout << "rvalue" << std::endl;
// }
// int main() {
//     std::string lv1 = "string "; // lv1 is a lvalue
//     std::cout << lv1 << std::endl; // string
//     // std::string&& r1 = lv1; // illegal, rvalue can't ref to lvalue

//     std::string &&rv1 = std::move(lv1);
//     // legal, std::move can convert lvalue to rvalue
//     std::cout << rv1 << std::endl; // string

//     const std::string &lv2 = lv1 + lv1; // legal, const lvalue reference can
//     // extend temp variable's lifecycle
//     // lv2 += "Test"; // illegal, const ref can't be modified
//     std::cout << lv2 << std::endl; // string,string,

//     std::string &&rv2 = lv1 + lv2; // legal, rvalue ref extend lifecycle
//     rv2 += "string ";              // legal, non-const reference can be modified
//     std::cout << rv2 << std::endl; // string,string,string,string

//     reference(rv2); // output: lvalue

//     return 0;
// }

// void increase(int &v) {
//     v++;
// }

// void foo() {
//     double s = 1;
//     increase(s);
// }

// int main() {
//     // int &a = std::move(1); // illegal, non-const lvalue reference cannot ref rvalue
//     const int &b = std::move(1); // legal, const lvalue reference can
//     std::cout << b << std::endl;

// }
class A {
public:
    int* pointer;
    A() : pointer(new int(1)) { std::cout << "construct " << pointer << std::endl; }

    A(A& a) : pointer(new int(*a.pointer)) {
        std::cout << "copy " << pointer << std::endl;
    } // meaningless object copy

    A(A&& a) : pointer(a.pointer) {
        a.pointer = nullptr;
        std::cout << "move " << pointer << std::endl;
    }

    ~A() {
        std::cout << "destruct " << pointer << std::endl;
        delete pointer;
    }
};

// avoid compiler optimization
A return_rvalue(bool test) {
    A a, b;
    if (test)
        return a; // equal to static_cast<A&&>(a);
    else
        return b; // equal to static_cast<A&&>(b);
}

int main() {
    A obj = return_rvalue(false);
    std::cout << "obj:" << std::endl;
    std::cout << obj.pointer << std::endl;
    std::cout << *obj.pointer << std::endl;
    return 0;
}