//############################################################################
// Container's member functions vs algorithms
//############################################################################

// Functions with same name:
// List:
// void remove(const T); template<class Comp> void remove_if(Comp);
// void unique();        template<class Comp> void unique(Comp);
// void sort();          template<class Comp> void sort(Comp);
// void merge(list&);    template<class Comp> void merge(Comp);
// void reverse();

// Associative Container:
// size_type count(const T&) const;
// iterator find(const T&) const;
// iterator lower_bound(const T&) const;
// iterator upper_bound(const T&) const;
// pair<iterator,iterator> equal_range (const T&) const;
// Note: they don't have generalized form, because comparison is defined by
//       the container.

// Unordered Container:
// size_type count(const T&) const;
// iterator find(const T&);
// std::pair<iterator, iterator> equal_range(const T&);
// Note: No generalized form; use hash function to search

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

// unordered_set<int> s = {2, 4, 1, 8, 5, 9}; // Hash table

// unordered_set<int>::iterator itr;

// int main(int argc, char* argv[]) {
//     // Using member function
//     itr = s.find(4); // O(1)
//     cout << *itr << endl;

//     // Using Algorithm
//     itr = find(s.begin(), s.end(), 4); // O(n)
//     cout << *itr << endl;

//     return 0;
// }

// How about map/multimap?

// std::map<char, std::string>::iterator itr;

// int main(int argc, char* argv[]) {
//    std::map<char, std::string>::iterator itr; // Define the iterator type

//     std::map<char, std::string> mymap = {
//         {'S', "Sunday"}, {'M', "Monday"}, {'W', "Wednesday"},
//         {'T', "Thursday"}, {'F', "Friday"}, {'S', "Saturday"}
//     };

//     // Using member function
//     itr = mymap.find('F'); // O(log(n))

//     // Using Algorithm
//     // itr = find(mymap.begin(), mymap.end(), make_pair('F', "Friday")); // O(n)

//     return 0;
// }

// How about list?

std::list<int>::iterator itr;

int main() {
    // Using member function
    list<int> s = {2, 1, 4, 8, 5, 9};
    print_container(s);
    s.remove(4); // O(n)
    cout << "remove 4 by member function: " << endl;
    print_container(s);
    // s: {2,1,8,5,9}

    // Using Algorithm
    list<int> s2 = {2, 1, 4, 8, 5, 9};
    itr = remove(s2.begin(), s2.end(), 4); // O(n)
    cout << "remove 4 by algorithm function: " << endl;
    print_container(s2);
    cout << "after erase: " << endl;
    s.erase(itr, s2.end());
    print_container(s2);

    // Sort
    // Member function
    s.sort();
    cout << "after sort: " << endl;
    print_container(s);

    // Algorithm
    // sort(s.begin(), s.end()); // Undefined behavior

    // list<int>::iterator itr = remove(s.begin(), s.end(), 4);  // O(n)
    // s.erase(itr, s.end());
    // Similarly for algorithm: remove_if() and unique()

    return 0;
}

/*
 * Summary:
 *
 * 1. There are duplicated functions between container's member functions and
 *    algorithm functions.
 * 2. Prefer member functions over algorithm functions with the same names.
 *
 */
