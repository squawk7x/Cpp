// rememb-o-matic
#include <iostream>
#include <new>

using namespace std;

int main() {
    int n;
    int* p;
    cout << "How many numbers would you like to type? ";
    cin >> n;
    p = new (nothrow) int[n];
    if (p == nullptr)
        cout << "Error: memory could not be allocated";
    else {
        for (int i = 0; i < n; i++) {
            cout << "Enter number: ";
            cin >> p[i];
        }
        cout << "You have entered: ";
        for (int i = 0; i < n; i++)
            cout << p[i] << ", ";
        delete[] p;
    }
    return 0;
}