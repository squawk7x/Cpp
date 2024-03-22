//############################################################################
// String - Member Functions Algorithms
//############################################################################

#include <iostream>
#include <string>

using namespace std;

int main() {
    // copy,
    // find, find_first_of, find_last_of, find_first_not_of, find_last_not_of
    // compare
    string s1 = "abcdefg";
    char buf[20];
    size_t len = s1.copy(buf, 3); // buf: abc len == 3
    // copy exceptional case:
    // (other API is vice versa: first parameter starting point, second parameter size)
    // first parameter size, second parameter starting point:
    len = s1.copy(buf, 4, 2); // buf: cdefg len ==4

    //    0123456789012345678901234567890123456789012345
    s1 = "If a job is worth doing, it's worth doing well";
    size_t found = s1.find("doing");     // found == 18
    found = s1.find("doing", 20);        // found == 36
    found = s1.find("doing well", 0, 5); // found == 18

    found = s1.find_first_of("doing");        // found == 6 // first 'o'
    found = s1.find_first_of("doing", 10);    // found = 13 // look for 'o'
    found = s1.find_first_of("doing", 10, 1); // found = 18 // look for first 'd'

    found = s1.find_last_of("doing");            // found == 40
    found = s1.find_first_not_of("doing");       // found = 0
    found = s1.find_last_not_of("doing", 10, 1); // found = 10

    string s2 = "If a job is worth doing - it's worth doing well";
    s1.compare(s2); // return positive if (s1 > s2); negative if (s1 < s2); 0 if (s1 == s2)
    // if (s1 > s2) {} // <=> if (s1.compare(s2) > 0)
    s1.compare(3, 2, s2); // starts st position 3 and compares only 2 characters

    string ss = s1 + s2; // operator overloading for strings
}