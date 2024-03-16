#include <initializer_list>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class MyVector {
    vector<int> vec_;

public:
    MyVector(const initializer_list<int>& v) {
        for (initializer_list<int>::iterator i = v.begin(); i != v.end(); ++i) {
            vec_.push_back(*i);
        }
    }
    void show(){
        for (int i : vec_) {
            cout << i << endl;
        }

    }
};


int main() {
    MyVector mv = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    mv.show();
    
    return 0;
}