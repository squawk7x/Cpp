#include <iostream>
#include <string>
#include <tuple>

using namespace std;

int main(int argc, char* argv[]) {
    std::pair<int, string> p = make_pair(23, "hello from pair");
    cout << p.first << " " << p.second << endl;

    tuple<int, string, char> t(32, "hello from tuple", '!');
    cout << get<0>(t) << endl;
    cout << get<1>(t) << endl;
    cout << get<2>(t) << endl;

    get<1>(t) = "Hello again";
    
    
    return 0;
}

