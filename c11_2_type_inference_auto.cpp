#include <vector>

// int add(auto x, auto y) {        // from C++20
//     return x + y;
// }

// auto auto_arr2[10] = {arr}; // illegal, can't infer array type

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto i = 5;              // i as int
    auto arr = new auto(10); // arr as int *

    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
    }
    for (auto it = vec.cbegin(); it != vec.cend(); ++it) {
    }
}