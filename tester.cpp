#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    int i{0};

    const int *p1 = &i;
    *(p1++);
    cout << *p1 << endl;

    int* const p2 = &i;
    *(p2++);
    cout << *p2 << endl;

    return 0;
}