#include <future>
#include <iostream>
#include <thread>

using namespace std;

int factorial(future<int>& f) {

    cout << "in factorial with thread # " << this_thread::get_id() << endl;
    int n = f.get(); // Wait for the value to be set in the associated promise
    cout << "factorial has received the promise." << endl;

    int res = 1;
    for (int i = n; i > 1; i--)
        res *= i;

    return res;
}

int main() {
    int x;

    cout << "in main with thread # " << this_thread::get_id() << endl;

    // Create a promise and get a future associated with it
    promise<int> p;
    future<int> f = p.get_future();

    // Launch a new asynchronous task with factorial function and a reference to the future
    // future<int> fu = async(std::launch::deferred, factorial, ref(f));
    future<int> fu = async(std::launch::async, factorial, ref(f));
    cout << "future launched... " << endl;

    
    // Set the value of the promise
    p.set_value(4);
    cout << "promise made... " << endl;

    // Wait for the result from the child thread
    x = fu.get();

    // Print the result obtained from the child thread
    cout << "Got from child: " << x << endl;

    return 0;
}
