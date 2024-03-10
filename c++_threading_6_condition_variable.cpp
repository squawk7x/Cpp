//############################################################################
// Condition Variable
//############################################################################

#include <condition_variable>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>

using namespace std;

std::deque<int> q;
std::mutex mu;

// void function_1() {
// 	int count = 10;
// 	while (count > 0) {
// 		std::unique_lock<mutex> locker(mu);
// 		q.push_front(count);
// 		locker.unlock();
// 		std::this_thread::sleep_for(chrono::seconds(1));
// 		count--;
// 	}
// }

// void function_2() {
// 	int data = 0;
// 	while ( data != 1) {
// 		std::unique_lock<mutex> locker(mu);
// 		if (!q.empty()) {
// 			data = q.back();
// 			q.pop_back();
// 			locker.unlock();
// 			cout << "t2 got a value from t1: " << data << endl;
// 		} else {
// 			locker.unlock();
// 		}
// 		std::this_thread::sleep_for(chrono::milliseconds(10));
// 	}
// }

// Using conditional variable and mutex
std::condition_variable cond;

void function_1() {
    int count = 10;
    while (count > 0) {
        std::unique_lock<mutex> locker(mu);
        q.push_front(count);
        cout << "producing value: " << count << endl;
        locker.unlock();
        //  cond.notify_all();
        cond.notify_one();
        //   ^^^^^^^^^^ Notify one waiting thread, if there is one.
        std::this_thread::sleep_for(chrono::seconds(1));
        count--;
    }
}

void function_2() {
    int data = 0;
    while (data != 1) {
        std::unique_lock<mutex> locker(mu);
        // cond.wait(locker);  // can wake up by itself: spurious wake
        cond.wait(locker, []() { return !q.empty(); });
        //  ^^^^^ Unlock mu and wait to be notified relock mu
        data = q.back();
        q.pop_back();
        locker.unlock();
        cout << "t2 got a value from t1: " << data << endl;
    }
}

// It is hard to set the sleep time.
int main() {
    std::thread t1(function_1);
    std::thread t2(function_2);
    t1.join();
    t2.join();
    return 0;
}
