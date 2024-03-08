// ***********************************************
// Ressource Management Class
// ***********************************************

#include <string>
#include <iostream>
#include <vector>
#include <memory>
#include <deque>

using namespace std;

class Person {
private:
    // string* pName_;
    // shared_ptr<string> pName_;  // C++ 11 solution
    unique_ptr<string> pName_;  // C++ 11 solution

public:
    Person(string name) : pName_(new string(name)) {
    }
    // Person(const Person&) = delete; // copy constructor is deleted
    // ~Person() { delete pName_; }
    ~Person() { }
    Person(Person&&) = default;

    void printName() {
        cout << *pName_;
    }
};

int main() {
    vector<Person> persons; // vector requires containee to be copyable or movable.
    // deque<Person> persons;

    // persons.push_back(Person("George"));
    // // 1. George is constructed.
    // // 2. A copy of "George" is saved in the vector persons (shallow copy).
    // // 3. "George" ist destroyed.

    // persons.emplace_back("George");
    // construct the object in place (in the space allocated to the vector).
    // persons.front().printName();

    Person p("George");
    // persons.push_back(p);
    persons.push_back(move(p)); // unique_ptr is not copyable but moveable
    // if no destructor is defined => compiler generated move constructor used
    // or define a move constructor yourself
    persons.front().printName();

    cout << "\nGoodbye" << endl;
}

/* C++ 03 solution:
 * 1. define copy constructor and copy assignment operator
 * 2. delete copy constructor and copy assignment operator
*/

/* C++ 11:
 * keyword delete
 * emplace_back()
 * shared_ptr
 * unique_ptr
 * move()
 * keyword default
*/
