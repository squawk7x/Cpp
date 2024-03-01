// Summary of Removing Elements:
//
// 1. Vector or deque: algorithm remove() followed by erase()
// 2. List: member function remove()
// 3. Assoziative Container or Unordered Container: erase()
//
// 4. Remove and do something else?

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

template <class T> void print_container(T container, string msg) {
    typename T::iterator it;
    cout << msg << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << " }" << std::endl;
}

bool equalOne(int e) {
    if (e == 1) {
        cout << e << " will be removed" << endl;
        return true;
    }
    return false;
}

//############################################################################
// Remove and do something else
//############################################################################

// Associative Container:
multiset<int> s = {1, 4, 1, 1, 1, 12, 18, 16};

int main() {
    // multiset<int>::iterator itr;
    // for (itr = s.begin(); itr != s.end(); itr++) {
    //     if (*itr == 1) {
    //         s.erase(itr);
    //         cout << "Erase one item of " << *itr << endl;
    //     }
    // }

    // First erase OK; second one is undefined behavior

    //Solution:
    // multiset<int>::iterator itr;
    // for (itr = s.begin(); itr != s.end();) {
    //     if (*itr == 1) {
    //         cout << "Erase one item of " << *itr << endl;
    //         s.erase(itr++);  //  <----------
    //     } else {
    //         itr++;
    //     }
    // }

    // Sequence Container:
    // vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};
    // vector<int>::iterator itr2;
    // for (itr2 = v.begin(); itr2 != v.end();) {
    //     if (*itr2 == 1) {
    //         cout << "Erase one item of " << *itr2 << endl;
    //         v.erase(itr2++);
    //     } else {
    //         itr2++;
    //     }
    // }

    // Sequence container and unordered container's erase() returns
    // iterator pointing to next item after the erased item.

    //Solution:
    // vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};
    // vector<int>::iterator itr2;
    // for (itr2 = v.begin(); itr2 != v.end();) {
    //     if (*itr2 == 1) {
    //         cout << "Erase one item of " << *itr2 << endl;
    //         itr2 = v.erase(itr2); //  <----------
    //     } else {
    //         itr2++;
    //     }
    // }

    // 1. Sequence container and unordered container's erase() returns the next
    //    iterator after the erased item.
    // 2. Associative container's erase() returns nothing.
    //

    // A thing about efficiency: v.end()

    // Use Algorithm
    vector<int> c = {1, 4, 1, 1, 1, 12, 18, 16};
    auto itr = remove_if(c.begin(), c.end(), equalOne);
    c.erase(itr, c.end());

    // Use bind():
    vector<int> w = {1, 4, 1, 1, 1, 12, 18, 16};
    remove_if(w.begin(), w.end(), bind(equalOne, placeholders::_1));

    // Lambda:
    vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};

    auto itr2 = remove_if(v.begin(), v.end(), [](int e) {
        if (e == 12) {
            cout << e << " will be removed" << endl;
            return true;
        } else {
            return false;
        }
    });
    v.erase(itr2, v.end());
}
