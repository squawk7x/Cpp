#include <iostream>
#include <numeric>
#include <string_view>
#include <vector>

#include "../include/print_container.h"

int main()
{
    std::vector<char> cnt(10);
    std::iota(cnt.begin(), cnt.end(), '0');
    print_container(cnt);

    std::erase(cnt, '3');
    print_container(cnt);

    auto erased = std::erase_if(cnt, [](char x) { return (x - '0') % 2 == 0; });
    print_container(cnt);
    std::cout << "Erased even numbers: " << erased << '\n';
}