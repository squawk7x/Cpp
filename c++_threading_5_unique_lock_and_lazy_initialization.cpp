//############################################################################
// Unique Lock and Lazy Initialization
//############################################################################

/*
3 ways of locking:
------------------
1. mu.lock() / mu.unlock() (not recommended)
2. lock_guard<mutex> locker(mu)	// can be called once
3. std::unique_lock<mutex> ulocker(mu, std::defer_lock) 
	// do sth else
	ulocker.lock();
	// ...
	ulocker.unlock();

	// -> can be locked multiple times
	// -> finer graned lock
	// -> performance not as good as with lock_guard
*/

#include <iostream>
#include <fstream>
#include <string>
#include <memory>
#include <thread>
#include <mutex>

using namespace std;

// class LogFile {
// 	std::mutex m_mutex;
// 	ofstream f;
// public:
// 	LogFile() {
// 		f.open("log.txt");
// 	}
// 	void shared_print(string id, int value) {
// 		//m_mutex.lock();  // lock before lock_guard is created
// 		//std::lock_guard<mutex> locker(m_mutex, std::adopt_lock);
// 		std::unique_lock<mutex> locker(m_mutex, std::defer_lock);
//         // do sth else
//         // now lock:
// 		locker.lock();  // Now the mutex is locked
// 		// f << "From " << id << ": " << value << endl;
// 		cout << "From " << id << ": " << value << endl;
//         locker.unlock(); // Unlock
// 	}
// };

// Objects cannot be copied but can be moved: thread, packaged_task, fstream, unique_ptr
// unique_lock
// mutex can neither be copied nor moved

// /* unique_lock for transferring mutex ownership */

class LogFile {
	std::mutex m_mutex;
	ofstream f_;
public:
	LogFile() {
		f_.open("log.txt");
	}
	void shared_print(string id, int value) {
		// std::lock_guard<std::mutex> locker(m_mutex);
		std::unique_lock<std::mutex> locker(m_mutex, std::defer_lock);
		// do sth. else
		locker.lock();
		// f_ << "From " << id << ": " << value << endl;
		cout << "From " << id << ": " << value << endl;
		locker.unlock();

		// unique_lock can be moved
		// std::unique_lock<mutex> locker2 = std::move(locker);
	}
};

int main() {
	LogFile log;

	log.shared_print("from main", 42);
   
	return 0;
}


// class LogFile {
// 	std::mutex m_mutex;
// 	ofstream f_;
// public:
// 	LogFile() {
// 		f_.open("log.txt");
// 	}
// 	unique_lock<mutex> giveMeLock() {
// 		return unique_lock<mutex>(m_mutex);  // Moved
// 	}
// 	void shared_print(string id, int value) {
// 		std::unique_lock<mutex> locker(m_mutex);
// 		// f_ << "From " << id << ": " << value << endl;
// 		cout << "From " << id << ": " << value << endl;
// 	}
// };

// int main() {
// 	LogFile log;
// 	unique_lock<mutex> locker = log.giveMeLock();
//    // I don't want to shared_print anything, but I don't want anybody else to do that either untill I am done.

//    // I can also release the lock before locker is destroyed
//    locker.unlock();  // lock_guard can't unlock

//    //...
//    // allow other thread to use log

//    locker.lock();  // lock again. -- finer grained lock alows more resource sharing

// 	return 0;
// }

/* Lock for Initialization */
// class LogFile {
//     std::mutex m_mutex;
//     ofstream _f;

// public:
//     void shared_print(string id, int value) {
//         if (!_f.is_open()) { // lazy initialization
//             std::unique_lock<mutex> locker(m_mutex);
//             _f.open("log.txt"); // This must be synchronized
//         }
//         _f << "From " << id << ": " << value
//            << endl; // I don't care this is not synchronized
//     }
// };

// Problem: log.txt could be opened multiple times by other threads

// class LogFile {
// 	std::mutex m_mutex;
// 	ofstream f;
// public:
// 	void shared_print(string id, int value) {
// 		if (!f.is_open()) {   // lazy initialization   -- A
// 			std::unique_lock<mutex> locker(m_mutex);
//          if (!f.is_open()) {
// 			   f.open("log.txt");   // This must be synchronized  -- B
//          }
// 		}
// 		f << "From " << id << ": " << value << endl;  // I don't care this is not synchronized
// 	}
// };
// // Double-checked locking
// // Problem: race condition between point A and point B

// // C++ 11 solution:
// class LogFile {
//    static int x;
// 	std::mutex m_mutex;
// 	ofstream f;
// 	std::once_flag m_flag;
// 	void init() { f.open("log.txt"); }
// public:
// 	void shared_print(string id, int value) {
//       std::call_once(m_flag, &LogFile::init, this); // init() will only be called once by one thread
// 		//std::call_once(m_flag, [&](){ f.open("log.txt"); });  // Lambda solution
// 		//std::call_once(_flag, [&](){ _f.open("log.txt"); });  // file will be opened only once by one thread
// 		f << "From " << id << ": " << value << endl;
// 	}
// };
// int LogFile::x = 9;

// Note: once_flag and mutex cannot be copied or moved.
//       LogFile can neither be copy constructed nor copy assigned.

// static member data are guaranteed to be initialized only once.

// std::recursive_mutex
// A mutex can be locked multiple times (it must be released multiple times also)
