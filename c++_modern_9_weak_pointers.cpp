// ***********************************************
// weak_ptr
// ***********************************************

// weak_ptr has no ownership of the pointed object
// similiar to raw pointer Dog* m_pFriend;
// but 2 levels of protection:
// 1. nobody can use operator 'delete' as possible with raw pointer
// 2. weak_ptr is not always valid -> check if valid:  if (!m_pFriend.expired())

#include <iostream>
#include <memory>

using namespace std;

class Dog {
    // Even with shared pointers Memory leaks are possible
    // shared_ptr<Dog> m_pFriend; // cyclic reference
    weak_ptr<Dog> m_pFriend;
    // weak_ptr has no ownership of the pointed object

public:
    string m_name;

    Dog(string name) {
        cout << "Dog is created: " << name << endl;
        m_name = name;
    }
    ~Dog() { cout << "dog is destroyed: " << m_name << endl; }
    void bark() { cout << "Dog " << m_name << " rules!" << endl; }
    void makeFriend(shared_ptr<Dog> f) { m_pFriend = f; }

    void showFriend() {
        // weak_ptr can NOT be used just like a regular pointer.
        // .lock() creates a shared_ptr out of weak_ptr

        // if a weak_ptr is empty, .lock(); will throw an exception
        if (!m_pFriend.expired())
            // cout << "My friend is: " << m_pFriend->m_name << endl;
            cout << "My friend is: " << m_pFriend.lock()->m_name << endl;
        cout << "... he is owned by " << m_pFriend.use_count() << " pointer(s)." << endl;
    }
};

int main() {
    shared_ptr<Dog> pD(new Dog("Gunner"));
    shared_ptr<Dog> pD2(new Dog("Smokey"));
    pD->makeFriend(pD2);
    pD2->makeFriend(pD);

    pD->showFriend();
}
