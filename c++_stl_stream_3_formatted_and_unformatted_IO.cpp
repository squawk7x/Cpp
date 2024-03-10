//############################################################################
// Stream - Formatted and unformatted IO
//############################################################################

#include <bitset>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    cout << 34 << endl;
    cout.setf(ios::oct, ios::basefield);
    cout << 34 << endl;
    cout.setf(ios::showbase);
    cout << 34 << endl;
    cout.setf(ios::hex, ios::basefield);
    cout << 34 << endl;
    cout.unsetf(ios::showbase);
    cout << 34 << endl;
    cout.setf(ios::dec, ios::basefield);

    cout.width(10);
    cout << 26 << endl;
    cout.setf(ios::left, ios::adjustfield);
    cout << 26 << endl;

    // Floating Point Values:
    cout.setf(ios::scientific, ios::floatfield);
    cout << 340.1 << endl;
    cout.setf(ios::fixed, ios::floatfield);
    cout << 340.1 << endl;
    cout.precision(3);
    cout << 340.1 << endl;

    // Input:
    // int i;
    // cin.setf(ios::hex, ios::basefield);
    // cin >> i; // Enter 12 -> 18
    // cout << i << endl;

    cout.flags();
    cout.flags(ios::oct | ios::showbase);

    // Member functions for unformatted IO:
    { // input
        ifstream inf("myLog.txt");
        char buf[80];

        inf.get(buf, 80);
        inf.getline(buf, 80);
        inf.read(buf, 80);
        inf.ignore(3);
        inf.peek(); //
        inf.unget();
        inf.get();
        inf.gcount();

        // output
        ofstream of("myLog.txt");
        of.put('c');
        of.write(buf, 6);
        of.flush();
    }
}