//############################################################################
// Reverse Iterator and Iterator
//############################################################################

#include <algorithm>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> void print_container(T container) {
    typename T::iterator it;
    std::cout << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << " }" << std::endl;
}

// Two ways to declare a reverse iterator
// reverse_iterator<vector<int>::iterator> ritr;
// vector<int>::reverse_iterator ritr;

// Traversing with reverse iterator

// int main() {
//     vector<int> vec = {4, 5, 6, 7};
//     reverse_iterator<vector<int>::iterator> ritr;

//     for (ritr = vec.rbegin(); ritr != vec.rend(); ritr++)
//         cout << *ritr << endl; // prints: 7 6 5 4

//     return 0;
// }

// vector<int>::iterator itr;
// vector<int>::reverse_iterator ritr;

// ritr = vector<int>::reverse_iterator(itr);
// other way around is NOT woking:
// itr = vector<int>::iterator(ritr);  // Compile Error
// itr = ritr.base();

// C++ Standard: base() returns current iterator

vector<int> vec = {1, 2, 3, 4, 5};

int main() {
    print_container(vec);

    vector<int>::reverse_iterator ritr = find(vec.rbegin(), vec.rend(), 3);
    cout << (*ritr) << endl; // 3

    vector<int>::iterator itr = ritr.base();
    cout << (*itr) << endl; // 4
                            // see picture: itr and ritr diff by 1 position

    // Inserting
    vec = {1, 2, 3, 4, 5};
    // vec.insert(ritr, 9); // vec: {1,2,3,9,4,5}
    // or: (ritr and ritr.base() have same result)
    vec = {1, 2, 3, 4, 5};
    vec.insert(ritr.base(), 9); // vec: {1,2,3,9,4,5}
    print_container(vec);

    vec = {1, 2, 3, 4, 5};
    ritr = find(vec.rbegin(), vec.rend(), 3);
    print_container(vec);

    // Erasing
    // vec.erase(ritr); // vec: {1,2,4,5}
    // or
    vec = {1, 2, 3, 4, 5};
    vec.erase(ritr.base()); // vec: {1,2,3,5}
    print_container(vec);
}