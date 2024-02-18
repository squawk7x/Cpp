
//############################################################################
/*
C++ Keyword: using 

1. using directive: to bring all namespace members into current scope
  Example:  
                using namespace std;

2. using declaration
   a. Bring one specific namespace member to current scope. 
   b. Bring a member from base class to current class's scope. 
   Example:
                using std::cout;
                cout << "Hello world.\n";
*/

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
    using B::f; // <-- now access to private member f of B
    void f() {  // function shadowing
        cout << "f in D" << endl;
    }
};

int main() {
    D d;
    d.f(8);
}