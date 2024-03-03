//############################################################################
// Assoziative Containers
//############################################################################

/* 
    Always sorted, default criteria is <
    No push_back(), push_front()
 */

#include <vector>
#include <deque>
#include <list>
#include <set>           // set and multiset
#include <map>           // map and multimap
#include <unordered_set> // unordered set/multiset
#include <unordered_map> // unordered map/multimap
#include <iterator>
#include <algorithm>
#include <numeric> // some numeric algorithm
#include <functional>

#include <iostream>

using namespace std;

//############################################################################
// Set
//############################################################################

int main() {
    set<int> myset;

    myset.insert(3); // myset: {3}
    myset.insert(1); // myset: {1, 3}
    myset.insert(7); // myset: {1, 3, 7},  O(log(n))

    set<int>::iterator it;
    it = myset.find(7); // O(log(n)), it points to 7
    // Sequence containers don't even have find() member function

    // The insertion function returns a pair of values
    pair<set<int>::iterator, bool> ret;
    ret = myset.insert(3); // no new element inserted
    if (ret.second == false)
        it = ret.first; // "it" now points to element 3
                        // it points to 3

    myset.insert(it, 9); // myset:  {1, 3, 7, 9}   O(log(n)) => O(1)
    // the position where 9 is inserted depends on the value itself.
    // You cannnot decide where 9 will be inserted.
    // if you can provide a hint where element will be inserted => O(log(n)) => O(1)

    myset.erase(it); // myset:  {1, 7, 9}

    myset.erase(7); // myset:  {1, 9}
        // Note: none of the sequence containers provide this kind of erase.

    // ############################################################################
    // Multiset
    // ############################################################################

    // multiset is a set that allows duplicated items
    multiset<int> mymultiset;

    // set / multiset : value of the elements cannot be modified
    // * it = 10; // *it is read-only
}

/* Properties:
    * 1. Fast search: O(log(n))
    * 2. Traversing is slow (compared to vector & deque)
    * 3. No random access, no [] operator.
    */

//############################################################################
// Map
//############################################################################

//  * - No duplicated key
//  */

int main() {
    map<char, int> mymap;
    mymap.insert(pair<char, int>('a', 100));
    mymap.insert(make_pair('z', 200));

    map<char, int>::iterator it = mymap.begin();
    mymap.insert(it, pair<char, int>('b', 300)); // "it" is a hint

    it = mymap.find('z'); // O(log(n))

    // showing contents:
    for (it = mymap.begin(); it != mymap.end(); it++)
        cout << (*it).first << " => " << (*it).second << endl;

    //############################################################################
    // Multimap
    //  -- keys cannot be modified
    //############################################################################

    // multimap is a map that allows duplicated keys
    multimap<char, int> mymmap;

    // map/multimap:
    //  -- keys cannot be modified
    //     type of *it:   pair<const char, int>
    // (*it).first = 'd'; // Error
}

// Associative Containers: set, multiset, map, multimap
//
// What does "Associative" mean?
