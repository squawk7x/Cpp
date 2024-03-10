// ***********************************************
// shared_ptr I
// ***********************************************

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
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Dog {
    string m_name;

public:
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    Dog() {
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
};

void foo_wrong() {
    Dog* dog_w = new Dog("dangerous dog");
    // delete dog_w;
    dog_w->bark(); // dog_w is a dangling pointer - undefined behavior
} // Memory Leak

void foo() {
    // CORRECT way creating shared pointer, but not the BEST way (see below PREFERED ...):
    shared_ptr<Dog> p(new Dog("Gunner")); // count == 1
    // 1. Gunner is created
    // 2. p is created with Dog Gunner
    // not exception safe:
    // What if Dog is created successfully but shared_ptr failed to be created?

    {
        shared_ptr<Dog> p2 = p; // count == 2
        p2->bark();
        cout << "\ncounts: " << p2.use_count() << "\n";
    } // count == 1
    p->bark();
} // count == 0

int main() {
    // foo_wrong();
    foo();

    // WRONG way to use shared pointer:
    // Dog* d = new Dog("Tank");    // bad idea
    // shared_ptr<Dog> p(d);    // p.use_count() == 1
    // shared_ptr<Dog> p2(d);   // p2.use_count() == 1
    // An object should be assigned to a smart pointer as soon as it is created.
    // Raw pointer should not be used again.

    // PREFERED way to create shared pointer:
    shared_ptr<Dog> p = make_shared<Dog>("Tank"); // faster and safer
    p->bark();
    (*p).bark();
    auto p2 = make_shared<Dog>("Gunner");
    p2->bark(); // == (*p2).bark();

    // CASTING with shared pointer:
    // static_pointer_cast
    // dynamic_pointer_cast
    // const_pointer_cast
}
