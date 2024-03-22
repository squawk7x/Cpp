//############################################################################
// Stream - Manipulators
//############################################################################

#include <bitset>
#include <complex>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// ostream& endl(ostream& sm) { // Manipulator
//     sm.put('\n');
//     sm.flush();
//     return sm;
// }

// ostream& ostream::operator<<(ostream& (*func)(ostream&)){
//     return (*func)(*this);
// }

int main() {
    cout << "Hello, world!" << endl; // endl: '\n' + flush
    // What is 'endl' ?
    // Object? Build-in data? Function?
    // -> Function!

    cout << ends;  // '\0'
    cout << flush; //
    cin >> ws;     // read and discard white spaces

    cout << setw(8) << left << setfill('_') << 99 << endl; // 99______
    cout << hex << showbase << 14;                         // 0xe
}