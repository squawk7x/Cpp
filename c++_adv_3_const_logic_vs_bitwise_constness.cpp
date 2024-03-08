// ***********************************************
// const Logic vs bitwise Logic
// ***********************************************

/*
If you want to allow logical constness use keyword mutable
*/

#include <vector>

using std::vector;


class BigVector {
    vector<int> v;
    // int accessCounter;
    mutable int accessCounter;
    // var can be changed in const FUNCTION

    int* v2;

public:
    int getItem(int index) const {
        accessCounter++;
        return v[index];
    }

    // void setV2Item(int index, int x) {       // compiles
    void setV2Item(int index, int x) const { // compiles
        *(v2 + index) = x;
        // it does not change any class member directly

        // Quiz:
        // const * int const func (const int *const& p) const
    }
};

int main() {
    BigVector b;
}