#include <iostream>
#include <string>
using namespace std;

/*
Avoid using member functions in constructor unless it is a static function.

*/

class Dog {
public:
    Dog() {
        cout << "Dog born" << endl;
        // bark();  // AVOID virtual function in constructor
    }
    // void bark() {
    //     cout << "I am just a dog" << endl;
    // }
    virtual void bark() {
        cout << "I am just a dog" << endl;
    }
    void seeCat() {
        bark();
    }

    // ~Dog() { bark(); }   
    // same for destructor: AVOID virtual function in destructor

};
class YellowDog: public Dog {
public:
    YellowDog() {
        cout << "Yellow dog born" << endl;
    }
    // virtual is inherited, but good practice to explicitly declare.
    virtual void bark() {
        cout << "I am a yellow dog" << endl;
    }
};

int main(int argc, char* argv[]) {
    YellowDog d;
    d.seeCat();
}