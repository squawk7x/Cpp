// **************************************************
// if const is on the left of *, data is constant
// if const is on the right of *, pointer is constant
// **************************************************

int main() {
    const int i = 5;
    // i = 6;   fails

    // ------------------------------------

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
