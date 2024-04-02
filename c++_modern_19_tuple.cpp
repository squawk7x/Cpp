// ***********************************************
// Tuple
// ***********************************************

#include "../../../../../usr/include/c++/11/bits/refwrap.h"
#include <algorithm>
#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>

using namespace std;
struct Node {
    char id;
    int value;
    Node(char i, int v) : id(i), value(v) {}
    Node() : id(0), value('z') {}
};

int main() {
std:
    pair<int, string> p = make_pair(23, "hello");
    cout << p.first << " " << p.second << endl;

    // tuple can be considered as extended pair:
    tuple<int, string, char> t(32, "Penny wise", 'a');
    // tuple<int, string, char> t = {32, "Penny wise", 'a'};
    // Wont compile, constructor is explicit

    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;

    // get returns a refenence to the elements of the tuple
    get<1>(t) = "Pound foolish";
    cout << get<1>(t) << endl;

    string& s = get<1>(t);
    s = "Patience is virtue";
    cout << get<1>(t) << endl;
    // get<..> returns reference to the variables in the tuple like
    // subscript operator [] in a vector
    // get<1>(t) is similar to
    // vector<int> v(3);
    // v[1] = 3;

    // get<3>(t);  // Won't compile, t only has 3 fields

    int i = 1;
    // get<i>(t); // Won't compile, i must be a compile time constant

    tuple<int, string, char> t2; // default construction
    t2 = tuple<int, string, char>(12, "Curiosity kills the cat", 'd');
    // easier way:
    t2 = make_tuple(12, "Curiosity kills the cat", 'd');

    if (t > t2) { // lexicographical comparison
        cout << "t is larger than t2" << endl;
    }

    t = t2; // member by member copying

    // Tuple can store references !!
    // STL containers such as vectors cannot.
    // Pair can.
    string st = "In for a penny";
    tuple<string&> t3(st);
    // auto t3 = make_tuple(ref(st));  // Do the same thing
    get<0>(t3) = "In for a pound"; // st has "In for a pound"
    cout << st << endl;
    t2 = make_tuple(12, "Curiosity kills the cat", 'd');

    int x;
    string y;
    char z;
    std::make_tuple(ref(x), ref(y), ref(z)) = t2; // assign t2 to x, y, z
    std::tie(x, y, z) = t2;                       // doing the same thing
    std::tie(x, std::ignore, z) = t2;             // get<1>(t2) is ignored

    // Other features
    auto t4 = std::tuple_cat(t2, t3); // t4 is tuple<int, string, char, string>
    cout << get<3>(t4) << endl;       // "In for a pound"

    // type traits
    cout << std::tuple_size<decltype(t4)>::value << endl; // Output: 4
    std::tuple_element<1, decltype(t4)>::type dd;         // dd is a string
}
