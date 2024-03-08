
//############################################################################
// C++ Keyword: using 
//############################################################################
 
 /*
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
using namespace std;        //case 1: global scope
using std::cout, std::endl; // case 2a: global scope

// class B {
// public:
//     void f(int a) {
//         cout << "f in B" << endl;
//     }
// };

// class D : private B {
// public:
//     void f() { // function shadowing
//         cout << "f in D" << endl;
//     }

//     void g() {
//         using namespace std; // case 1: local scope
//         cout << "g in D\n" << endl;
//     }

//     void h() {
//         using std::cout; // case 2a: local scope
//         cout << "h in D\n" << endl;
//     }
//     using B::f; // case 2b: class scope
//     // <-- now access to private member f of B
// };

// int main() {
//     D d;
//     d.f(8);
// }



/*
 * Anonymous Namespace
 */

// similiar to: 
// static void h() { std::cout << "h()\n"; }
// void g() { std::cout << "global g()\n"; }

namespace {
   void g() { std::cout << "g()\n"; }
   void h() { std::cout << "h()\n"; g(); }
}

int main() {
   h();
}