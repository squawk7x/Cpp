// ***********************************************
// RAII
// ***********************************************

/* Resource Acquisition is Initialization (RAII)
 *
 * Use objects to manage resources:
 * 	memory, hardware device, network handle, etc.
 */

#include <iostream>
#include <memory>
#include <mutex>
#include <random>
#include <string>

using namespace std;

std::mutex m;

void func() {}

bool random_ok() {
    std::random_device rd;
    std::mt19937 gen(rd());
    // Standard mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> dis(0, 1);
    // Distribution for 0 and 1

    // Generate a random number (0 or 1)
    int random_value = dis(gen);

    // Convert the random number to a boolean value
    return static_cast<bool>(random_value);
}

void bad() {
    m.lock(); // acquire the mutex
    func();   // if func() throws an exception, the mutex is never released
    if (!random_ok())
        return; // early return, the mutex is never released
    m.unlock(); // if bad() reaches this statement, the mutex is released
}

void good() {
    std::lock_guard<std::mutex> lk(m);
    // RAII class: mutex acquisition is initialization
    func();
    // if f() throws an exception, the mutex is released
    if (!random_ok())
        return;
    // early return, the mutex is released
}
// if good() returns normally, the mutex is released

// void functionA() {
//     Mutex_lock(&mu);
//    // ...                // Do a bunch of things
//     Mutex_unlock(&mu);   // Will this line always be executed?
// }

/*
 * Solution:
 */

// Define global mutex

// std::mutex mu;

// Define a lock class
// class Lock {
// private:
//     std::mutex* m_pm;

// public:
//     explicit Lock(std::mutex* pm) : m_pm(pm) {
//         m_pm->lock();
//     }

//     ~Lock() {
//         m_pm->unlock();
//     }
// };

// void functionA() {
//     Lock mylock(&mu);
//     // Do a bunch of things
// }

// int main(int argc, char* argv[]) {
//     // Use the mutex directly in main or other functions
//     {
//         Lock lock(&mu);
//         // Critical section
//     }

//     return 0;
// }
// The mutex will always be released when mylock is destroyed from stack

/* Conclusion:
 *
 * The only code that can be guaranteed to be executed after exception is
 * thrown are the destructor of objects residing on the stack.
 *
 * Resource management therefore needs to be tied to the lifespan of
 * suitable objects in order to gain automatic deallocation and reclamation.
 */

/* Note 1:
 * Another good example of RAII:
 * tr1:shared_ptr C++ 03
 * C++ 11: std::shared_ptr
 */

// #include <memory> // for std::shared_ptr
// #include <iostream>

// class Dog {};
// class Trick {};

// void train(std::shared_ptr<Dog> pd,
//            const Trick& dogtrick){cout << "bark" << endl ;}; // Pass Trick by const reference

// Trick getTrick() {
//     Trick t;
//     // Some logic to initialize t
//     return t;
// }

// int main() {
//     std::shared_ptr<Dog> pd(new Dog());
//     train(pd, getTrick());
//     // Assuming getTrick() returns a Trick object
//     return 0;
// }

// Question: What's the problem with above code:

// What happens in train()'s parameter passing:
// 1. new dog();
// 2. getTrick();
// 3. construct tr1::shared_ptr<dog>.
// The order of these operations are determined by compiler.

// Conclusion: Don't combine storing objects in shared pointer with other statement.

/* Note 3:
   What happens when resource management object is copied?
*/
//    Lock L1(&mu);
//    Lock L2(L1);

/* Solution 1:
 * Prohibit copying. To see how to disallow copy constructor and copy
 * assignment operator from being used, watch my another session:
 * Disallow Compiler Generated Functions.
 */

/* Solution 2:
 * Reference-count the underlying resource by using shared_ptr
 */

class dog {};

int main(int argc, char* argv[]) {
    std::shared_ptr<dog> pd(new dog());

    return 0;
}
