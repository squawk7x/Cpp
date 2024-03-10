#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int>& i) { (*i)++; }
int main() {
    // auto pointer = new int(10); // illegal, no direct assignment
    // Constructed a std::shared_ptr
    auto pointer = make_shared<int>(10);
    foo(pointer);
    cout << "get: " << pointer.get() << endl;
    cout << "use_count: " << pointer.use_count() << endl;
    // pointer.reset();    // count = count -1
    cout << "use_count: " << pointer.use_count() << endl;
    cout << "*pointer: " << *pointer << std::endl; // 11

    // The shared_ptr will be destructed before leaving the scope
    return 0;
}