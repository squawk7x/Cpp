//############################################################################
// Remove from Vector or Deque
//############################################################################

#include <algorithm>
#include <iostream>
#include <list>
#include <set>
#include <string>
#include <vector>

using namespace std;

template <class T> void print_container(T container, string msg) {
    typename T::iterator it;
    cout << msg << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << " }" << std::endl;
}

// int main() {
//     vector<int> vec = {1, 4, 1, 1, 1, 12, 18, 16};
//     print_container(vec, "Original: ");

//     // To remove all '1'
//     for (vector<int>::iterator itr = vec.begin(); itr != vec.end();) {
//         if (*itr == 1) {
//             vec.erase(itr);
//         } else
//             itr++;
//     }
//     print_container(vec, "after removing 1 by vec.erase: ");
//     // vec: { 4, 1, 12, 18, 16}
//     // Complexity: O(n*m) // member function is INEFFICIENT

//     vec = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     remove(vec.begin(), vec.end(), 1);
//     print_container(vec, "after removing 1 by algorithm: ");
//     // vec: {4, 12, 18, 16, ?, ?, ?, ?}
//     // Complexity: O(n)

//     vec = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     vector<int>::iterator newEnd = remove(vec.begin(), vec.end(), 1); // O(n)
//     vec.erase(newEnd, vec.end());
//     print_container(vec, "after vec.erase(): ");
//     cout << "before shrink_to_fit() capacity(): " << vec.capacity() << endl;
//     // Similarly for algorithm: remove_if() and unique()

//     // vec still occupy 8 int space: vec.capacity() == 10
//     vec.shrink_to_fit(); // C++ 11
//     cout << "after shrink_to_fit() capacity(): " << vec.capacity() << endl;
//     // Now vec.capacity() == 5

//     // For C++ 03:
//     vector<int>(vec).swap(vec); // Release the vacant memory
// }

//############################################################################
// Remove from List
//############################################################################

// int main() {
//     list<int> l = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     print_container(l, "Original: ");

//     auto newEnd = remove(l.begin(), l.end(), 1);
//     l.erase(newEnd, l.end());
//     print_container(l, "after erase(): ");

//     l = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
//     l.remove(1); // member function MORE efficient in list
//     print_container(l, "after remove(): ");

//     return 0;
// }

//############################################################################
// Remove from associative containers or unordered containers
//############################################################################

int main() {
    std::multiset<int> mset = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    print_container(mset, "Original");

    // auto newEnd = std::remove(mset.begin(), mset.end(), 1);
    // mset.erase(newEnd, mset.end()); // O(n)
    // print_container(mset, "After remove and erase");

    mset = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    mset.erase(1); // O(log(n)) or O(1)
    print_container(mset, "After direct erase");

    return 0;
}

// Summary of Removing Elements:
//
// 1. Vector or deque: algorithm remove() followed by m.erase()
// 2. List: member function m.remove()
// 3. Assoziative Container or Unordered Container: m.erase()
//
// 4. Remove and do something else? 
