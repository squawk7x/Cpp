//############################################################################
//  Sequence Containers
//############################################################################

#include <iostream>
#include <string>

#include <algorithm>
#include <deque>
#include <functional>
#include <iterator>
#include <list>
#include <map>           // map and multimap
#include <numeric>       // some numeric algorithm
#include <set>           // set and multiset
#include <unordered_map> // unordered map/multimap
#include <unordered_set> // unordered set/multiset
#include <vector>

using namespace std;

//############################################################################
//  Vector
//############################################################################

// int main() {
//     vector<int> vec; // vec.size() == 0

//     vec.push_back(4);
//     vec.push_back(1);
//     vec.push_back(8); // vec: {4, 1, 8};    vec.size() == 3

//     // Vector specific operations:
//     cout << vec[2];    // 8  (no range check)
//     cout << vec.at(2); // 8  (throw range_error exception of out of range)

//     for (int i; i < vec.size(); i++)
//         cout << vec[i] << " ";

//     // Universal way of traversing a container
//     for (vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr)
//         cout << *itr << " ";

//     for (auto it : vec) // C++ 11
//         cout << it << " ";

//     // Vector is a dynamically allocated contiguous array in memory
//     int* p = &vec[0];
//     p[2] = 6;

//     // Common member functions of all containers.
//     // vec: {4, 1, 8}
//     if (vec.empty()) {
//         cout << "Not possible.\n";
//     }

//     cout << vec.size(); // 3
//     vector<int> vec2(vec); // Copy constructor, vec2: {4, 1, 8}
//     vec.clear(); // Remove all items in vec;   vec.size() == 0
//     vec2.swap(vec); // vec2 becomes empty, and vec has 3 items.

//     // Notes: No penalty of abstraction, very efficient.
// }

/* Properties of Vector:
 * 1. fast insert/remove at the end: O(1)
 * 2. slow insert/remove at the begining or in the middle: O(n)
 * 3. slow search: O(n)
 */

//############################################################################
// Deque
//############################################################################

// int main() {
//     deque<int> deq = {4, 6, 7};
//     deq.push_front(2); // deq: {2, 4, 6, 7}
//     deq.push_back(3);  // deq: {2, 4, 6, 7, 3}

//     // Deque has similar interface with vector
//     cout << deq[1]; // 4
// }

/* Properties:
 * 1. fast insert/remove at the begining and the end;
 * 2. slow insert/remove in the middle: O(n)
 * 3. slow search: O(n)
 */

//############################################################################
// List
// -- double linked list
//############################################################################

// int main() {
//     list<int> mylist = {5, 2, 9};
//     mylist.push_back(6);  // mylist: { 5, 2, 9, 6}
//     mylist.push_front(4); // mylist: { 4, 5, 2, 9, 6}

//     list<int>::iterator itr = find(mylist.begin(), mylist.end(), 2); // itr -> 2
//     mylist.insert(itr, 8); // mylist: {4, 5, 8, 2, 9, 6}
//                            // O(1), faster than vector/deque
//     itr++;                 // itr -> 9
//     mylist.erase(itr);     // mylist: {4, 8, 5, 2, 6}   O(1)
// }

/* Properties:
 * 1. fast insert/remove at any place: O(1)
 * 2. slow search: O(n)
 * 3. no random access, no [] operator.
 */

// list killing feature:
// mylist1.splice(itr, mylist2, itr_a, itr_b); // O(1) in constant time!

//############################################################################
// Array
//############################################################################

int main(int argc, char* argv[]) {
    int a[3] = {3, 4, 5};
    array<int, 3> ac = {1, 2, 3};
    array<int, 4> bc = {1, 2, 3, 4}; // different type as ac

    // Array is not a class type
    // a.begin();
    // a.end();
    // a.size();
    // a.swap();

    //  => use Array Container
    ac.begin(); // works
    ac.end();
    ac.size(); // + ac.swap();
    bc = {1, 2, 3};

    /*
    Limitations:
    1. no resize
    2. two arrays may have different types.
    */

    return 0;
}