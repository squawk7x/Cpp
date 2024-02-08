#include <iostream>
using std::cout, std::endl;

class B {
public:
    void f(int a) {
        cout << "f in B" << endl;
    }
};

class D : public B {
public:
    using B::f;                     // <-- now access to private member f of B
    void f() {                      // function shadowing
        cout << "f in D" << endl;
    }
};

int main(){
    D d;
    d.f(8);
}