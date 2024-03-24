//###################################################################
// User defined Literals
//###################################################################

// C++ went a long way to make user defined types (classes) to behave same as buildin types.
// User defined literals pushes this effort even further

/*
 * Literals are constants
 * C++ has 4 kinds of literals:
 *      integer        --- 45
 *      floating point --- 4.5
 *      character      --- 'z'
 *      string         --- "Dog"
 */

/*
    int a = 45      // int
    int b = 45u     // unsigned int (suffix specifies type)
    int c = 45l     // long

    int height = 3.4;   // Meters? Centimeters? Inches?
*/

/*
Restriction: input parameters can only work with the following parameters:

    char const*
    unsigned long long
    long double
    char const*, std::size_t
    wchar_t const*, std::size_t
    char16_t const*, std::size_t
    char32_t const*, std::size_t

Note: return value can be of any type
*/

#include <iostream>
#include <string>
using namespace std;

// C++ 11:
// first example:
constexpr long double operator"" _mm(long double x) { return x; }
constexpr long double operator"" _cm(long double x) { return x * 10; }
constexpr long double operator"" _m(long double x) { return x * 1000; }

// Note: add constexpr to make the translation happen in compile time.
//  Restriction: it can only work with following paramters:
//  char const *unsigned long long long double char const *,
//      std::size_t wchar_t const *, std::size_t char16_t const *,
//      std::size_t char32_t const *,
//      std::size_t
//  Note: return value can be of any types.

// second Example:
// User-defined literal for binary conversion
int operator"" _bin(char const* str, size_t l) {
    int ret = 0;
    for (int i = 0; i < l; i++) {
        ret = ret << 1;    // Shift left by 1 bit
        if (str[i] == '1') // Check for '1' instead of 'l'
            ret += 1;      // Increment by 1
    }
    return ret;
}

// User-defined literal for hexadecimal conversion
int operator"" _hex(const char* str, size_t length) {
    int result = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = str[i];
        int digit;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            // Invalid character
            throw std::invalid_argument("Invalid hexadecimal character");
        }
        result = result * 16 + digit;
    }
    return result;
}

// User-defined literal for octal conversion
int operator"" _oct(const char* str, size_t length) {
    int result = 0;
    for (size_t i = 0; i < length; ++i) {
        char c = str[i];
        if (c < '0' || c > '7') {
            // Invalid character
            throw std::invalid_argument("Invalid octal character");
        }
        result = result * 8 + (c - '0');
    }
    return result;
}

int main(int argc, char* argv[]) {
    // Old C++ 03:
    // long double height = 3.4; // Meters? Centimeters? Inches?

    // Remember in high school physics class?
    // height = 3.4cm;
    // ratio = 3.4cm / 2.1mm;

    // Why we don't do that anymore?
    //  1. No language support
    //  2. Run time cost associated with the unit translation

    long double height = 3.4_cm;
    cout << height << endl;              // 34
    cout << (height + 13.0_m) << endl;   // 13034
    cout << (130.0_mm / 13.0_m) << endl; // 0.01

    cout << "110"_bin << endl;                   // 6
    cout << "1100110"_bin << endl;               // 102
    cout << "110100010001001110001"_bin << endl; // 1712753
    cout << "FF"_hex << endl;                    // 255
    cout << "40"_oct << endl;                    // 32

    return 0;
}
