// overloading operators example
// member operator overloads
#include <iostream>

using namespace std;

class CVector {
public:
    int x, y;
    CVector(){};
    CVector(int a, int b) : x(a), y(b) {}
    CVector operator+(const CVector&);
};

CVector CVector::operator+(const CVector& param) {
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

// non-member operator overloads
CVector operator-(const CVector& lhs, const CVector& rhs) {
    CVector temp;
    temp.x = lhs.x - rhs.x;
    temp.y = lhs.y - rhs.y;
    return temp;
}

// example on this
#include <iostream>
using namespace std;

class Dummy {
public:
    bool isitme(Dummy& param);
};

bool Dummy::isitme(Dummy& param) {
    if (&param == this)
        return true;
    else
        return false;
}

int main() {
    CVector foo(3, 1);
    CVector bar(1, 2);

    CVector result;
    result = foo + bar;
    cout << result.x << ',' << result.y << '\n';

    result = foo - bar;
    cout << result.x << ',' << result.y << '\n';

    Dummy a;
    Dummy* b = &a;
    cout << b, *b;
    if (b->isitme(a))
        cout << "yes, &a is b\n";

    return 0;
}