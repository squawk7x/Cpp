//############################################################################
// String - Non-Member Functions Algorithms
//############################################################################

#include <iostream>
#include <string>

using namespace std;

int main() {
    // cout, cin, getline, toString, stoi, stod, stof
    // stringstream functions
    // lexical_sort
    string s1 = "abcdef";
    cout << s1;
    cin >> s1;

    getline(cin, s1);      // default delimiter of '\n';
    getline(cin, s1, ';'); // delimiter is ';'

    // ...
    // lexical_sort();
}