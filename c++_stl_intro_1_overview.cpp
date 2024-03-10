//############################################################################
//  STL: Standard Template Library
//  Data Structures and Algorithms
//############################################################################

/*
 * STL Headers
 */
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

vector<int> vec;

// int main() {
//     vec.push_back(4);
//     vec.push_back(1);
//     vec.push_back(8); // vec: {4, 1, 8}

//     vector<int>::iterator itr1 = vec.begin();
//     // half-open:  [begin, end)
//     vector<int>::iterator itr2 = vec.end();

//     for (vector<int>::iterator itr = itr1; itr != itr2; ++itr)
//         cout << *itr << " "; // Print out:  4 1 8

//     sort(itr1, itr2); // vec: {1, 4, 8}
// }

// iterator is a class, but behaves like a regular pointer.
// algorithm does not directly work on container, but on iterator.
// e.g. sort(itr1, itr2);

// /*
//  * Reasons to use C++ standard library:
//  * 1. Code reuse, no need to re-invent the wheel.
//  * 2. Efficiency (fast and use less resources). Modern C++ compiler are usually
//  *    tuned to optimize for C++ standard library code.
//  * 3. Accurate, less buggy.
//  * 4. Terse, readable code; reduced control flow.
//  * 5. Standardization, guarenteed availability
//  * 6. A role model of writing library.
//  * 7. Good knowledge of data structures and algorithms.
//  */
