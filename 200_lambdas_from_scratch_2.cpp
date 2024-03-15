#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int g = 10;
auto kitten = []() { return g + 1; }; // auto capture
auto cat = [g = g]() { return g + 1; };

int main() {
    g = 20;
    printf("%d %d\n", kitten(), cat());

    return 0;
}
