//############################################################################
// Concurrent C++
//############################################################################

#include <iostream>
#include <thread>
using namespace std;

// First example:
void thread1() {
    std::cout << "Hello, World" << std::endl;
}

int main() {
    std::thread t1(thread1);    // t1 starts running
    t1.join(); // main thread wait for t1 to finish
    // t1.detach();  // main thread let t1 to run on its own: t1 is a daemon process.
    // C++ runtime library is responsible returning t1's resources
    // and main thread may finish before t2 prints "Hello"
    // once detached - forever detached! You cannot t1.join(); again!
    // t1.join(); // crash

    if (t1.joinable())
        t1.join();

    return 0;
}

// If neither detach nor join is called, terminate() will be called for the t1.
// A thread can only be joined once or detached once. After it is joined on detached
// it becomes unjoinable ( t.joinable() returns false )

