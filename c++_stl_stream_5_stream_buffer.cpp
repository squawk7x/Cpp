//############################################################################
// Stream - Buffer
//############################################################################

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// IO operation
// formatting data -- stream
// communicating data to external devices -- stream buffer

int main(int argc, char* argv[]) {
    cout << 34 << endl;
    streambuf* pbuf = cout.rdbuf();

    ostream myCout(pbuf);
    myCout << 34; // 34 to stdout

    myCout.setf(ios::showpos);
    myCout.width(20);
    myCout << 12 << endl;
    cout << 12 << endl;

    ofstream of("myLog.txt");
    streambuf* origBuf = cout.rdbuf();
    cout.rdbuf(of.rdbuf());
    cout << "Hello" << endl; // mylog.txt has "Hello"
    // Redirecting

    cout.rdbuf(origBuf);
    cout << "Goodbye" << endl; // stdout has "Goodbye"

    // Stream buffer iterator
    istreambuf_iterator<char> i(cin);
    ostreambuf_iterator<char> o(cout);

    while (*i != 'x') {
        *o = *i;
        ++o;
        ++i;
    }

    copy(istreambuf_iterator<char>(cin), istreambuf_iterator<char>(), ostreambuf_iterator<char>(cout));
}