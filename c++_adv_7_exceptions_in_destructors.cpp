//############################################################################
// Prevent Exceptions from Leaving Destructors.
//############################################################################

#include <iostream>
#include <string>

using namespace std;

class Dog {
public:
    string m_name;
    Dog(string name) {
        m_name = name;
        cout << name << " is born." << endl;
    }
    ~Dog() {
        cout << m_name << " is distroyed." << endl;
        // when Bob and Henry are removed from stack, 2 exceptions might be pending!
        // avoid throw exeption in destructor
    }

    // 1. Solution: Destructor swallows the exception.
    // ~Dog() {
    //     try {
    //         cout << m_name << " is distroyed." << endl;
    //         throw 20;
    //     } catch (int e) {
    //         cout << e << " is caught" << endl;
    //     } catch (...) { // dangerous: this masks all other exceptions
    //     }
    // }

    // 2. Solution: Move the exception-prone code to a different function.
    void prepareToDestr() {
        // ...
        throw 20;
    }

    void bark() { cout << m_name << " is yelling" << endl; }
};

int main() {
    try {
        Dog dog1("Henry");
        Dog dog2("Bob");
        // throw 20;   // first the objects on stack will be distroyed
        dog1.bark();
        dog2.bark();
        dog1.prepareToDestr();
        dog2.prepareToDestr();
    } catch (int e) {
        cout << e << " is caught" << endl;
    }
}

/*
 *
 * Which one to use?
 * It depends on who is the better person to handle the exception, dog or dog's client.
 *
 * /
