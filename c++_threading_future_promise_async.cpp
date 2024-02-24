//############################################################################
// Future, Promise, async()
//############################################################################

#include <iostream>
#include <string>
#include <future>
#include "../../../../../usr/include/c++/11/bits/this_thread_sleep.h"

using namespace std;


// void factorial(int N) {
// 	int res = 1;
// 	for (int i=N; i>1; i--)
// 		res *= i;

// 	cout << "Result is: " << res << endl;
// }

// int main() {
// 	std::thread t1(factorial, 4);
//     t1.join();
// 	return 0;
// }

// int factorial(int N) {
// 	int res = 1;
// 	for (int i=N; i>1; i--)
// 		res *= i;

// 	cout << "Result is: " << res << endl;
//     return res;
// }

// passing value from child to parent:
// int main() {
//     // int x;
// 	future<int> fu = std::async(factorial, 4);   // is same as:
// 	// future<int> fu = std::async(std::launch::deferred | std::launch::async, factorial, 4);
//     // std::launch::async -> new thread
//     // std::launch::deferred -> no new thread
//     // std::launch::deferred | std::launch::async is standard setting
// 	cout << "Got from child thread #: " << fu.get() << endl;
// 	// x = fu.get();  // crash // get() can be called only ONCE
// 	return 0;
// }

// passing value from parent to child:

// /* Asynchronously provide data with promise */
// int factorial(std::future<int>& f) {
// 	// do something else and wait for my promise
// 	int res = 1;

// 	int N = f.get();     
//     // If promise is distroyed, exception: std::future_errc::broken_promise
	
//     for (int i=N; i>1; i--)
// 		res *= i;

// 	cout << "Got from parent: " << N << endl;
// 	cout << "Result is: " << res << endl;
// 	return res;
// }

// int main() {
//     int x;

// // Both promise and future cannot be copied, they can only be moved.
// 	std::promise<int> p;
// 	// std::promise<int> p2;
//     // p2 = std::move(p);

// 	std::future<int> f = p.get_future();
// 	// std::future<int> f2 = p.get_future();
//     // f2 = std::move(f);

// 	std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

// 	// Do something else
// 	std::this_thread::sleep_for(chrono::milliseconds(20));
// 	// p.set_value(4);  // forget to fulfill my promise
// 	//p.set_value(28);  // It can only be set once
// 	p.set_exception(std::make_exception_ptr(std::runtime_error("Flat tire")));

// 	cout << "Got from child: " << fu.get() << endl;
// 	return 0;
// }

/* shared_future */
int factorial(shared_future<int> f) {
	// do something else

	int N = f.get();     // If promise is distroyed, exception: std::future_errc::broken_promise
	f.get();
	cout << "Got from parent: " << N << endl;
	int res = 1;
	for (int i=N; i>1; i--)
		res *= i;

	return res;
}

int main() {
	// Both promise and future cannot be copied, they can only be moved.
	promise<int> p;
	future<int> f = p.get_future();
	shared_future<int> sf = f.share();

	future<int> fu = std::async(std::launch::async, factorial, sf);
	future<int> fu2 = std::async(std::launch::async, factorial, sf);

	// Do something else
	std::this_thread::sleep_for(chrono::milliseconds(20));
	p.set_value(5);

	cout << "Got from child thread #: " << fu.get() << endl;
	cout << "Got from child thread #: " << fu2.get() << endl;
	return 0;
}
