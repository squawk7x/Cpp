//############################################################################
/*
 * Public inheritance => "is-a" relation
 *
 * A Derived class should be able to do everything the base class can do.
 */
//############################################################################

// #include <iostream>

// using namespace std;

// class Bird {
// public:
//     void fly(){cout << "I am flying ..." << endl;};
// };

// // class FlyableBird : public Bird {
// // public:
// //     void fly(){cout << "flying" << endl;};
// // };

// class Penguin : public Bird {};

// int main(int argc, char** argv) {
//     Penguin p;
//     p.fly();
// }

//############################################################################

// #include <iostream>

// using namespace std;

// class Dog {
// public:
//     void bark() {
//         cout << "Whoof, I am just a dog.\n";
//     };
// };

// class Yellowdog : public Dog {
// public:
//     void bark() {
//         cout << "Whoof, I am a yellow dog.\n";
//     };
// };

// int main() {
//     Yellowdog* py = new Yellowdog();
//     py->bark();
//     Dog* pd = py;
//     pd->bark();
// }

// OUTPUT : Whoof,
//          I am a yellow dog.Whoof,
//          I am just a dog.

/*
 * Never Override Non-virtual Functions
 */

//############################################################################

// #include <iostream>

// using namespace std;

// class Dog {
// public:
//     void bark(int age) {
//         cout << "I am " << age << " years old.\n" << endl;
//     }
//     virtual void bark(string msg = "just a") {
//         cout << "Whoof, I am " << msg << " dog." << endl;
//     }
// };

// class Yellowdog : public Dog {
// public:
//     using Dog::bark;
//     virtual void bark(string msg = "a yellow") {
//         cout << "Whoof, I am " << msg << " dog." << endl;
//     }
// };

// int main() {
//     Yellowdog* py = new Yellowdog();
//     py->bark(5);
//     // Dog* pd = py;
//     // pd->bark();

// }

// OUTPUT : Whoof,
//          I am a yellow dog.Whoof,
//          I am just a dog.

/*
 * Never redefine default parameter for virtual function
 *   - Default parameters are bound statically;
 *   - Virtual functions are bound dynamically.
 */

/*
 * in class dog, add:

 *  virtual void bark(int age) {
 *      cout << "I am " << age << " years old"<< endl;
 *  }
 *
 * in main(),
 *    py->bark(5);  // Won't compile
 *                  // Can be fixed by adding "using Dog::bark;" in yellow dog
 */

//############################################################################

#include <iostream>
using namespace std;

class Dog {
public:
    virtual void bark() { cout << "I am just a dog.\n"; };
    void run();
};

class Yellowdog : public Dog {
public:
    virtual void barks() { cout << "I am a yellow dog.\n"; };
};

// C++ 11 standard:
// class Yellowdog : public Dog {
// public:
//      virtual void barks() override;      // Compile Error: no function to override
//      virtual void bark() const override; // Compile Error: no function to override
//      void run() override;                // Error
// };

/*
 * Summary of pitfalls:
 * 1. Precise definition of classes;
 * 2. Don't override non-virtual functions;
 * 3. Don't override default parameter values for virtual functions;
 * 4. Force inheritance of shadowed functions. // using B::f()
 * 5. Be careful of typo in function overriding.
 */
//############################################################################
