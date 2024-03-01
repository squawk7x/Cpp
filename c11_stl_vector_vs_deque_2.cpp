//############################################################################
// vector vs deque
//############################################################################

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>

using namespace std;

/*
 * Which one to use?
 *
 * - Need to push_front a lot?  -> deque
 *
 * - Performance is important?   -> vector
 */

/*
 * 1. Element type
 *   - When the elements are not of a trivial type, deque is not much less 
 *    efficient than vector.
 */

/*
 * 2. Memory Availability
 *   Could allocation of large contiguous memory be a problem? 
 *   - Limited memory size
 *   - Large trunk of data
 */

/*
 * 3. Frequency of Unpredictable Growth
 */

// int main() {
//     vector<int> vec;
//     for (int x = 0; x < 1025; x++)
//         vec.push_back(x); // 11 reallocations performed (growth ratio = 2)
// }
//   workaround: reserve()

/*
 * 4. Invalidation of pointers/references/iterators because of growth
 */
// int main() {
//     vector<int> vec = {2, 3, 4, 5};
//     int* p = &vec[3];
//     vec.push_back(6);
//     cout << *p << endl; // Undefined behavior

//     deque<int> deq = {2, 3, 4, 5};
//     p = &deq[3];
//     deq.push_back(6);
//     cout << *p << endl; // OK

//     // push_front() is OK too
//     // deque: inserting at either end won't invalidate pointers

//     // Note: removing or inserting in the middle still will invalidate
//     //       pointers/references/iterators
// }

/*
 * 5. Vector's unique feature: portal to C
 */

void c_fun(const int* arr, int size);

int main() {
    vector<int> vec = {2, 3, 4, 5};

    c_fun(&vec[0], vec.size());

    // Passing data from a list to C
    list<int> mylist;

    vector<int> vec(mylist.begin(), mylist.end());
    c_fun(&vec[0], vec.size());

    // NOTE: &vector[0] can be used as a raw array.
    // Exception: vector<bool>

    void cpp_fun(const bool* arr, int size);
    vector<bool> vec = {true, true, false, true};
    // cpp_fun(&vec[0], vec.size()); 
    // Compiler Error: &vec[0] is not a bool pointer
    // workaround: use vector<int>, or bitset
}

// /*
//  * Summary:
//  * 1. Frequent push_front()    - deque
//  * 2. High performance         - vector
//  * 3. Non-trivial data type    - deque
//  * 4. Contiguous memory        - deque
//  * 5. Unpredictable growth     - deque
//  * 6. Pointer integrity        - deque
//  * 7. Talk to C                - vector
//  */
