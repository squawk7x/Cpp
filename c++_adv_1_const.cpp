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
    int i = 9;
    // const int i = 9;
    // i = 6;   // fails

    const int* p0 = &i; // data is constant, pointer is not
                        //        equivalent to:
    int const* p1 = &i; // data is constant, pointer is not
    p1++;               // *p1 = 5;  fails

    int* const p2 = &i; // pointer is constant, data is not
    *p2 = 9;            // p2++;    fails

    const int* const p3 = &i; // pointer and data both constant
    // p3++; *p3 = 10;  // fail

    // Use const_cast to remove the constness
    const int c = 5;
    int& ref_c = const_cast<int&>(c);
    ref_c = 6;
    cout << "c = " << c << endl;

    // Uses static_cast to cast j to a const
    int j = 10;
    const int& const_j = static_cast<const int&>(j);
    // const_j = 13; // This line will cause a compilation error since const_j is a const reference

    return 0;
}
