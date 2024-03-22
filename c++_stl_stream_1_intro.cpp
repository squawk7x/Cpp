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

    // What is 'serial'?
    string s = "Hello";
    s[3] = 't'; // Random access
    // random access does not work for serial interface:
    // cout[3] = 'r'; // Error
    { // in a certain scope, a file is opened, when scope is constructed , RAII technique
        ofstream of("myLog.txt"); // Creates new file with write access, if file does not exist
        of << "Expirience is the mother of wisdom."
           << endl;                       // overloaded for string, writes a string into the file
        of << 234 << endl;                // overloaded for int, writes an int into the file
        of << 2.3 << endl;                // overloaded for double, writes a double into the file
        of << bitset<8>(14) << endl;      // ..., 00001110
        of << complex<int>(2, 3) << endl; // ..., (2,3)
    } 
    // in a certain scope, a file is closed, when scope is destructed, RAII technique

    // IO Operation:
    // formatting the data <-----> communication the data with external devices

    // stream class provides a common API for formatting the data and IO operations
    //      Software Engineer Principle: LOW COUPLING > Reusability

    return 0;
}
