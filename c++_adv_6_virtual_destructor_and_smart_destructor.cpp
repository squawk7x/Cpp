//############################################################################
// Declare a destructor virtual in polymorphic base classes
//############################################################################

// /* Problem */
// class yellowdog : public dog {
// };

// dog* dogFactory::createDog() {
// 	dog* pd = new yellowdog();
// 	return pd;
// }

// int main() {
// 	dog* pd = dogFactory::createDog();
// 	...
// 	delete pd;  // Only dog's destructor is invoked, not yellowdog's.
// }

#include <iostream>
#include <memory>

using namespace std;

/*
Solution: 
*/
class Dog {
public:
    virtual ~Dog() {
        cout << "dog destroyed" << endl;
    }
};

/* 
Note: All classes in STL have no virtual destructor, so be careful inheriting 
from them.
*/

/*
When we should use virtual destructor:
Any class with virtual functions should have a virtual destructor.

When not to use virtual destructor:
1. Size of the class needs to be small;
2. Size of the class needs to be precise, e.g. passing an object from C++ to C.
*/

class YellowDog : public Dog {
public:
    ~YellowDog() {
        cout << "yellow dog destroyed" << endl;
    }
};

/* Solution 2: 
 *    using shared_prt
 */

class DogFactory {
public:
    //static Dog* createYellowDog() { return (new Yellowdog()); }
    static shared_ptr<Dog> createYellowDog() {
        return shared_ptr<YellowDog>(new YellowDog());
    }
    //static unique_ptr<Dog> createYellowDog() {
    //   return unique_ptr<Yellowdog>(new Yellowdog());
    //}
};

int main() {
    //Dog* pd = DogFactory::createYellowDog();
    shared_ptr<Dog> pd = DogFactory::createYellowDog();
    //unique_ptr<Dog> pd = DogFactory::createYellowDog();

    //delete pd;    // shared_ptr is responsible for deleting
                    // destructor even not required anymore

    return 0;
}
/* Note: you cannot use unique_ptr for this purpose */
