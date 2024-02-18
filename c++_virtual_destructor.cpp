#include <iostream>
#include <string>
#include <memory>

using namespace std;


/*
Note:

destructor from base class must be virtual or use shared_pointer.
Only shared_pointer can be used.
unique_pointer will only invoke base class' destructor.

All classes in STL have no virtual destructor.
So be careful inheriting from them!

Use shared_ptr as much as possible.

*/

class Dog {
public:
    // ~Dog() { cout << "Dog destroyed" << endl; }
    virtual ~Dog() {
        cout << "Dog destroyed" << endl;
    } // either use virtual destructor or use sared_pointer
    virtual void bark() {
    }
};

class Yellowdog : public Dog {
public:
    ~Yellowdog() {
        cout << "Yellowdog destroyed" << endl;
    }
};

class DogFactory {
public:
    // static Dog *createYellowdog() {
    // return (new Yellowdog());
    // }
    static shared_ptr<Dog> createYellowdog() {
        return shared_ptr<Yellowdog>(new Yellowdog());
    }
};

int main(int argc, char* argv[]) {
    // Dog *pd = DogFactory::createYellowdog();
    shared_ptr<Dog> pd = DogFactory::createYellowdog();

    // delete pd;   
    // shared pointer ist responsible for destruction

    return 0;
}

