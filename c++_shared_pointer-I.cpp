/*********** Shared_ptr ***********/

// 1. When a pointer outlives pointee: dangling pointer
// 2. When a pointee outlives all its pointers: resource leak
//
// Smart Pointers: Make sure the lifetime of a pointer and pointee match.

/*
   WRONG way to use shared pointer:
   Dog* d = new Dog("Gunner");  // d lvalue
   shared_ptr<Dog> p(d); 

   CORRECT way:
   shared_ptr<Dog> p(new Dog("Tank")); //count ==1

   BETTER way (eliminates asymmetric use of 'new'):
   shared_ptr<Dog> p = make_shared<Dog>("Tank");

   BEST way:
   auto p = make_shared<Dog>("Tank");

*/
#include <string>
#include <iostream>
#include <memory>

using namespace std;

class Dog {
    string m_name;

public:
    void bark() {
        cout << "Dog " << m_name << " rules!" << endl;
    }
    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    Dog() {
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    ~Dog() {
        cout << "dog is destroyed: " << m_name << endl;
    }
};

void foo() {
    // CORRECT way creating shared pointer, but not BEST way (see below PREFERED ...):
    // An object should be assigned to a smart pointer as soon as itis created.
    // Raw pointer should not be used.
    shared_ptr<Dog> p(new Dog("Gunner")); //count ==1
    // 1. Gunner is created
    // 2. p is created
    {
        shared_ptr<Dog> p2 = p; // count == 2
        p2->bark();
        cout << "\ncounts: " << p2.use_count() << "\n";
    } // count == 1
    p->bark();
} //count == 0

int main() {
    // foo();

    // WRONG way to use shared pointer:
    // Dog* d = new Dog("Tank");
    // shared_ptr<Dog> p(d);

    // PREFERED way to create shared pointer:
    // Dog* d = new Dog("Tank");
    shared_ptr<Dog> p = make_shared<Dog>("Tank"); // faster and safer
    p->bark();                                    // == (*p).bark();
    auto p2 = make_shared<Dog>("Gunner");
    p2->bark(); // == (*p2).bark();

    // CASTING with shared pointer:
    // static_pointer_cast
    // dynamic_pointer_cast
    // const_pointer_cast
}
