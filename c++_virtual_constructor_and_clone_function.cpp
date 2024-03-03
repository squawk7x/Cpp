#include <iostream>
#include <string>

using namespace std;

class Dog {
public:
    virtual Dog* clone() const {
        return new Dog(*this); // co-variant return type
    }
};

class Yellowdog : public Dog {
public:
    virtual Yellowdog* clone() const override {
        return new Yellowdog(*this);
    }
};

void foo(Dog* d) { // d is a Yellowdog
    // Dog* c = new Dog(*d);   // c is a dog => not identical => clone()
    Dog* c = d->clone(); // c is a Yellowdog
}

int main(int argc, char* argv[]) {
    Yellowdog d;
    foo(&d);
}