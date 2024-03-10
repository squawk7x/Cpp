//############################################################################
/*
 * All Castings Considered - Part 2
 *
 * Type Conversion:
 *    1. Implicit Type Conversion
 *    2. Explicit Type Conversion - Casting
 */
//############################################################################

#include <iostream>

using namespace std;

/*
 * Casting could be risky.
 *
 * Example with dynamic_cast:
 */

class dog {
public:
    virtual ~dog() {}
};

class yellowdog : public dog {
    int age;

public:
    void bark() { cout << "woof. I am " << age << endl; }
};

int main() {
    dog* pd = new dog();
    yellowdog* py = dynamic_cast<yellowdog*>(pd);
    py->bark();
    cout << "py = " << py << endl;
    cout << "pd = " << pd << endl;
}

/* casting could be a handy hack tool */

// class dog {
// public:
//     std::string m_name;
//     dog() : m_name("Bob") {
//     }
//     void bark() const {
//         std::cout << "My name is " << m_name << std::endl;
//     }
// };

//	  m_name = "Henry";
//	  const_cast<dog*>(this)->m_name = "Henry";

/*
 * =========================================  C++ Style Casting ================================
 *
 *                            Generate_Code   Generate_data      risky   data_type
 * Object Casting:
 *    static_cast                 yes              yes             2      any types
 *                                                                        (as long as type
 *                                                                        conversion is defined)
 * Pointer/Reference Casting:
 *    static_cast                 no               no              4      related types
 *    dynamic_cast                yes              no              3      related types(down-cast)
 *    const_cast                  no               no              1      same type
 *    reinterpret_cast            no               no              5      any types
 *
 * =========================================  C Style Casting ================================
 *
 *                             Generate_Code  Generate_data      risky   data_type
 * Object Casting:               yes              yes             5      any types
 *                                                                       (as long as type
 *                                                                       conversion is defined)
 * Pointer/Reference Casting:    no               no              5      any types
 *
 *
 * Notes can be downloaded at my website: boqian.weebly.com
 *
 * Note:
 * 1. const_cast, dynamic_cast and reinterpret_cast can only work on pointers/references.
 * 2. static_cast of objects is very different from static_cast of pointers.
 * 3. reinterpret_cast basically reassigning the type information of the bit pattern.
 *    It should only be used in low-level coding.
 * 4. dynamic_cast does static_cast plus run-time type check.
 * 5. dynamic_cast and static_cast for pointers can only work on related type (e.g.,
 *    base <-> derived).
 *
 */

/* Use polymorphism to minimize castings */

// class dog {
// public:
//     virtual ~dog() {
//     }
// };

// class yellowdog : public dog {
// public:
//     void bark() {
//         cout << "Yellow dog rules! " << endl;
//     }
// };

// int main() {
//     dog* pd = get_dog();
//     if (yellowdog* py = dynamic_cast<yellowdog*>(pd)) {
//         py->bark();
//     }
//     delete pd;
// }

/* Add virtual bark() in dog */

// class dog {
// public:
//     virtual ~dog() {
//     }
//     virtual void bark() {
//     }
// };

// class yellowdog : public dog {
// public:
//     void bark() {
//         cout << "Yellow dog rules! " << endl;
//     }
// };

// int main() {
//     dog* pd = get_dog();
//     pd->bark();
//     delete pd;
// }
