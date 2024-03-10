// ***********************************************
// Disallow Functions
// ***********************************************

#include <iostream>
#include <string>
using namespace std;

// C++03

class OpenFile {
public:
    OpenFile(string filename) { cout << "Open a file " << filename << endl; }

    void destroyMe() { delete this; }

private:
    // in C++11: ... = delete;
    // in C++03 dissallow like this:
    OpenFile(OpenFile& rhs);                  // copy constructor declared but not defined
    OpenFile& operator=(const OpenFile& rhs); // copy assignment operator declared but not defined
    ~OpenFile() { cout << "OpenFile destructed"; } // destructor needs a body
};

int main(int argc, char* argv[]) {
    // OpenFile f(string("Bo_file"));      // Error with private destructor

    // OpenFile f2(f); // Error

    // How to use an object with private destructor?

    OpenFile* f = new OpenFile(string("Bo_file"));

    // f.destroyMe();
    f->destroyMe();

    return 0;
}

/*
An object with private destructor can only be stored on heap not on stack
*/

/*
Summary of disallowing functions:
1. C++11 : f() = delete;
2. C++03 : declare the function private and do not define it.
3. private destructor: stay out of stack.
*/