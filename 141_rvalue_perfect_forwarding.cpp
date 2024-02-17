
/*
UNIVERSAL REFERENCE !!!
    rvalue, lvalue, const, non-const, etc.

    Conditions:
    1. T is a template type. Type deduction (reference collapsing) happens to T.
    2. T is a function template type, not class template type.

*/

template <typename T>
void relay(T&& arg) { // Universal Reference, works for lvalues and rvalues
    foo(std::forward<T>(arg));
}

// Implementation of std::forward()
// cast arg to type T&&
/*
template <class T>
T&& forward(typename remove_reference<T>::type &arg) {
    return static_cast<T&&>(arg);
}

 MOVE <--> FORWARD
    std::move() vs std::forward()
    std::move<T>(arg);      // Turns arg into rvalue type
    std::forward<T>(arg);   // Turns rvalue into type of T&&
*/

/*
    PERFECT FORWARDING

    Reference Collapsing Rules (C++ 11)
    T& &    ==> T&
    T& &&   ==> T&
    T&& &   ==> T&
    T&& &&  ==> T&&

    template< typename> T >
    void func (T&& arg) {...}    func can take any type of argument

    if arg is initialized with rvalue ==> T&& arg is rvalue reference
    if arg is initialized with lvalue ==> T&& arg is lvalue reference
 
    UNIVERSAL REFERENCE !!!
    rvalue, lvalue, const, non-const, etc.

    Conditions:
    1. T is a template type.
    2. Type deduction (reference collapsing) happens to T.
    3. T is a function template type, not class template type.

   
    */