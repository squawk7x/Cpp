//############################################################################
// String - String and Algorithms
//############################################################################

#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    // count,

    // Member functions
    // erase, insert, replace

    //           0123456789012345678901234567
    string s1 = "Variety is the spice of life";
    cout << s1 << endl;
    int num = count(s1.begin(), s1.end(), 'e');                                          // 4
    num = count_if(s1.begin(), s1.end(), [](char c) { return (c <= 'e' && c >= 'a'); }); // 6

    s1 = "Goodness is better than beauty";
    string::iterator itr = search_n(s1.begin(), s1.begin() + 20, 2, 's'); // itr -> first 's'
    s1.erase(itr, itr + 5);           // "Goodne better than beauty"
    s1.insert(itr, 3, 'x');           // "Goodnexxx better than beauty"
    s1.replace(itr, itr + 3, 3, 'y'); // "Goodneyyy better than beauty"

    // Algorithm functions
    is_permutation(s1.begin(), s1.end(), s1.begin());
    replace(s1.begin(), s1.end(), 'e', ' '); // "Goodn yyy b tt r than b auty"
    transform(s1.begin(), s1.end(), s1.begin(), [](char c) {
        if (c < 'n')
            return 'a';
        else
            return 'z';
    }); // s2: azzazazzzaaazzazazaazaaaazzz

    s1 = "abcdefg";
    rotate(s1.begin(), s1.begin() + 3, s1.end()); // s1: defgabc

    string s;
    u16string s9; // string char16_t
    u32string s8; // string char32_t
    wstring s0;   // string wchar_t
    // to_wstring();

    return 0;
}