// Summary of Removing Elements:
//
// 1. Vector or deque: algorithm remove() followed by erase()
// 2. List: member function remove()
// 3. Assoziative Container or Unordered Container: erase()
//
// 4. Remove and do something else?

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

<<<<<<< HEAD
template <class T> void print_container(T container, string msg) {
    typename T::iterator it;
    cout << msg << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << " }" << std::endl;
=======
template <class T> void print_container(T container, const string& msg) {
    cout << msg << "{ ";
    for (const auto& elem : container) {
        cout << elem << ", ";
    }
    cout << " }" << endl;
>>>>>>> 5970f50 (Stream Tutorial added)
}

bool equalOne(int e) {
    if (e == 1) {
        cout << e << " will be removed" << endl;
        return true;
    }
    return false;
}

<<<<<<< HEAD
=======
bool equalX(int e, int x) {
    if (e == x) {
        cout << e << " will be removed" << endl;
        return true;
    }
    return false;
}
>>>>>>> 5970f50 (Stream Tutorial added)
//############################################################################
// Remove and do something else
//############################################################################

// Associative Container:
<<<<<<< HEAD
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

    // Solution:
    //  multiset<int>::iterator itr;
    //  for (itr = s.begin(); itr != s.end();) {
    //      if (*itr == 1) {
    //          cout << "Erase one item of " << *itr << endl;
    //          s.erase(itr++);  //  <----------
    //      } else {
    //          itr++;
    //      }
    //  }

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

    // Solution:
    //  vector<int> v = {1, 4, 1, 1, 1, 12, 18, 16};
    //  vector<int>::iterator itr2;
    //  for (itr2 = v.begin(); itr2 != v.end();) {
    //      if (*itr2 == 1) {
    //          cout << "Erase one item of " << *itr2 << endl;
    //          itr2 = v.erase(itr2); //  <----------
    //      } else {
    //          itr2++;
    //      }
    //  }

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
=======

// int main() {
//     multiset<int> ms = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     multiset<int>::iterator itr;
//     for (itr = ms.begin(); itr != ms.end(); itr++) {
//         if (*itr == 1) {
//             ms.erase(itr);
//             cout << "Erase one item of " << *itr << endl;
//         }
// First erase OK; second one is undefined behavior
//     }
// }

// Solution:
//  int main() {
//      multiset<int> ms = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//      multiset<int>::iterator itr;
//      for (itr = ms.begin(); itr != ms.end();) {
//          if (*itr == 1) {
//              cout << "Erase one item of " << *itr << endl;
//              ms.erase(itr++); //  <----------
//          } else {
//              itr++;
//          }
//      }
//  }

// Same way to erase elements from vector?

// Sequence Container:
// int main() {
//     vector<int> v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     vector<int>::iterator itr;
//     for (itr = v.begin(); itr != v.end();) {
//         if (*itr == 1) {
//             cout << "Erase one item of " << *itr << endl;
//             v.erase(itr++);
//         } else {
//             itr++;
//         }
//         // only 3 elements of 1 are erased
//         // undefined behavior
//     }
// }

// Sequence container and unordered container's erase() returns
// iterator pointing to next item after the erased item.

// Solution for sequence and unordered container:
//  int main() {
//      vector<int> v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//      vector<int>::iterator itr;
//      for (itr = v.begin(); itr != v.end();) {
//          if (*itr == 1) {
//              cout << "Erase one item of " << *itr << endl;
//              itr = v.erase(itr); //  <----------
//          } else {
//              itr++;
//          }
//      }
//  }

// 1. Sequence container and unordered container's erase() returns the next
//    iterator after the erased item.
//    itr = c.erase(itr)
// 2. Associative container's erase() returns nothing.
//    c.erase(itr++)

// A thing about efficiency: v.end()

// BEST SOLUTION: Use Algorithm + Lambda
int main() {
    vector<int> v;

    v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    auto itr = remove_if(v.begin(), v.end(), equalOne);
    v.erase(itr, v.end());

    // Use bind():
    v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    remove_if(v.begin(), v.end(), bind(equalX, placeholders::_1, 12));

    // Lambda:
    v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    auto itr2 = remove_if(v.begin(), v.end(), [](int e) {
        if (e == 1) {
>>>>>>> 5970f50 (Stream Tutorial added)
            cout << e << " will be removed" << endl;
            return true;
        } else {
            return false;
        }
    });
<<<<<<< HEAD
    v.erase(itr2, v.end());
=======
    v.erase(itr, v.end());
>>>>>>> 5970f50 (Stream Tutorial added)
}
