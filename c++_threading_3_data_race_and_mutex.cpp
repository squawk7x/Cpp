//############################################################################
// Data Race and Synchronization
//############################################################################

#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

// std::mutex mu;

// void shared_print(string msg, int id) {
//     std::lock_guard<std::mutex> guard(mu);
//     // RAII = Ressource Acquisition Is Initialization technique
//     // whenever the guard goes out of scope, the mutex mu will always be unlocked
//     // with or without exception.

//     // Another problem:
//     // other programs still have access to cout ressource

//     // mu.lock();
//     cout << msg << id << endl; // if exception occurs mu will never unlock -> lock_guard
//     // mu.unlock();
// }

// void function_1() {
//     for (int i = 0; i > -100; i--) {
//         // cout << "from t1: "	<< i << endl;
//         shared_print(string("from t1: "), i);
//     }
// }

// int main() {
//     std::thread t1(function_1);

//     for (int i = 0; i < 100; i++) {
//         // cout << "from main: " << i << endl;
//         shared_print(string("from main: "), i);
//     }

//     t1.join();

//     return 0;
// }

/*
 * 1. Avoid global variables (cout)
 * 2. Mutex should bundle together with the resource it is protecting.
 */

class LogFile {
    std::mutex m_mutex;
    ofstream f;

public:
    LogFile() { f.open("log.txt"); } // Need destructor to close file
    void shared_print(string id, int value) {
        std::lock_guard<mutex> locker(m_mutex);
        f << "from " << id << ": " << value << endl;
    }
    // Never return f to the outside world
    ofstream& getStream() { return f; }
    // Never pass f as argument to user provided function
    void processf(void fun(ofstream&)) { fun(f); }
};

void function_1(LogFile& log) {
    for (int i = 0; i > -100; i--) {
        log.shared_print(string("from t1: "), i);
    }
}

int main() {
    LogFile log;
    // Fctor fctor(log);
    std::thread t1(function_1, std::ref(log));

    for (int i = 0; i < 100; i++)
        log.shared_print("from main: ", i);

    t1.join();

    return 0;
}

// /* the ofstream will not be protected if it is leaked out */
// // Example: add a LogFile method:
// 	ofstream* getStream() {
// 		return &f;
// 	}
// // main():
// 	ofstream* fs = log.getStream();
// 	*fs << "ddummy" << endl;  // Unprotected access

// // A more hidden leakage:
// 	void formated_print(function<ofstream (ofstream&)> usrFunc){
// 		std::lock_guard<mutex> locker(m_mutex);
// 		usrFunc(f);
// 	}

// /* Important: Do not let your user work on protected data directly */

/* Interface is not thread safe */
// class Stack {
//     int* _data;
//     std::mutex _mu;

// public:
//     // void pop();  // pops off the item on top of the stack
//     int& pop();
//     int& top(); // returns the item on top
//                 //...
// };

// void process(int& value) {} 

// void function_1(Stack& st) {
//     int v = st.pop();
//     // st.pop();
//     process(v);
// }

/*	Summary: Avoiding Data Race:
1. Use mutex to synchronize data access;
2. Never leak a handle of data to outside
3. Design interface appropriately.
*/