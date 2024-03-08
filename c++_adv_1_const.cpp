// ***********************************************
// if const is on the  left of *,    data is const
// if const is on the right of *, pointer is const
// ***********************************************

/* A compile time constraint that an object can not be modified

Why use const
-------------
1. guards against inadvertent write to the variable
2. self documenting
3. compiler makes more optimization
4. variabel can be put in ROM

*/

#include <iostream>

using namespace std;

int main() {
    const int i = 9;
    // i = 6;   // fails

    const int* p0 = &i; // data is constant, pointer is not
                        //        equivalent to:
    int const* p1 = &i; // data is constant, pointer is not
    p1++;               // *p1 = 5;  fails

    int* const p2 = &i; // pointer is constant, data is not
    *p2 = 9;            // p2++;    fails

    const int* const p3 = &i; // pointer and data both constant
    // p3++; *p3 = 10;  // fail

    // const_cast<int&>(i) = 6;
    // // Uses const_cast to remove the constness of i and assign it the value 6
    // cout << "i = " << i << endl; // Outputs the value of i (which is now 6) ???

    // static_cast<const int&>(j);
    // // Uses static_cast to cast j to a const int reference (this doesn't change j itself)
    // j = 10; // Modifies j to 10
    // cout << "j = " << j << endl; // Outputs the value of j (which is now 10)

    return 0;
}
