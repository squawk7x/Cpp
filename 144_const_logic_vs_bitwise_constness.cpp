#include <vector>

using std::vector;

/*
If you want to allow logical constiness use keyword mutable
*/

class BigVector {
    vector<int> v;
    // int accessCounter;
    mutable int accessCounter; // var can be changed in const FUNCTION

    int *v2;

public:
    int getItem(int index) const {
        accessCounter++;
        return v[index];
    }

    // void setV2Item(int index, int x) {       // compiles
    void setV2Item(int index, int x) const { // compiles
        *(v2 + index) = x;

        // Quiz:
        // const *int const fun(const int *const& p) const
    }
};

int main() {
    BigVector b;
}