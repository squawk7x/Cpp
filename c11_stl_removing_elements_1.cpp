//############################################################################
// Remove from Vector or Deque
//############################################################################

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

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
//     // Complexity: O(n*m)

//     vector<int> vec2 = {1, 4, 1, 1, 1, 12, 18, 16};
//     remove(vec2.begin(), vec2.end(), 1);
//     print_container(vec2, "after removing 1 by algorithm: ");
//     // vec: {4, 12, 18, 16, ?, ?, ?, ?}
//     // Complexity: O(n)

//     vector<int>::iterator newEnd = remove(vec2.begin(), vec2.end(), 1); // O(n)
//     vec2.erase(newEnd, vec2.end());
//     print_container(vec2, "after vec.erase(): ");
//     cout << "before shrink_to_fit() capacity(): " << vec2.capacity() << endl;

//     // Similarly for algorithm: remove_if() and unique()

//     // vec still occupy 8 int space: vec.capacity() == 8
//     vec2.shrink_to_fit(); // C++ 11
//     cout << "after shrink_to_fit() capacity(): " << vec2.capacity() << endl;
//     // Now vec.capacity() == 4

//     // For C++ 03:
//     vector<int>(vec).swap(vec2); // Release the vacant memory
// }

//############################################################################
// Remove from List
//############################################################################

// int main() {
//     list<int> mylist = {1, 4, 1, 1, 1, 12, 18, 16};
//     print_container(mylist, "Original: ");

//     auto newEnd = remove(mylist.begin(), mylist.end(), 1);
//     mylist.erase(newEnd, mylist.end());
//     print_container(mylist, "after erase(): ");

//     list<int> mylist2 = {1, 4, 1, 1, 1, 12, 18, 16};
//     mylist2.remove(1); // faster
//     print_container(mylist2, "after remove(): ");

//     return 0;
// }

//############################################################################
// Remove from associative containers or unordered containers
//############################################################################

int main() {

    multiset<int> myset = {1, 4, 1, 1, 1, 12, 18, 16};
    print_container(myset, "Original: ");

    // auto newEnd = remove(myset.begin(), myset.end(), 1);
    // myset.erase(newEnd, myset.end()); // O(n)

    myset.erase(1); // O(log(n)) or O(1)
    print_container(myset, "after erase(): ");

    return 0;
}

// Summary of Removing Elements:
//
// 1. Vector or deque: algorithm remove() followed by erase()
// 2. List: member function remove()
// 3. Assoziative Container or Unordered Container: erase()
//
// 4. Remove and do something else? 