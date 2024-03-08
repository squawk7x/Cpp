// ***********************************************
// Random Number Distribution
// ***********************************************

#include <iostream>
#include <random>
#include <chrono>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // engine only provides a source of randomness
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    // How to get a random number between 0 and 5?
    cout << e() % 6 << endl;
    //  1. Bad quality of randomness
    //  2. Can only provide uniform distribution

    std::uniform_int_distribution<int> distr(0, 5);
    // range: [0,5]  -- both 1 and 5 are included
    // default param: [0, INT_MAX]
    cout << " int_distribution: " << endl;
    for (int i = 0; i < 30; i++) {
        cout << distr(e) << " ";
    }

    cout << "\n\n real_distribution: " << endl;

    std::uniform_real_distribution<double> distrReal(0, 5);
    // half open: [1, 5)  -- 1 is included, 5 is not.
    // default param: [0, 1)
    for (int i = 0; i < 30; i++) {
        cout << distrReal(e) << " ";
    }

    cout << " poisson_distribution: " << endl;
    std::poisson_distribution<int> distrP(1.0); //  mean (double)
    for (int i = 0; i < 30; i++) {
        cout << distrP(e) << " ";
    }
    cout << endl;

    cout << " normal_distribution: " << endl;
    std::normal_distribution<double> distrN(10.0, 3.0);
    // mean and standard deviation
    vector<int> v(20);
    for (int i = 0; i < 800; i++) {
        int num = distrN(e); // convert double to int
        if (num >= 0 && num < 20)
            v[num]++; // E.g., v[10] records number of times 10 appeared
    }
    for (int i = 0; i < 20; i++) {
        cout << i << ": " << std::string(v[i], '*') << endl;
    }
    cout << endl;

    // Stop using rand()%n;
}

/* Other distributions */
