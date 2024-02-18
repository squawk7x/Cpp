// ***********************************************
// if const is on the  left of *,    data is const
// if const is on the right of *, pointer is const
// ***********************************************


/*
Why use const
-------------
1. guards against inadvertent write to the variable
2. self documenting
3. compiler makes more optimization
4. variabel can be put in ROM

*/

int main() {
    const int i = 5;
    // i = 6;   fails

    int j = 7;

    const int *p10 = &j; // data is constant, pointer is not ==
    int const *p11 = &j; // data is constant, pointer is not
    p10++;               // *p10 = 5;  fails

    int *const p2 = &j; // pointer is constant, data is not
    *p2 = 9;            // p2++;    fails

    const int *const p3 = &j; // pointer and data both constant
    // p3++; *p3 = 10;
}
// const_cast<int&>(i) = 6;
// static_cast<const int&>(j);
