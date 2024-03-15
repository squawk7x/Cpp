

class Plus {
    int value;

public:
    Plus(int v) { value = v; };
    int plusme(int x) const { return x + value; };
    int operator()(int x) const { return x + value; };
    template <class T> T operator()(T x) { return x + value; };
};

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Plus p(1);
    auto plus = Plus(1);
    auto func = [value = 1](int x) { return value + x; };
    auto func2 = [value = 1](auto x) { return value + x; };

    cout << plus.plusme(42.7) << endl;
    cout << plus(42.1) << endl;
    cout << func(42.3) << endl;
    cout << func2(42.3) << endl;

    return 0;
}