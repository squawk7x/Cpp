#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

// Functor:

template <typename T> void print_container(T container) {
    typename T::iterator it;
    cout << "{ ";
    for (it = container.begin(); it != container.end(); it++) {
        cout << *it << ", ";
    }
    cout << " }" << endl;
}
class Lsb_less {
public:
    bool operator() (int x, int y) const {
        return (x % 10) < (y % 10);
    }
};

int main() {
    set<int, Lsb_less> s = {21, 23, 26, 27};
    print_container(s);

    set<int, Lsb_less>::iterator itr1, itr2;

    // algorithm
    itr1 = find(s.begin(), s.end(), 36); // s.end()
    if (itr1 != s.end()) {
        cout << "Found using algorithm: " << *itr1 << endl;
    } else {
        cout << "Not found using algorithm" << endl;
    }

    // set::find()
    itr2 = s.find(36); // 26
    if (itr2 != s.end()) {
        cout << "Found using set::find(): " << *itr2 << endl;
    } else {
        cout << "Not found using set::find()" << endl;
    }

    return 0;
}

