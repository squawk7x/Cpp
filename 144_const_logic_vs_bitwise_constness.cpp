#include <vector>

using std::vector;

class BigVector {
    vector<int> v;
    // int accessCounter;
    mutable int accessCounter;

    int* v2;

public:
    int getItem(int index) const {
        accessCounter++;
        return v[index];
    }
};

int main() {
    BigVector b;
}