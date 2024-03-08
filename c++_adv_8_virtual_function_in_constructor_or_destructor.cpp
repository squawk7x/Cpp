//############################################################################
// virtaul function in constructor or destructor
//############################################################################

#include <string>
#include <iostream>

using namespace std;

class Dog {
public:
    Dog() {
        cout << "dog is born." << endl;
        // bark();// behaves like a non-virtual function in constructor
        // conclusion: avoid virtual function in constructor and destructor
    }

    virtual ~Dog() {
        bark();
        cout << "dog is distroyed." << endl;
    }
    
    // void bark() {
    virtual void bark() {
        cout << "I am just a dog." << endl;
    }

    void seeCat() {
        bark();
    }
};

// virtual is inherited, but good practice to write additionally
// in derived class
class YellowDog : public Dog {
public:
    YellowDog() {
        cout << "yellow dog is born." << endl;
    }
    virtual ~YellowDog() {
        cout << "yellow dog is distroyed." << endl;
    }

    virtual void bark() {
        cout << "I am a yellow dog." << endl;
    }
};

int main() {
    YellowDog yd;
    yd.seeCat();
}
