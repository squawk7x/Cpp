
// ***********************************************
// unique_ptr
// ***********************************************

// Unique Pointers: exclusive ownership (<-> shared pointers)
// out of scope or starts to own another object -> original object automatically deleted
// light weight smart pointer

#include <iostream>
#include <memory>

using namespace std;

class Bone {};

class Dog {
    // Bone* pB;
    // unique_ptr<Bone> pB;
    // prevents memory leak even when constructor fails
public:
    string m_name;
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    Dog() {
        // pB = new Bone();
        cout << "Nameless dog created." << endl;
        m_name = "nameless";
    }
    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    ~Dog() {
        // delete pB;
        cout << "dog is destroyed: " << m_name << endl;
    }
};

void test() {
    // old fashion way:
    // Dog* pD = new Dog("Gunner");
    // pD->bark();
    /* pD does a bunch of different things, not thread safe:
        - may be goes back to main function prematurely
        - may be throwing an exception
        => pD will not be deleted
    */
    // delete pD;

    unique_ptr<Dog> pD(new Dog("Gunner"));
    pD->bark();

    // Dog* p = pD.get();   // will not give up ownership
    Dog* p = pD.release();
    // pD has given up ownership of the dog
    // released object will NOT be destroyed => memory LEAK
    // returns a raw pointer ( like shared_ptr get() function )

    // pD.reset(new Dog("Smokey"));
    // pD.reset();
    // <=> pD = nullptr
    // original object "Gunner" will be destroyed

    if (!pD) {
        cout << "pD is empty.\n";
    } else
        cout << "pD is not empty\n";
}

void test2() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
    unique_ptr<Dog> pD2(new Dog("Smokey"));

    pD2->bark();
    // transfer ownership from one unique_ptr to another unique_ptr
    pD2 = move(pD);
    // 1. Smokey is destroyed.
    // 2. pD becomes empty.
    // 3. pD2 owns "Gunner".

    pD2->bark();

    unique_ptr<Dog[]> dogs(new Dog[3]);
    // dogs[1].bark();
    // (*dogs).bark(); // * is not defined
}

void f(unique_ptr<Dog> p) { p->bark(); }
// when p goes out of scope the moved dog is destroyed

unique_ptr<Dog> getDog() {
    unique_ptr<Dog> p(new Dog("Smokey"));
    return p; // p returned by value ==> use move semantics
}

void test3() {
    unique_ptr<Dog> pD(new Dog("Gunner"));
    f(move(pD)); // "Gunner will be destroyed inside the f function"
    if (!pD) {
        cout << "pD is empty" << endl;
    }

    unique_ptr<Dog> pD2 = getDog();
    // if pD2 goes out of scope "Smokey" will be destroyed

    // shared_ptr<Dog> dogs(new Dog[3], [](Dog* p) { delete[] p; });
    unique_ptr<Dog[]> dogs(new Dog[3]);
    // template parameter of unique_ptr can be an array
    // unique_ptr is partially specialized for array
}

int main() {
    // test();
    // test2();
    test3();
}