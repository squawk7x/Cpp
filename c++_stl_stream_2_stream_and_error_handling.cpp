//############################################################################
// Stream - File Stream and Error Handling
//############################################################################

#include <bitset>
#include <complex>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    {
        // ofstream of("myLog.txt"); // open for write, clear content of the file
        ofstream of("myLog.txt", ofstream::app); // open for write for append
        of << "Honesty is the best policy" << std::endl;
    }
    {
        ofstream of("myLog.txt", ofstream::in | ofstream::out);
        of.seekp(10, ios::beg); // Move the output pointer 10 chars after begin
        of << "12345";          // Overwrite 5 chars
        of.seekp(-5, ios::end); // Move the output pointer 5 chars before end
        of << "Nothing ventured, nothing gained" << std::endl;
        of.seekp(-5,
                 ios::cur); // Move the output pointer 5 chars before current pointer
    }
    {
        ifstream inf("myLog.txt");
        int i;
        inf >> i; // read one word
        // Error status: goodbit, badbit, failbit, eofbit
        inf.good(); // Everything is OK (goodbit == 1)
        inf.bad();  // Non-recoverable error (badbit == 1)
        inf.fail(); // failed stream operation (failbit == 1 & badbit == 1)
        inf.eof();  // End of file (eofbit == 1)

        inf.clear();            // clear all the error status, clear (ios::goodbit)
        inf.clear(ios::badbit); // sets a new value to the error flag, bitoperation
        inf.rdstate();          // read the current status flag
        inf.clear(inf.rdstate() & ~ios::failbit); // clear only the failbit

        if (inf) // Equivalent to: if (!inf.fail())
            cout << "Read successfully!" << endl;
        if (inf >> i) // Equivalent to: if (!inf.fail())
            cout << "Read successfully!" << endl;

        // Handle errors with exceptions
        inf.exceptions(ios::badbit | ios::failbit); // setting the exception mask
        // When badbit or failbit is set to 1 exception of ios::failure will be thrown
        // when eofbit is set to 1, no exception will be thrown

        inf.exceptions(ios::goodbit); // no exception will be generated
    }

    return 0;
}