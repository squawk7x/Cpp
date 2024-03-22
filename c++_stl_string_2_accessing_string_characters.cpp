//############################################################################
// String - Accessing String Characters
//############################################################################

#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1 = "Goodbye";
    s1[2];
    // Accesses the character at index 2 but doesn't do anything with it
    s1[2] = 'x'; // Goxdbye
    // Modifies the character at index 2 to 'x'
    // s1.at(2) = 'y';  // Goydbye
    // Throws an out_of_range exception since index 20 is out of range
    // s1.at(20);
    // Throws an out_of_range exception since index 20 is out of range
    s1[20];
    // Causes undefined behavior since index 20 is out of range
    // ...

    // s1.front, s1.back, s1.push_back s1.begin, s1.end
    // like vector, bur string does not have push_front and pop_front

    // Iterator access of a string:
    string s2(s1.begin(), s1.begin() + 3); // s3: Gox

    // Ranged Access of a string
    // assign, append, insert, replace
    string s3 = "Dragon Land";

    s1.assign(s3);
    s1.assign(s3, 2, 4);        // s1: agon
    s1.assign("Wisdom");        // s1: Wisdom
    s1.assign("Wisdom", 3);     // s1: Wis
    // s1.assign(s2, 3);           // Error
    s1.assign(3, 'x');          // s1: xxx
    s1.assign({'a', 'b', 'c'}); // s1: abc

    s1.append(" def");           // s1: abc def
    s1.insert(2, "mountain", 4); // s1: abmounc def
    s1.replace(2, 5, s2, 3, 3);  // s1: abgon def
    s1.erase(1, 4);              // s1: af
    s1.substr(2, 5);          // s2: agon
    s1 = "abc";
    s1.c_str(); // s1: "abc\0"
    s1.data();  // s1: "abc"
    s1.swap(s2);
}