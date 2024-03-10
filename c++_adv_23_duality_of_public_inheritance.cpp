//###########################################################################
/*
 * The Duality of Public Inheritance
 *
 *   - Inheritance of Interface
 *   - Inheritance of Implementation
 *
 *    Interface Implementation
 *      func()    { ... }
 */
//###########################################################################

#include <iostream>

using namespace std;

class Dog {
public:
    virtual void bark() = 0; // inherit interface only
    void run() {             // inherit interface and implementation
        cout << "I am running.";
    }
    virtual void eat() {
        cout << "I am eating. "; // inherit interface and default implementation
    }

protected:
    void sleep() {
        cout << " I am sleeping. "; // inherit implementation only
    }
};

class Yellowdog : public Dog {
public:
    virtual void bark() { cout << "I am a yellow dog.\n"; }
    void iSleep() { sleep(); }
};

/*
 * Types of Inheritance in C++:
 * 1. Pure virtual public function - inherit interface only.
 * 2. Non-virtual public function - inherit both interface and implementation.
 * 3. Impure virtual public function - inherit interface and default implementation
 * 4. Protected function - inherit implementation only
 *
 * As a software designer, it is very important to separate the concepts of
 * interface and implementation.
 */

/*
 * Interface Inheritance
 *
 * 1. Subtyping
 * 2. Polymorphism
 */

// virtual void bark() = 0;

/*
 * Pitfalls:
 *  -- Be careful of interface bloat.
 *  -- Interfaces do not reveal implementation.
 */

/*
 * Implementation Inheritance
 *    - Increase code complexity
 *    - Not encouraged
 */

// public:
// void run() {
//     cout << "I am running.";
// }
// virtual void eat() {
//     cout << "I am eating. ";
// }

// protected:
// void sleep() {
//     cout << " I am sleeping. ";
// }

/*
 * "Inheritance is evil"  ???
 *
 * "Inheritance is often useful, but more often overused (abused)."
 *
 * Guidelines for Implementation Inheritance:
 * 1. Do not use inheritance for code reuse, use composition.
 * 2. Minimize the implementation in base classes. Base classes should be thin.
 * 3. Minimize the level of hierarchies in implementation inheritance.
 */
