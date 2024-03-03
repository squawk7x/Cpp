//############################################################################
// Equality vs Equivalence
//############################################################################

#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

template <typename T> void print_container(T container) {
    typename T::iterator it;
    std::cout << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        std::cout << *it << ", ";
    }
    std::cout << " }" << std::endl;
}

// Functor:
class Lsb_less {
public:
    bool operator() (int x, int y) const {
        return (x % 10) < (y % 10);
    }
};


int main() {
    set<int, Lsb_less> s = {21, 23, 26, 27};
    print_container(s);

    set<int, Lsb_less>::iterator itr1, itr2;

    // algorithm
    itr1 = find(s.begin(), s.end(), 36); // s.end()
    if (itr1 != s.end()) {
        cout << "Found using algorithm: " << *itr1 << endl;
    } else {
        cout << "Not found using algorithm" << endl;
    }

    // member function set::find()
    itr2 = s.find(36); // 26
    if (itr2 != s.end()) {
        cout << "Found using set::find(): " << *itr2 << endl;
    } else {
        cout << "Not found using set::find()" << endl;
    }

    return 0;
}

// set<int, Lsb_less> s = {21, 23, 26, 27};

//############################################################################
// Algorithm find() looks for equality: if (x == y)  
// itr1 = find(s.begin(), s.end(), 36); // itr1 points to s.end()
//############################################################################


//############################################################################
// set<int>::find() looks for equivalence: if ( !(x<y) && !(y<x) )
// itr2 = s.find(36); // itr2 points to 26
//############################################################################

// Guidelines:
//
// If the function is using operator "<" or its like, it's checking equivalence
//   - Typically it's algorithm that works with sorted data, or a member
//     function of a container with sorted data, such as associative container.
//
// If the function is using operator "==" or its like, it's checking equality
//   - Typically the data is not required to be sorted


// Algorithms of equality:
// search 
// find_end
// find_first_of
// adjacent_search

// Algorithms of equivalence:
// binary_search
// simple forms
// includes 
// lower_bound 
// upper_bound

/*
 * Summary:
 * When using a function to search or remove certain element, make sure you 
 * understand the difference between equality and equivalence.
 *
 */
