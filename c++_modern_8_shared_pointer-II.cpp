// ***********************************************
// shared_ptr II
// ***********************************************

// 1. When a pointer outlives pointee: dangling pointer
// 2. When a pointee outlives all its pointers: resource leak
//
// Smart Pointers: Make sure the lifetime of a pointer and pointee match.

#include <iostream>
#include <memory>
#include <string>

using namespace std;

class Dog {
    string m_name;

public:
    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    Dog() {
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
};

void foo() {
    shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
    auto p2 = make_shared<Dog>("Tank");
    p1 = p2;      // Gunner is deleted or
    p1 = nullptr; // Gunner is deleted or
    p1.reset();   // Gunner is deleted
}

void foo2() {
    shared_ptr<Dog> p1 = make_shared<Dog>("Gunner"); // using default deleter: operator delete
    // If you want to use custom deleter
    // you need to use constructor of shared pointer with custom deleter
    shared_ptr<Dog> p2 = shared_ptr<Dog>(new Dog("Tank"), [](Dog* p) {
        cout << "Custom deleting... ";
        delete p;
    });
    shared_ptr<Dog> p3(new Dog[3]); // dog[1] and dog[2] have memory leaks -> custom deleter
    shared_ptr<Dog> p4(new Dog[3],
                       [](Dog* p) { delete[] p; }); // all 3 dogs deleted when p4 goes out of scope
}

void foo3() {
    shared_ptr<Dog> p1 = make_shared<Dog>("Gunner");
    Dog* d = p1.get(); // returns the raw pointer

    // AVOID using the raw pointer !!!
    // delete d; // undefined behavior
    // shared_ptr<Dog> p2(d);
    // doghouse.saveDog(d);
}

int main() {
    foo();
    foo2();
}
