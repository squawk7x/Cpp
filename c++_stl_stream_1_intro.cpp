//############################################################################
// Stream - Introduction
//############################################################################

#include <bitset>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // C++ Input/Output Library -- Stream
    cout << "Hello!" << endl;
    // cout: a global object of ostream
    // (typedef basic_ostream<char> ostream)
    // <<: ostream& ostream::operator<< (string v);
    // endl: '\n' + flush

    // What is stream?
    // Serial IO Interface to external devices
    //   file, stdin/stdout, network, etc.

    string s = "Hello";
    s[3] = 't'; // Random access
    // random access does not work for serial interface:
    // cout[3] = 'r'; // Error
    {
        ofstream of("myLog.txt"); // Creates new file with write access, if file does not exist
        of << "Expirience is the mother of wisdom." << endl;
        of << 234 << endl;
        of << 2.3 << endl;
        of << bitset<8>(14) << endl;      // 00001110
        of << complex<int>(2, 3) << endl; // (2,3)
    }
    // in a scope a stream is AUTOMATICALLY opened and closed
    // typical RAII

    // IO Operation:
    // formatting the data <---> communication the data with external devices
    //      Software Engineer Principle: LOW COUPLING > Reusability

    return 0;
}
