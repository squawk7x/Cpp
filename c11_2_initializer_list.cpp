/*
#include <iostream>
#include <vector>

class Foo {
public:
    int value_a;
    int value_b;
    Foo(int a, int b) : value_a(a), value_b(b) {
    }
};

int main() {
    // before C++11
    Foo foo(1, 2);
    std::cout << "foo:" << foo.value_a << ", " << foo.value_b << std::endl;

    int arr[3] = {1, 2, 3};
    std::cout << "arr[0]: " << arr[0] << std::endl;

    std::vector<int> vec = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << std::endl;
    }
    return 0;
}
*/

#include <initializer_list>
#include <vector>
#include <iostream>

class MagicFoo {
public:
    std::vector<int> vec;
    MagicFoo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }

    void foo(std::initializer_list<int> list) {
        for (std::initializer_list<int>::iterator it = list.begin();
             it != list.end(); ++it)
            vec.push_back(*it);
    }

    void printVec() {
        std::cout << "magicFoo: \n";
        for (auto it = vec.begin(); it != vec.end(); ++it)
            std::cout << *it << std::endl;
    }
};

int main() {
    // after C++11
    MagicFoo magicFoo = {1, 2, 3, 4, 5};
    magicFoo.printVec();

    magicFoo.foo({5, 6, 7, 8, 9, 10});
    magicFoo.printVec();
}
