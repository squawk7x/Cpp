
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

        cout << of.good() << std::endl;
        cout << of.bad() << std::endl;
        cout << of.fail() << std::endl;
        cout << of.eof() << std::endl;
        cout << of.flags() << std::endl;
    }
}