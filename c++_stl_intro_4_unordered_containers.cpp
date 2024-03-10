//############################################################################
// Unordered Containers
//############################################################################

/*
 *  Unordered Container (C++ 11)
 *   - Unordered set and multiset
 *   - Unordered map and multimap

 *  Order not defined, and may change overtime
 *
 *  Default hash function defined for fundamental types and string.
 *
 *  No subscript operator[] or at()
 *  No push_back(), push_front()
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

#include <iostream>

using namespace std;

//############################################################################
// Unordered set
//############################################################################

// int main() {
//     unordered_set<string> myset = {"red", "green", "blue"};
//     unordered_set<string>::const_iterator itr = myset.find("green"); // O(1)

//     if (itr != myset.end()) // Important check
//         cout << *itr << endl;

//     myset.insert("yellow"); // O(1)

//     vector<string> vec = {"purple", "pink"};
//     myset.insert(vec.begin(), vec.end());

//     // Hash table specific APIs:
//     cout << "load_factor = " << myset.load_factor() << endl;
//     string x = "red";
//     cout << x << " is in bucket #" << myset.bucket(x) << endl;
//     cout << "Total bucket #" << myset.bucket_count() << endl;
// }

// unordered multiset: unordered set that allows duplicated elements
// unordered map: unordered set of pairs
// unordered multimap: unordered map that allows duplicated keys

// hash collision => performance degrade

/* Properties of Unordered Containers:
 * 1. Fastest search/insert at any place: O(1)
 *     Associative Container takes O(log(n))
 *     vector, deque takes O(n)
 *     list takes O(1) to insert, O(n) to search
 * 2. Unorderd set/multiset: element value cannot be changed.
 *    Unorderd map/multimap: element key cannot be changed.
 */

//############################################################################
// Associative Array
// -- map and unordered map
//############################################################################

// void foo(const unordered_map<char, string>& m) {
//     // m['S'] = "SUNDAY";
//     // cout << m['S'] << endl; // m['S'] is write access, not read access
//     auto itr = m.find('S');
//     if (itr != m.end())
//         cout << itr->second << endl;
// }

// int main() {
//     unordered_map<char, string> day = {{'S', "Sunday"}, {'M', "Monday"}};

//     cout << day['S'] << endl;    // No range check
//     cout << day.at('S') << endl; // Has range check

//     vector<int> vec = {1, 2, 3};
//     // vec[5] = 5; // Compile Error

//     day['W'] = "Wednesday";               // Inserting {'W', "Wednesday}
//     day.insert(make_pair('F', "Friday")); // Inserting {'F', "Friday"}

//     // day.insert(make_pair('M', "MONDAY"));
//     // Fail to modify, it's an unordered_map

//     day['M'] = "MONDAY"; // write access to container
//     // Succeed to modify

//     foo(day);
// }

/*
Notes about Associative Array:
1. Search time: unordered_map, O(1); map, O(log(n));
2. Unordered_map may degrade to O(n);
3. Can't use multimap and unordered_multimap, they don't have [] operator.
*/
