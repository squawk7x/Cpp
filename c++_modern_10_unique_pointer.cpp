
// ***********************************************
// unique_ptr
// ***********************************************

// Unique Pointers: exclusive owenership (<-> shared pointers)
// out of scope or starts to own another object -> original object automatically deleted
// light weight smart pointer

#include <iostream>
#include <memory>

using namespace std;

class Dog {
public:
    string m_name;
    void bark() {
        cout << "Dog " << m_name << " rules!" << endl;
    }
    Dog() {
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    ~Dog() {
        cout << "dog is destroyed: " << m_name << endl;
    }
};

void test() {
    // old way:
    // Dog* pD = new Dog("Gunner");
    // pD->bark();
    /* pD does a bunch of different things */
    // delete pD;

    unique_ptr<Dog> pD(new Dog("Gunner"));
    pD->bark();

    Dog* p = pD.release();       
    // released object will NOT be destroyed
    // returns a raw pointer ( like shared_ptr get() function )

    // pD.reset(new Dog("Smokey"));
    // pD.reset();      // <=> pD = nullptr
    // reset object will be destroyed

    if (!pD) {
        cout << "pD is empty.\n";
    } else
        cout << "pD is not empty\n";
}

void f(unique_ptr<Dog> p) {
    p->bark();
}

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> p(new Dog("Smokey"));
    return p;   // return by value // move semantics
}

void test2() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
    unique_ptr<Dog> pD2(new Dog("Smokey"));

    pD2->bark();
    // transfer ownership from one unique_ptr to another unique_ptr
    pD2 = move(pD);
    // 1. Smokey is destroyed.
    // 2. pD becomes empty.
    // 3. pD2 owns Gunner.

    pD2->bark();

    unique_ptr<Dog[]> dogs(new Dog[3]);
    // dogs[1].bark();
    // (*dogs).bark(); // * is not defined
}

void test3() {
    // prevent resource leak even when constructor fails
}

int main() {
    // test(); 
    test2();
}