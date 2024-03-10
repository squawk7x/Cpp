// ***********************************************
// Regular Expression 3
// ***********************************************

#include <iostream>
#include <regex>
#include <string>

using namespace std;

/**************** Regex Iterator ******************/

int main() {
    string str = "boq@gmail.com; boqian@hotmail.com; bo_quian2000@163.com";

    regex e("([[:w:]]+)@([[:w:]]+)\\.com");

    sregex_iterator pos(str.cbegin(), str.cend(), e);
    sregex_iterator end;
    // Default constructor defines past-the-end iterator

    cout << "=============================\n";

    for (; pos != end; pos++) {
        cout << "Matched:  " << pos->str(0) << endl;
        cout << "user name: " << pos->str(1) << endl;
        cout << "Domain: " << pos->str(2) << endl;
        cout << "=============================\n";
    }
}

// /**************** Regex Token Iterator ******************/

// int main() {
//     string str = "boq@yahoo.com, boqian@gmail.com; bo@hotmail.com";

//     //regex e("[[:punct:]]+");  // Printable character that is not space, digit, or letter.
//     //regex e("[ [:punct:]]+");
//     regex e("([[:w:]]+)@([[:w:]]+)\\.com");

//     sregex_token_iterator pos(str.cbegin(), str.cend(), e, 0);
//     sregex_token_iterator
//         end; // Default constructor defines past-the-end iterator

//     cout << "=============================\n";
//     for (; pos != end; pos++) {
//         cout << "Matched:  " << *pos << endl;
//         cout << "=============================\n";
//     }
// }

// /**************** regex_replace ******************/

// int main() {
//     string str = "boq@yahoo.com, boqian@gmail.com; bo@hotmail.com";

//     // regex e("([[:w:]]+)@([[:w:]]+)\\.com");
//     regex e("([[:w:]]+)@([[:w:]]+)\\.com",
//             regex_constants::grep | regex_constants::icase);

//     //cout << regex_replace(str, e, "$1 is on $2");
//     cout << regex_replace(
//         str, e, "$1 is on $2",
//         regex_constants::format_no_copy | regex_constants::format_first_only);
//     cout << regex_replace(str, e, "$1 is on $2");
// }
