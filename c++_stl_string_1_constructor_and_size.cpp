//############################################################################
// String - Constructor and Size
//############################################################################

#include <iostream>
#include <string>

using namespace std;

int main() {
    // constructors
    string s1("Hello");
    string s2("Hello", 3); // s2: Hel // 3 is size
    string s3(s1, 2);      // s3: llo // 2 is starting position
    string s4(s1, 2, 2);   // s4: ll // starting position, size
    string s5(5, 'a');
    string s6({'a', 'b', 'c'});

    // Size
    s1 = "Goodbye";
    s1.size();
    s1.length();     // Synonymous, both return 7
    s1.capacity();   // size of storage space currently allocated to s1
    s1.reserve(100); // 100 chars
    // reserve does not work on content or on size of a string:
    s1.reserve(5);      // s1: Goodbye, s1.size() == 7, s1.capacity() == 7
    s1.shrink_to_fit(); // shrink the capacity to fit the content
                        // resize does not work on content a string:
    s1.resize(9);       // s1: Goodbye\0\0
    s1.resize(12, 'x'); // s1: Goodbye\0\0xxx, s1.size() == 12
    s1.resize(3);       // s1: Goo
}