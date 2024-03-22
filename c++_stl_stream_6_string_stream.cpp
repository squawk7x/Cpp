//############################################################################
// Stream - String stream
//############################################################################

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    stringstream ss; // stream without IO channels/operations
    // read from a string / write to a string

    ss << 89 << " Hex: " << hex << 89 << " Oct: " << oct << 89; // format string with stringstream
    cout << ss.str() << endl;                                   // 89 Hex: 59 Oct: 131

    int a, b, c;
    string s1;

    // 89 Hex: 59 Oct: 131
    ss >> hex >> a; // Formatted input works token by token.
    // tokens separated byspaces, tabs, newlines
    //  a == 137

    ss >> s1;       // s1: "Hex:"
    ss >> dec >> b; // b == 59

    ss.ignore(6);   // ignore next 6 characters of the stream
    ss >> oct >> c; // c == 89

    cout << a << " " << b << " " << c << endl;

    // stringstream can both, format input and ouput

    // more specialized:
    // better type safety:
    // better code readability:
    // ostringstream -- only for formatted output
    // istringstream -- only for formatted input
}