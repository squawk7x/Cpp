//############################################################################
// Thread Management
//############################################################################

#include <iostream>
#include <thread>
using namespace std;

// First example:
void thread1() {
    std::cout << "\nHello, World\n" << std::endl;
}

// int main() {
//     std::thread t1(thread1);

//     for (int i = 0; i < 100; i++) {
//         cout << "from main: " << i << std::endl;
//     }

//     t1.join();

//     return 0;
// }

// int main() {
//     std::thread t1(thread1);

//     try {
//         for (int i = 0; i < 10; i++) {
//             cout << "from main: " << i << std::endl;
//         }
//     } catch (std::exception& e) {
//         t1.join();
//         // Handle exception if needed
//         std::cerr << "Exception caught: " << e.what() << std::endl;
//     }
//     t1.join(); // Join the thread after the try-catch block

//     return 0;
// }

// // other approach: using RAII
// // creating a Wrapper class
// class Wrapper {
//     std::thread t;

// public:
//     template <typename Func>
//     Wrapper(Func&& func) : t(std::forward<Func>(func)) {}
//     ~Wrapper() {
//         if (t.joinable()) {
//             t.join();
//         }
//     }
// };

// class Fctor {
// public:
//     void operator()() { 
//         for (int i=0; i>-100; i--){
//             cout << "from functor: " << i << endl;
//         }
//     }
// };

// int main() {
//     Fctor fct;
//     Wrapper w(fct);

//     for (int i = 0; i < 100; i++) {
//         cout << "from main: " << i << std::endl;
//     }

//     return 0;
// }

// thread object can use any callable object: function, Functor, lambda function

class Fctor {
public:

    void operator()(string& msg) { // try with-out &
        cout << "thread says: " << msg << endl;
        msg = "Thrust is the mother of deceit";
    }
};

/*
std::ref
parent and child are sharing the same memory (string s).
*/

int main() {
    string s = "Where there is no thrust, there is no love";
    Fctor fct;
    // std::thread t1(fct);         // let's save a line of code ->
    // std::thread t1(Fctor());     // would be treated as function declaration
    // std::thread t1((Fctor()), s);   // parameter of thread is ALWAYS passed by value
    std::thread t1(fct, std::ref(s)); // use std::ref to pass by reference
    // std::thread t1(fct, std::move(s)); // s is not available in the main thread

    t1.join();

    cout << "main says: " << s << std::endl;

    return 0;
}

// int main() {
//     cout << std::this_thread::get_id() << std::endl;

//     string s = "Where there is no thrust, there is no love";
//     // if s is not longer needed in main:
//     std::thread t1((Fctor()), std::move(s)); // use std::move
//     cout << t1.get_id() << std::endl;

//     // The trhread object itself can only be moved:
//     // std::thread t2 = std::move(t1);
//     // std::thread t2 = t1; // will not compile
//     cout << t1.get_id() << std::endl;

//     t1.join();

//     cout << "main says: " << s << std::endl;

//     return 0;
// }

// Avoid Oversubscription:
// How many threads should I create to solve a large problem?
// -> cpu cores

// int main() {
//     cout << std::thread::hardware_concurrency() << endl; // Indication -> 8
//     return 0;
// }