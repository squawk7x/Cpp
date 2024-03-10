// ***********************************************
// Random Number Engine
// ***********************************************

/* Random Engine:
 *    stateful generator that generates random value within predefined min and max.
 *    Not truely random -- pseudorandom
 */

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <sstream>

using namespace std;

// int main ()
// {
//    std::default_random_engine eng;
// 	cout << "Min: " << eng.min() << endl;
// 	cout << "Max: " << eng.max() << endl;

// 	cout << eng() << endl;  // Generate one random value
// 	cout << eng() << endl;  // Generate second random value

// 	std::stringstream state;
// 	state << eng;  // Save the state

// 	cout << eng() << endl;  // Generate one random value
// 	cout << eng() << endl;  // Generate second random value

// 	state >> eng;  // Restore the state
// 	cout << eng() << endl;  // Generate one random value
// 	cout << eng() << endl;  // Generate second random value
// }

/* More examples */
void printRandom(std::default_random_engine e) {
    for (int i = 0; i < 10; i++)
        cout << e() << " ";
    cout << endl;
}

template <typename T> void printArray(T arr) {
    for (auto v : arr) {
        cout << v << " ";
    }
    cout << endl;
}

int main() {
    std::default_random_engine eng;
    printRandom(eng);

    std::default_random_engine eng2;
    printRandom(eng2);

    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e3(seed);
    printRandom(e3);

    eng.seed();    // reset engine to initial state
    eng.seed(109); // set engine to a state according to seed 109

    eng2.seed(109);
    if (eng == eng2) // will return true
        cout << "eng and eng2 have the same state" << endl;

    // cout << "\n\n Shuffling:" << endl;
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vector<int> d(arr, arr + 9);
    // printArray(d);

    // vector<int> d = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // std::shuffle(d.begin(), d.end(), std::default_random_engine());
    // printArray(d);
    // std::shuffle(d.begin(), d.end(),
    //              std::default_random_engine()); // same order
    // printArray(d);

    // std::shuffle(d.begin(), d.end(), eng);
    // printArray(d);
    // std::shuffle(d.begin(), d.end(), eng); // different order
    // printArray(d);
}
