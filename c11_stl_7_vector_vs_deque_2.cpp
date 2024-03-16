//############################################################################
// vector vs deque
//############################################################################

#include <deque>
#include <iostream>
#include <list>
#include <string>
#include <vector>

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
 *     efficient than vector.
 */

/*
 * 2. Memory Availability
 *   Could allocation of large contiguous memory be a problem?
 *   - Limited memory size
 *   - Large trunk of data
 *   - Memory flagmentation
 */

/*
 * 3. Frequency of Unpredictable Growth
 */

// int main() {
//     vector<int> vec;
//     vec.reserve(1);
//     int count = 0;
//     for (int x = 0; x < 1025; x++) {
//         if (vec.size() == vec.capacity()) {
//             count++;
//         }
//         vec.push_back(x); // 11 reallocations performed (growth ratio = 2)}
//     }
//     cout << count << " reallocations performed" << endl;
// }
//   workaround: reserve()

/*
 * 4. Invalidation of pointers/references/iterators because of growth
 */

// int main() {
//     vector<int> vec = {2, 3, 4, 5};
//     int* p = &vec[3];
//     cout << *p << endl;
//     vec.push_back(6); // push_back triggers reallocation
//         // all pointer is INVALIDATED
//     cout << *p << endl; // Undefined behavior

//     deque<int> deq = {2, 3, 4, 5};
//     p = &deq[3];
//     cout << *p << endl; // OK
//     deq.push_back(6);
//     cout << *p << endl; // OK
// }

// push_front() is OK too
// deque: inserting at either END won't invalidate pointers

// Note: removing or inserting in the MIDDLE of a deque
//       also will invalidate pointers/references/iterators

/*
 * 5. Vector's unique feature: portal to C
 */
// C-style function taking a pointer to const int and its size
void c_fun(const int* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Passing data from a vector to C
    vector<int> vec = {1, 2, 3, 4, 5};
    c_fun(&vec[0], vec.size());

    // Passing data from a list to C
    list<int> mylist = {6, 7, 8, 9, 10};
    // Convert list to vector
    vector<int> vec2(mylist.begin(), mylist.end());
    c_fun(&vec2[0], vec2.size());

    // NOTE: &vector[0] can be used as a raw array or pointer.
    // Exception: vector<bool>

    // Example of vector<bool>
    void cpp_fun(const bool* arr, int size);
    vector<bool> bool_vec = {true, true, false, true};
    // cpp_fun(&bool_vec[0], bool_vec.size()); // Compiler Error: &vec[0] is not a bool pointer
    // Workaround: use vector<int> or bitset

    return 0;
}

/*
 * Summary:
 * 1. Frequent push_front()    - deque
 * 2. Built-in data type       - vector
 * 3. Not built-in data type   - deque
 * 4. Contiguous memory        - deque
 * 5. Unpredictable growth     - deque
 * 6. Pointer integrity        - deque
 * 7. Frequently passed to C   - vector
 */
