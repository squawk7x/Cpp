// ***********************************************
// When to use Tuple
// ***********************************************

#include <iostream>
#include <map>
#include <string>
#include <tuple>
#include <unordered_map>

using namespace std;

// tuple vs struct

tuple<string, int> getNameAge() {
    // ...
    return make_tuple("Bob", 34);
}

int main() {
    struct Person {
        string name;
        int age;
    } p;

    cout << p.name << " " << p.age << endl;

    // why using tuple? (Struct is easier to read)
    tuple<string, int> t;
    cout << get<0>(t) << " " << get<1>(t) << endl;

    // As a one-time only structure to transfer a group of data
    string name;
    int age;
    tie(name, age) = getNameAge();

    // Comparison of tuples
    tuple<int, int, int> time1, time2; // hours, minutes, seconds
    if (time1 > time2)
        cout << " time1 is a later time";

    // Multi index map
    map<tuple<int, char, float>, string> m;
    m[make_tuple(2, 'a', 2.3)] = "Faith will move mountains";
    //  std::unordered_map<std::tuple<int, char, float>, std::string> hashtable;

    // Little trick
    int a, b, c;
    tie(b, c, a) = make_tuple(a, b, c);
    // a, b, c shifted 1 position to the left
}
