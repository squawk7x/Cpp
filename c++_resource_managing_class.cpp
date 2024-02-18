#include <string>
#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Person {
private:
    // string *pName_;
    // shared_ptr<string> pName_;
    unique_ptr<string> pName_; // more efficient than shared_ptr
    // but push_back(p) function tries copy, but unique_ptr can not be copied
    // -> std::move(p)

public:
    Person(string name) : pName_(new string(name)) {
    }
    // Person(const Person &) = delete;
    // ~Person() {delete pName_; }  // not needed with shared_ptr
    ~Person() {
    } // when destructor defined, no move constructor generated
    // Move constructor set to default
    Person(Person &&) = default;

    void printName() {
        cout << *pName_;
    }
};

int main() {
    vector<Person> persons;
    // persons.push_back(Person("Georges"));

    // persons.emplace_back("Georges");
    // construct object in place (in the space allocated for vector)
    // No copy or moving was involved

    Person p("George"); // Segmentation fault -> smart pointer
    // persons.push_back(p);
    persons.push_back(move(p));

    //
    persons.front().printName();

    cout << "\nGoodbye" << endl;
}


/*
C++ 11 features:
1. keyword "delete"
2. emplace_back()
3. shared_ptr
4. unique_ptr
5. move()
*/