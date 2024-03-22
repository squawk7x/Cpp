//############################################################################
// Stream - Buffer
//############################################################################

// IO operation
// 1. formatting data                        -- stream
// 2. communicating data to external devices -- stream buffer

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    cout << 34 << endl;             // stream
    streambuf* pbuf = cout.rdbuf(); // pointer to internal model of stream buffer

    ostream myCout(pbuf); // other ostream which has same streambuffer as cout
    myCout << 34;         // myCout has same transferring channel as cout   // 34 to stdout

    myCout.setf(ios::showpos); // useful for temporarily change format of myCout, but not cout
    myCout.width(20);          // default align to the right
    myCout << 12 << endl;      //            +12
    cout << 12 << endl;        // 12

    ofstream of("myLog.txt");
    streambuf* origBuf = cout.rdbuf();
    cout.rdbuf(of.rdbuf()); // Redirecting cout to myLog.txt
    cout << "Hello" << endl; // mylog.txt has "Hello"

    // Restoring
    cout.rdbuf(origBuf);
    cout << "Goodbye" << endl; // stdout has "Goodbye"

    // Stream buffer iterator
    istreambuf_iterator<char> i(cin);
    ostreambuf_iterator<char> o(cout);

    // Echo input to output:
    while (*i != 'x') {
        *o = *i;
        ++o;
        ++i;
    }

    // Echo input to output:
    copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(),
         ostreambuf_iterator<char>(cout));
}