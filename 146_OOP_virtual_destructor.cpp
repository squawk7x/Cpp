#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Dog {
public:
    // ~Dog() { cout << "Dog destroyed" << endl; }
    ~Dog() {
        cout << "Dog destroyed" << endl;
    }
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

int main(int argc, char *argv[]) {
    // Dog *pd = DogFactory::createYellowdog();
    shared_ptr<Dog> pd = DogFactory::createYellowdog();

    // delete pd;
    return 0;
}

/*
Note:
All classes in STL have no virtual destructor, so be careful inheriting from them.
Use shared_ptr as much as possible.
*/