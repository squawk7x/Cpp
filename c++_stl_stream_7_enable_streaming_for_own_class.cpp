//############################################################################
// Stream - Enable streaming for your own class
//############################################################################

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Creating Stream-enabled class

struct Dog {
public:
    int age_;
    string name_;
};

// Non-member functions (usual way)
ostream& operator<<(ostream& sm, const Dog& d) {
    sm << "My name is " << d.name_ << " and my age is " << d.age_ << endl;
    return sm;
}

istream& operator>>(istream& sm, Dog& d) {
    sm >> d.age_;
    sm >> d.name_;
    return sm;
}

int main() {
    Dog d{2, "Bob"}; // Universal Initialization from C++ 11
    cout << d;

    // Interactive initialization in terminal
    cin >> d;
    cout << d;
}