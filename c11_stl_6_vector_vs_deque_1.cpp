//############################################################################
// vector vs deque
//############################################################################

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// int main(int argc, char* argv[]) {
//     vector<int> vec = {2, 3, 4, 5};

//     cout << "size: " << vec.size() << endl;
//     cout << "capacity: " << vec.capacity() << endl;

//     vec.push_back(6);

//     cout << "size after pushback of 1 element: " << vec.size() << endl;
//     cout << "capacity after pushback of 1 element: " << vec.capacity() << endl;

//     return 0;
// }

/*
 * Vector Reallocation:
 * 1. A new memory space of 8 int is allocated (Assume growth factor is 2)
 * 2. A new vector is constructed with {2,3,4,5,6} at the new memory space.
 * 3. The old memory is released.
 */

class Dog {};

int main() {
    // Example 1:
    vector<Dog> vec(6); // vec.capacity() == 6, vec.size() == 6,
                        // 6 Dogs created with default constructor
    cout << "vec: size= " << vec.size() << " capacity= " << vec.capacity() << endl;

    // Example 2:
    vector<Dog> vec2; // vec.capacity() >= 0, vec.size() == 0
    vec2.resize(6);   // vec.capacity() >= 6, vec.size() == 6,
                      // 6 Dogs created with default constructor
    cout << "vec2: size= " << vec2.size() << " capacity= " << vec2.capacity() << endl;

    // Example 3:
    vector<Dog> vec3;
    vec3.reserve(6); // vec.capacity() >= 6, vec.size() == 0,
                     // no default constructor invoked
    cout << "vec3: size= " << vec3.size() << " capacity= " << vec3.capacity() << endl;
}

/*
 * Strategy of minimizing reallocation:
 * 1. If the maximum number of item is known, reserve(MAX);
 * 2. If unknown, reserve as much as you can, once all data a inserted,
 *    trim off the rest.
 */

/*
 * deque
 *
 * - No reallocation
 *   deque has no reserve() and capacity()
 *
 * - Slightly slower than vector
 * + more complex data structure
 * + Locality
 *
 */
