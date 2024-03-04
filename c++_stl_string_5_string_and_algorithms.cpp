//############################################################################
// String - Strings and Algorithms
//############################################################################

#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    // count,

    // Member functions
    // erase, insert, replace

    string s1 = "Variety is the spice of life";
    cout << s1 << endl;
    int num = count(s1.begin(), s1.end(), 'e'); //4
    cout << num << endl;
    num = count_if(s1.begin(), s1.end(),
                   [](char c) { return (c <= 'e' && c >= 'a'); });
    cout << num << endl;

    s1 = "Goodness is better than beauty";
    cout << s1 << endl;
    string::iterator itr =
        search_n(s1.begin(), s1.begin() + 20, 2, 's'); // itr -> first 's'
    cout << *itr << endl;
    s1.erase(itr, itr + 5);
    cout << s1 << endl;
    s1.insert(itr, 3, 'x');
    cout << s1 << endl;
    s1.replace(itr, itr + 3, 3, 'y'); // Replacing substring
    cout << s1 << endl;

    // Algorithm functions
    // is_permutation, replace, transform, rotate
    is_permutation(s1.begin(), s1.end(), s1.begin());
    cout << s1 << endl;
    replace(s1.begin(), s1.end(), 'e', ' '); // Replacing characters
    cout << s1 << endl;
    transform(s1.begin(), s1.end(), s1.begin(), [](char c) {
        if (c < 'n')
            return 'a';
        else
            return 'z';
    });
    cout << s1 << endl;
    s1 = "abcdefg";
    rotate(s1.begin(), s1.begin() + 3, s1.end());
    cout << s1 << endl;

    string s;
    u16string s9;  // string char16_t
    u32string s10; // string char32_t
    wstring s11;   // string wchar_t
    // to_wstring();

    return 0;
}