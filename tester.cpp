#include <iostream>
#include <string>

using namespace std;

int main() {
    int a = 0;
    int b(1);
    int c{2};

    int& d = a;
    d++;

    int* p = &a;
    ++*p;

    cout << a << " " << b << " " << c << " " << d << endl;

    return 0;
}
