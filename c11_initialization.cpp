#include <iostream>
#include <string>
using namespace std;

class DemoInit {
    int num;
    string str;

public:
    DemoInit() {
        cout << "DemoInit{...}" << endl;
    };
    DemoInit(string str) {
        cout << "DemoInit(string str)" << endl;
    }
    DemoInit(int &i) {
        cout << "DemoInit(int &i)" << endl;
    }
    DemoInit(int &&i) {
        cout << "DemoInit(int &&i)" << endl;
    }
    ~DemoInit() {
        cout << "DemoInit destroyed" << endl;
    }
    // DemoInit &operator=(const DemoInit &rhs){
    //     cout << "DemoInit copy operator)"  << endl;
    //     return rhs;}
    DemoInit operator=(DemoInit &&rhs) {
        cout << "DemoInit copy operator)" << endl;
        num = rhs.num;
        str = rhs.str;
    }
};

int main(int argc, char *argv[]) {
    int n = 0;
    DemoInit d1;
    DemoInit d2{"Hello"};
    DemoInit d3{n};
    DemoInit d4{42};

    return 0;
}