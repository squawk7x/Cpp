#include <iostream>
#include <vector>

template <typename T, typename U>

class MagicType {
public:
    T dark;
    U magic;
    MagicType(T d, U m) : dark(d), magic(m) {}
};

template <typename T> using TrueDarkMagic = MagicType<std::vector<T>, std::string>;

int main() {
    MagicType<int, double> mt(42, 1.23);
    std::cout << "dark: " << mt.dark << ", magic: " << mt.magic << std::endl;

    std::vector<double> myVector = {1, 2, 3};
    TrueDarkMagic<double> tdm(myVector, "Hello, world!");
    std::cout << "dark: " << tdm.dark.size() << ", magic: " << tdm.magic << std::endl;

    return 0;
}
