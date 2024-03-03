//############################################################################
// Object Slicing
//############################################################################

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <deque>
#include <algorithm>

using namespace std;

class Dog {
public:
    virtual void bark() {
        cout << "I don't have a name." << endl;
    }
};

class YellowDog : public Dog {
    string m_name;

public:
    YellowDog(string name) : m_name(name) {
    }
    void bark() {
        cout << "My name is " << m_name << endl;
    }
};

void foo(Dog d) {
}

int main() {
    deque<Dog> dog;
    YellowDog yellowDog("Gunner");

    dog.push_front(yellowDog); // first copy construct dog from yellowDog
    dog[0].bark();      // dog[0] is a dog NOT yellowDog
    // object slicing, m_name is sliced away

    // Solution: use pointer:
    deque<Dog*> dog2;
    YellowDog yellowDog2("Gunner");
    dog2.push_front(&yellowDog); // passed by reference
    dog2[0]->bark();      // virtual void bark();
    // dog[0] is a yellow dog

    Dog dog2 = yellowDog;
    foo(yellowDog); // yellowDog is slices and passed to foo
}

/*
void foo(Dog* d) {  
	YellowDog* py = dynamic_cast<YellowDog*>(d);
	cout << py->m_name << endl;
}

foo(&yellowDog);

class Dog { 
	public:
	virtual ~Dog();
};
*/

/*
 * STL containers always copy objects.
 */

// vector<int> vec;
// int x = 45;
// vec.push_back(x);
// vec.insert(vec.begin(), x);

//Solution: shared_ptr
//

/*
 *  Functor cannot be passed by reference.
 */

// class MyFunctor {
// public:
//     int val;
//     void operator()(int i) {
//         cout << "Operating on " << i << endl;
//     }
// };

// int main() {
//     unordered_set<int> us = {2, 4, 5, 1, 9};
//     MyFunctor f;
//     for_each(us.begin(), us.end(), f);
//     //for_each<unordered_set<int>::iterator, MyFunctor&>(us.begin(), us.end(), f);
// }

// Problem with passing by value: Slicing!!!

// Conclusion 1: functors should not be polymorphic!

// Conclusion 2: functors should be lightweight

// Solution:
//     Pimpl Idiom
