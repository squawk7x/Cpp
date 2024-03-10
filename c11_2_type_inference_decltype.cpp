#include <iostream>
#include <string>

using namespace std;

template <typename R, typename T, typename U> R add(T x, U y) { return x + y; }

template <typename T, typename U> auto add2(T x, U y) -> decltype(x + y) { return x + y; }

// after c++14
// template <typename T, typename U> auto add3(T x, U y) {
//     return x + y;
// }

int main(int argc, char* argv[]) {
    auto x = 1;
    auto y = 2.0;
    decltype(x + y) z;

    if (std::is_same<decltype(x), int>::value)
        std::cout << "type x == int" << std::endl;
    if (std::is_same<decltype(x), float>::value)
        std::cout << "type x == float" << std::endl;
    if (std::is_same<decltype(x), decltype(z)>::value)
        std::cout << "type z == type x" << std::endl;

    // after c++11
    auto w = add2<int, double>(x, y);
    if (std::is_same<decltype(w), double>::value) {
        std::cout << "w is double: ";
    }
    std::cout << w << std::endl;

    // after c++14
    // auto q = add3<double, int>(1.0, 2);
    // std::cout << "q: " << q << std::endl;

    return 0;
}
