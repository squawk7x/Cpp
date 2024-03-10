//############################################################################
// String - Constructor and Size
//############################################################################

#include <iostream>
#include <string>

using namespace std;

int main() {
    // constructors
    string s1("Hello");
    string s2("Hello", 3);
    string s3(s1, 2);
    string s4(s1, 2, 2);
    string s5(5, 'a');
    string s6({'a', 'b', 'c'});

    // Size
    s1 = "Goodbye";
    s1.size();
    s1.length();        // Synonymous, both return 7
    s1.capacity();      // size of storage space currently allocated to s1
    s1.reserve(100);    // 100 chars
    s1.reserve(5);      // s1: Goodbye, s1.size() == 7, s1.capacity() == 7
    s1.shrink_to_fit(); // shrink the capacity to fit the content
    s1.resize(9);       // s1: Goodbye\0\0
    s1.resize(12, 'x'); // s1: Goodbye\0\0xxx, s1.size() == 12
    s1.resize(3);       // s1: Goo
}