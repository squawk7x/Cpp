//############################################################################
// object slicing
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
    deque<Dog> dqe;
    YellowDog yd("Gunner");
    dqe.push_front(yd); // passed by value
    dqe[0].bark();      // dqe[0] is a dog
    // object slicing, m_name is sliced away

    // Solution: use pointer:
    deque<Dog*> dqe2;
    YellowDog yd2("Gunner");
    dqe2.push_front(&yd); // passed by reference
    dqe2[0]->bark();      // virtual void bark();
    // dqe[0] is a yellow dog

    Dog d2 = yd;
    foo(yd); // yd is slices and passed to foo
}

/*
void foo(Dog* d) {  
	YellowDog* py = dynamic_cast<YellowDog*>(d);
	cout << py->m_name << endl;
}

foo(&yd);

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
