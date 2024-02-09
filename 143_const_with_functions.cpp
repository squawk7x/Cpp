#include <iostream>
#include <string>

using namespace std;

class Dog {
    int age;
    string name;

public:
    Dog() {
        age = 3;
        name = "dummy";
    }
    // const parameter
    // void setAge(int a) { age = a; a++; }     // local copy
    // void setAge(const int a) { age = a; }    // not so usefull
    void setAge(int &a) { // lvalue
        age = a + 100;
        cout << age << " - non-const" << endl;
        a++;
    }
    void setAge(const int &a) { // rvalue
        age = a;
        cout << age << " - const" << endl;
    }

    // const return value
    // const string getName() { return name; } // const useless, returns a temporary value
    const string &getName() {
        return name;
    } // the caller cannot modify the return

    // const function body
    // void printDogName() const {cout << name << endl; age++; }
    // void printDogName() const {cout << name << endl; }
    void printDogName() const {
        cout << name << " - const" << endl;
    }
    void printDogName() {
        cout << getName() << " - non-const" << endl;
    }
};

int main() {
    int i = 9;
    Dog dog;
    dog.setAge(i);
    dog.setAge(7);
    // cout << i << endl;

    const string &name = dog.getName();
    cout << name << endl;

    Dog d1;
    d1.printDogName();

    const Dog d2;
    d2.printDogName();
}