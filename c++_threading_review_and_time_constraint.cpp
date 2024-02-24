//############################################################################
// Review and Time Constrain
//############################################################################

#include <mutex>
#include <deque>
#include <future>
#include <iostream>
#include <functional>
#include "../../../../../usr/include/c++/11/bits/this_thread_sleep.h"

using namespace std;

int factorial(int N) {
	int res = 1;
	for (int i=N; i>1; i--)
		res *= i;
    std::cout << "Result is: " << res << std::endl;

	return res;
}

int main() {
    /* thread */
    std::thread t1(factorial, 6);
    std::this_thread::sleep_for(chrono::milliseconds(3));
    chrono::steady_clock::time_point tp = chrono::steady_clock::now() + chrono::microseconds(4);
    std::this_thread::sleep_until(tp);

    /* Mutex */
    std::mutex mu;
    std::lock_guard<mutex> locker(mu);
    std::unique_lock<mutex> ulocker(mu);
    ulocker.try_lock();
    ulocker.try_lock_for(chrono::nanoseconds(500));
    ulocker.try_lock_until(tp);

    /* Condition Variable */
    std:condition_variable cond;
    cond.wait_for(ulocker, chrono::microseconds(2));
    cond.wait_until(ulocker, tp);

    /* Future and Promise */
    std::promise<int> p;
    std::future<int> f = p.get_future();
    f.get();
    f.wait();
    f.wait_for(chrono::milliseconds(2));
    f.wait_until(tp);

    /* async() */
    std::future<int> fu = async(factorial, 6);

    /* Packaged Task */
    std::packaged_task<int(int)> t(factorial);
    std::future<int> fu2 = t.get_future();
    t(6);

	 return 0;
}

//  Together with thread library
// 	std::this_thread::sleep_until(steady_clock::now() + seconds(3));

// 	std::future<int> fu;
// 	fu.wait_for(seconds(3));
// 	fu.wait_until(steady_clock::now() + seconds(3));

// 	std::condition_variable c;
// 	std::mutex mu;
// 	std::unique_lock<std::mutex> locker(mu);
// 	c.wait_for(locker, seconds(3));
// 	c.wait_until(locker, steady_clock::now() + seconds(3));
