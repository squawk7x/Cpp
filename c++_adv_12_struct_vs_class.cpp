// ***********************************************
// struct vs class
// ***********************************************

// Small passive objects that carry public data and have no or few basic member functions. --  data container
struct Person_t {
    string name;
    unsigned age;
};

// Bigger active objects that carry private data, interfaced through public member functions
class Person {
    string name_;
    unsigned age_;

public:
    unsigned age() {
        return age_;
    } // getter / accessor
    void set_age(unsigned a) {
        age_ = a;
    } // setter / mutator
};

int main() {
    Person_t Pt;
    cout << Pt.age;
    Person P;
    cout << P.age();
    P.set_age(4);
}

// Summary:
// 1. Use struct for passive objects with public data, use class for active objects with private data.
// 2. Use setter/getter to access class's data
// 3. Avoid making setter/getter if possible
