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

    // convert a number into a string
    s1 = to_string(8);
    s1 = to_string(2.3e7); // s1: 23000000.000000
    s1 = to_string(0xa4); // s1: 164
    s1 = to_string(034); // s1: 28
    
    // convert a string into a number
    s1 = "190";
    int i = stoi(s1);

    s1 = "190 monkeys";
    size_t pos;
    i = stoi(s1, &pos); // i:190 pos == 3

    s1 = "a monkey";
    // i = stoi(s1, &pos); // exception of invalid_argument
    i = stoi(s1, &pos, 16); // i: 10, a is interpreted as a hex number

    // sto functions do only simple string conversion
    // stol, stod, stof, etc

    // more complex data formatting
    // stringstream

    // other: lexical_cats for simple string conversion
}