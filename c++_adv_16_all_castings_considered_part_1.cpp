//############################################################################
/*
 * All Castings Considered - Part 1
 *
 * Type Conversion:
 *    1. Implicit Type Conversion
 *    2. Explicit Type Conversion - Casting
 */
//############################################################################

#include <iostream>

using namespace std;

class dog {
    string name_;

public:
    virtual ~dog() {}
    string name() const { return this; }
};

class yellowdog : public dog {
    int age;

public:
    void bark() { cout << "woof. I am " << age << endl; }
};

/*
 * 1. static_cast
 */
int i = 9;
float f = static_cast<float>(i);              // convert object from one type to another
dog d1 = static_cast<dog>(string("Bob"));     // Type conversion needs to be defined.
dog* pd = static_cast<dog*>(new yellowdog()); // convert pointer/reference from one type
                                              // to a related type (down/up cast)

/*
 * 2. dynamic_cast
 */
dog* pd = new yellowdog();
yellowdog* py = dynamic_cast<yellowdog*>(pd);
// a. It convert pointer/reference from one type to a related type (down cast)
// b. run-time type check.  If succeed, py==pd; if fail, py==0;
// c. It requires the 2 types to be polymorphic (have virtual function).

/*
 * 3. const_cast
 */                                        // only works on pointer/reference
const char* str = "Hello, world.";         // Only works on same type
char* modifiable = const_cast<char*>(str); // cast away constness of the object
                                           // being pointed to

/*
 * 4. reinterpret_cast
 */
long p = 51110980;
dog* dd = reinterpret_cast<dog*>(p); // re-interpret the bits of the object pointed to
// The ultimate cast that can cast one pointer to any other type of pointer.

/*
 * C-Style Casting:
 */
short a = 2000;
int i = (int)a; // c-like cast notation
int j = int(a); // functional notation
//   A mixture of static_cast, const_cast and reinterpret_cast

/*
 * Generally C++ style of casts are preferred over the C-style, because:
 * 1. Easier to identify in the code.
 * 2. Less usage error. C++ style provides:
 *    a. Narrowly specified purpose of each cast, and
 *    b. Run-time type check capability.
 */
