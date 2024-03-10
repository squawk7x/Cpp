#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
    int a, b;
    string c;

    // Default constructor
    MyClass() : a(0), b(0), c("") {}

    // Parameterized constructor
    MyClass(int a_val, int b_val, const string& c_val) : a(a_val), b(b_val), c(c_val) {}

    // Copy constructor
    MyClass(const MyClass& x) : a(x.a), b(x.b), c(x.c) {}
};

class Example5 {
    string* ptr;

public:
    Example5(const string& str) : ptr(new string(str)) {}
    Example5(const Example5& x) : ptr(new string(x.content())) {} // copy constructor:
    ~Example5() { delete ptr; }

    const string& content() const { return *ptr; } // access content:
};

int main() {
    Example5 foo("Example");
    Example5 bar = foo;

    cout << "bar's content: " << bar.content() << '\n';
    return 0;
}
