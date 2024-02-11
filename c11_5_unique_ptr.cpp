#include <iostream>
#include <memory>

// using namespace std;

// std::make_unique<T> implemented from C++14
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

void foo(std::unique_ptr<int>& i) {
    (*i)++;
}

int main() {
    auto pointer = make_unique<int>(10);
    foo(pointer);
    std::cout << "get: " << pointer.get() << std::endl;
    // No use_count() function for unique_ptr
    std::cout << "use_count: N/A" << std::endl; 
    // pointer.reset();

    // Dereferencing a null unique_ptr is undefined behavior
    // Always check if the pointer is not null before dereferencing
    if (pointer != nullptr)
        std::cout << *pointer << std::endl; // This line should not be executed
    return 0;
}
