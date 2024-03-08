// ***********************************************
// Handle self-assignment in operator=
// ***********************************************

/*
 * Operator overload: exploite people's intuition and reduce their learning curve

 dog dd;
 dd = dd;   //looks silly

 dogs[i] = doogs[j]; // looks less silly, but dog[i] and dog[j] may be same object
 */

#include <iostream>
#include <string>
using namespace std;

// Solution 1:
/* Implementing Assignment Operator */
class Collar {};

class Dog {
    Collar* pCollar;

public:
    Dog() {
        pCollar = new Collar();
    }
    Dog& operator=(const Dog& rhs) {
        // not just: 
        // delete pCollar;
        // pCollar = new Collar(*rhs.pCollar);
        // if lhs == rhs, rhs collar is deleted

        if (this == &rhs)
            return *this;
            
        // additionally: make it exception safe:
        // delete only after a new collar was created successfully
        Collar* pOrigCollar = pCollar;  
        pCollar = new Collar(*rhs.pCollar);
        delete pOrigCollar;
        return *this;
    }
    ~Dog() {
        if (pCollar != nullptr)
            delete pCollar;
    }
};

/* Solution 2: Delegation */
class DogD {
    Collar* pCollar;

public:
    DogD() {
        pCollar = new Collar();
    }
    DogD& operator=(const DogD& rhs) {
        // no need to check if (lhs == rhs), copy anyway
        *pCollar = *rhs.pCollar; // member by member copying of Collars or
                                 // call Collar's operator=
        return *this;
    }
    ~DogD() {
        if (pCollar != nullptr)
            delete pCollar;
    }
};

int main(int argc, char* argv[]) {
    Dog dog, dog1;
    dog = dog1;

    DogD dogD, dogD1;
    dogD = dogD1;

    return 0;
}
