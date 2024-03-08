// ***********************************************
// Ressource Managing Class
// ***********************************************

// a class owns another object by pointer

#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Person {
private:
    string* pName_;

public:
    Person(string name) : pName_(new string(name)) {
    }
    ~Person() {
        delete pName_;
    }
    void printName() {
        cout << *pName_;
    }
};

int main() {
    vector<Person> persons;

    persons.push_back(Person("George"));
    // 1. "George" is constructed.
    // 2. A copy (!) of "George" is saved in the vector persons (shallow copy).
    //          "George" and its copy point to the same pName_
    // 3. "George" ist destroyed. 

    persons.back().printName();
    // points to an object that is already deleted => program crashes

    cout << "\nGoodbye" << endl;
}

// Solution 1:
// class Person {
// private:
//     string* pName_;

// public:
//     Person(string name) : pName_(new string(name)) {
//      // Define copy constructor and copy assignment operator for deep copy assignment//     }
//     Person(const Person& rhs) : pName_(new string(*(rhs.pName_))) {
//     }
//     // Person& operator=(const Person& rhs);
//     ~Person() {
//         delete pName_;
//     }
//     void printName() {
//         cout << *pName_;
//     }
// };

// int main() {
//     vector<Person> persons;

//     persons.push_back(new Person("George"));
//     // 1. George is constructed.
//     // 2. A copy of "George" is saved in the vector persons (shallow copy).
//     // 3. "George" ist destroyed.

//     persons.back().printName();

//     cout << "\nGoodbye" << endl;
// }

// Solution 2: Delete copy constructor and copy assignment operator
//  and define clone() function.
// class Person {
// private:
//     //  C++03: make them private functions and delete function body
//     // Person(const Person& rhs);
//     // Person& operator=(const Person& rhs);
//     string* pName_;

// public:
//     Person(string name) : pName_(new string(name)) {
//     }
//     //  C++11: = delete;
//     Person(const Person& rhs) = delete;
//     Person& operator= (const Person& rhs) = delete;
//     ~Person() {
//         delete pName_;
//     }
//     void printName() {
//         cout << *pName_;
//     }
//     // if you need an copy of an object and have no copy constructor:
//     Person* clone() const {return new Person(*pName_);}
// };

// int main() {
//     // STL containers require containees to have copy constructor and copy assignment
//     // Workaround: save pointers in containers
//     vector<Person*> persons;

//     persons.push_back(new Person("George"));
//     // 1. "George" is constructed.
//     // 2. A copy of "George" is saved in the vector persons (shallow copy).
//     // 3. "George" ist destroyed.

//     persons.back()->printName();

//     cout << "\nGoodbye" << endl;
// }

/*
C++ 11 features:
1. keyword "delete"
2. emplace_back()
3. shared_ptr
4. unique_ptr
5. move()
*/