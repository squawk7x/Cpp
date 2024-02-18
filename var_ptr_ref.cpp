#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int i = 42;
// int& ri = i;
// int j = ri + 2;

// ==

// int* const cpi = &i;
// *cpi = 4;
// int k = *cpi + 2;

// int foo(int x) {
//     cout << "foo returns var";
//     return x;
// }

int foo(int& lv) {
    cout << "foo returns lvalue";
    return lv;
}

int foo(int&& rv) {
    cout << "foo returns rvalue";
    return rv;
}

int main(int argc, char* argv[]) {
    int bar = 21;
    int var{7};
    int& lv_ref = var; // ref needs initializer
    int&& rv_ref = 9;
    int* ptr;

    // rv_ref = 47;

    ptr = &bar;  // ptr can be reassigned
    ptr = &var;

    cout << "&var: " << &var << " var: " << var << "\n";
    cout << "&lv_ref: " << &lv_ref << " lv_ref: " << lv_ref << "\n";
    cout << "&ptr: " << &ptr << " ptr: " << ptr << " *ptr: " << *ptr << "\n";
    cout << "*&ptr: " << *&ptr << "\n";
    cout << "&*ptr: " << &*ptr << "\n\n";
    // cout << "&rv_ref: " << &rv_ref << " rv_ref: " << rv_ref << "\n";
    cout << "\n";

    int lvalue = foo(lv_ref);
    cout << " " << lvalue << "\n";

    int rvalue = foo(std::move(lv_ref));
    cout << " " << rvalue << "\n";
    
    return 0;
}