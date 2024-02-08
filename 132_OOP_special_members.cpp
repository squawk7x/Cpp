// classes and default constructors
#include <iostream>
#include <string>
using namespace std;

class Example {
public:
    int total;
    void accumulate(int x) {
        total += x;
    }
};

class Example2 {
public:
    int total;
    Example2(int initial_value) : total(initial_value){};
    void accumulate(int x) {
        total += x;
    };
};

class Example3 {
    string data;

public:
    Example3() {
    }
    Example3(const string &str) : data(str) {
    }
    const string &content() const {
        return data;
    }
};

class Example4 {
    string *ptr;

public:
    // constructors:
    Example4() : ptr(new string) {
    }
    Example4(const string &str) : ptr(new string(str)) {
    }
    // destructor:
    ~Example4() {
        delete ptr;
    }
    // access content:
    const string &content() const {
        return *ptr;
    }
};

int main() {
    Example4 foo;
    Example4 bar("Example");

    cout << "bar's content: " << bar.content() << '\n';
    return 0;
}