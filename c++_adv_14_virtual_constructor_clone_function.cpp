// ***********************************************
// Virtual Constructor - clone Function
// ***********************************************

#include <iostream>
#include <string>
using namespace std;

class Dog {
    virtual Dog* clone() {
        return new Dog(*this); // co-variant return type
    }
};

class Yellowdog : public Dog {
    virtual Yellowdog* clone() {
        return new Yellowdog(*this);
    }
};

void foo(Dog* d) { // d is a yellow dog
    // Dog* c = new Dog(*d); // c is a dog
    Dog* c = d->clone(); // c is a yellow dog
}

int main(int argc, char* argv[]) {
    Yellowdog d;
    foo(&d);
    return 0;
}