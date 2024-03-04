//############################################################################
// Stream - Manipulators
//############################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <complex>
#include <iomanip>

using namespace std;

// ostream& endl(ostream& sm) {
//     sm.put('\n');
//     sm.flush();
//     return sm;
// }

// ostream& ostream::operator<<(ostream& (*func)(ostream&)){
//     return (*func)(*this);
// }

int main() {
    cout << "Hello, world!" << endl; // endl: '\n' + flush
    // Object? Build-in data? Function?
    // -> Function!

    cout << ends;
    cout << flush;
    cin >> ws;

    cout << setw(8) << left << setfill('_') << 99 << endl;
    cout << hex << showbase << 14;

}