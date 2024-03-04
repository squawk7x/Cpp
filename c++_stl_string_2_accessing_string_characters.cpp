//############################################################################
// String - Accessing String Characters
//############################################################################

#include <string>
#include <iostream>

using namespace std;

int main() {
    string s1 = "Goodbye";
    s1[2];        
    // Accesses the character at index 2 but doesn't do anything with it
    s1[2] = 'x';  
    // Modifies the character at index 2 to 'x'
    // s1.at(20) = 'y'; 
    // Throws an out_of_range exception since index 20 is out of range
    // s1.at(20);        
    // Throws an out_of_range exception since index 20 is out of range
    s1[20];           
    // Causes undefined behavior since index 20 is out of range
    // ...
    
    // Ranged Access
    // assign, append, insert, replace
    // ...
}