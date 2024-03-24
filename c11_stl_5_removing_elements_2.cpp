// Summary of Removing Elements:
//
// 1. Vector or deque: algorithm remove() followed by m.erase()
// 2. List: member function m.remove()
// 3. Assoziative Container or Unordered Container: m.erase()
//
// 4. Remove and do something else?

#include <algorithm>
#include <functional>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>
#include "../include/print_container.h"

using namespace std;

bool equalOne(int e) {
    if (e == 1) {
        cout << e << " will be removed" << endl;
        return true;
    }
    return false;
}

bool equalX(int e, int x) {
    if (e == x) {
        cout << e << " will be removed" << endl;
        return true;
    }
    return false;
}

//############################################################################
// Remove and do something else
//############################################################################

// Associative Container:

// int main() {
//     multiset<int> ms = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     multiset<int>::iterator itr;
//     for (itr = ms.begin(); itr != ms.end(); itr++) {
//         if (*itr == 1) {
//             ms.erase(itr);
//             cout << "Erase one item of " << *itr << endl;
//         }
//         // First erase OK; second one is undefined behavior
//     }
// }

// Solution: "Handcrafted loop"
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
            cout << e << " will be removed" << endl;
            return true;
        } else {
            return false;
        }
    });
    v.erase(itr, v.end());
}
