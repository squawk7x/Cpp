//############################################################################
// watchBaseN - simulation of the 'Mengenlehreuhr' found in Berlin
// ██ ██ ██ ░░
// ██ ██ ░░ ░░
// ████░░░░░░░
// ██ ██ ░░ ░░
// ███████░░░░
// ██ ░░ ░░ ░░
//############################################################################

#include <chrono>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <set>
#include <string>
#include <thread>
#include <vector>

using std::cout;
using std::string;
using std::vector;

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#include <windows.h>
#else
#define CLEAR_SCREEN "clear"
#endif

class Clock {
    // private:
public:
    int BASE;
    string pos;
    string pts;
    string pol;
    string ptl;
    string* pattern_H;
    string* pattern_L;
    string* pattern_S;

    string makePattern(int digit, int length, const string& opaque, const string& translucent) {

        string pattern = "";

        if (BASE == 5) {
            for (int i = 0; i < digit; i++) {
                pattern += opaque;
            }
            for (int i = digit; i < length; i++) {
                pattern += translucent;
            }

        } else {
            for (int i = digit; i < length; i++) {
                pattern += translucent;
            }
            for (int i = 0; i < digit; i++) {
                pattern += opaque;
            }
        }
        return pattern;
    }

public:
    Clock(int base) : BASE(base) {
        pos = (BASE == 5) ? "█" : "█ ";
        pts = (BASE == 5) ? "░" : "░ ";
        pol = (BASE == 5) ? "██ " : "█ ";
        ptl = (BASE == 5) ? "░░ " : "░ ";

        pattern_H = new string[24 / BASE + 1]; // pattern_H[1]: "██ ░░ ░░ ░░ "
        pattern_L = new string[BASE];          // pattern_L[2]: "██ ██ ░░ ░░ "
        pattern_S = new string[60 / BASE];     // pattern_S[5]: "█████░░░░░░"

        for (int k = 0; k < 24 / BASE + 1; k++) {
            pattern_H[k] = makePattern(k, 24 / BASE, pol, ptl);
        }

        for (int k = 0; k < BASE; k++) {
            pattern_L[k] = makePattern(k, BASE - 1, pol, ptl);
        }

        for (int k = 0; k < 60 / BASE; k++) {
            pattern_S[k] = makePattern(k, 60 / BASE - 1, pos, pts);
        }
    }

    ~Clock() {
        delete[] pattern_H;
        delete[] pattern_L;
        delete[] pattern_S;
    }

    void displayTime() {
        while (true) {
            system(CLEAR_SCREEN);

            auto currentTime =
                std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

            std::tm* localTime = std::localtime(&currentTime);

            cout << "\n";
            // hours
            cout << pattern_H[localTime->tm_hour / BASE];
            BASE == 5 ? cout << "\n" : cout << "H ";
            cout << pattern_L[localTime->tm_hour % BASE];
            // minutes
            BASE == 5 ? cout << "\n" : cout << ": ";
            cout << pattern_S[localTime->tm_min / BASE];
            BASE == 5 ? cout << "\n" : cout << "M ";
            cout << pattern_L[localTime->tm_min % BASE];
            // seconds
            BASE == 5 ? cout << "\n" : cout << ": ";
            cout << pattern_S[localTime->tm_sec / BASE];
            BASE == 5 ? cout << "\n" : cout << "S ";
            cout << pattern_L[localTime->tm_sec % BASE];
            cout << "\n\n";

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(int argc, char* argv[]) {
    int BASE = 5;
    const std::set<string> validValues = {"1", "2", "3", "4", "5", "6", "10", "12"};

    if (argc > 1) {
        string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            cout << "Usage: " << argv[0] << " [options]\n";
            cout << "Options:\n";
            cout << "  -b [ 1 2 3 4 5 6 10 12 ]     Display time base-n "
                    "(default -b 5)\n";
            cout << "  -h, --help      Display this help message\n";
            cout << "  --version       Display program version information\n";
            return 0;
        } else if (arg == "--version") {
            cout << "Program Version 1.1" << std::endl;
            return 0;
        } else if (arg == "-b" && validValues.count(argv[2]) > 0) {
            BASE = std::atoi(argv[2]);
        } else {
            std::cerr << "Unknown option \
            \nusage: " << argv[0]
                      << " -b [ 1 2 3 4 5 6 10 12 ] \
            \ntry for example: "
                      << argv[0] << " -b 5" << std::endl;
            return 1;
        }
    }

    Clock clock(BASE);
    clock.displayTime();

    return 0;
}
