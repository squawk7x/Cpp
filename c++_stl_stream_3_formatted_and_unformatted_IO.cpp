//############################################################################
// Stream - Formatted and unformatted IO
//############################################################################

#include <bitset>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << 34 << endl; // 34
    cout.setf(ios::oct, ios::basefield);
    cout << 34 << endl; // 42
    cout.setf(ios::showbase);
    cout << 34 << endl; // 042
    cout.setf(ios::hex, ios::basefield);
    cout << 34 << endl; // 0x22
    cout.unsetf(ios::showbase);
    cout << 34 << endl; // 22
    cout.setf(ios::dec, ios::basefield);

    cout.width(10);
    cout << 26 << endl;                     //         26
    cout.setf(ios::left, ios::adjustfield); // 26
    cout << 26 << endl;

    // Floating Point Values:
    cout.setf(ios::scientific, ios::floatfield);
    cout << 340.1 << endl; // 3.401000e+002
    cout.setf(ios::fixed, ios::floatfield);
    cout << 340.1 << endl; // 340.10000
    cout.precision(3);
    cout << 340.1 << endl; // 340.100

    // Input:
    // int i;
    // cin.setf(ios::hex, ios::basefield);
    // cin >> i;          // Enter 12
    // cout << i << endl; // i == 18

    ios::fmtflags f = cout.flags();
    cout.flags(ios::oct | ios::showbase);

    // Member functions for unformatted IO:
    { // input
        ifstream inf("myLog.txt");
        char buf[80];

        inf.get(buf, 80);     // read up to 80 chars and save to buf
        inf.getline(buf, 80); // read up to 80 chars or until '\n'
        inf.read(buf, 20);    // read 20 chars
        inf.ignore(3);        //
        inf.peek();           //
        inf.unget();          // return a char back to the stream
        inf.get();            //
        inf.gcount();         // return the number of chars been read by last unformatted read

        // output
        ofstream of("myLog.txt");
        of.put('c');      // put 1 character into the stream
        of.write(buf, 6); // write first 6 chars of buf into the stream
        of.flush();       // flush output
    }
}