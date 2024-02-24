//############################################################################
// Using callable objects
//############################################################################

#include <string>
#include <iostream>
#include <future>
#include "../../../../../usr/include/c++/11/tr1/functional"

using namespace std;

/* async() are used in the same ways as thread(), bind() */
class A {
public:
    string note;
    void f(int x, char c) {
    }
    long g(double x) {
        note = "changed";
        return 0;
    }
    int operator()(int N) {
        return 0;
    } //Functor
};

int foo(int x) {return 0;}

int main() {
    A a;
    std::thread t1(a, 6);   // copy_of_a() in a different thread
    std::thread t2(std::ref(a), 6); // a() as Functor in a different thread
    std::thread t3(A(), 6); // temp A;
    std::thread t4([](int x){return x*x;}, 6); // temp A;
    std::thread t5(foo, 7);
    std::thread t6(&A::f, a, 8, 'w'); // copy_of_a.f(8, 'w') in a different thread
    std::thread t7(&A::f, &a, 8, 'w'); // a.f(8, 'w') in a different thread
    std::thread t8(std::move(a), 8); // a is no longer usable in parent thread

    // same for:
    // std::async(a, 6);
    // std::bind(a, 6);
    // std::call_once(once_flag, a, 6);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    return 0;
}
