#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include <cstdlib>
#include <string>
#include <cstring>

using std::string;
using std::cout;

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

class Clock {
private:
    int BASE;
    string pos;
    string pts;
    string pol;
    string ptl;
    string* pattern_H;
    string* pattern_L;
    string* pattern_S;

    string makePattern(int digit, int length, string opaque, string translucent) {
        string pattern = "";

        for (int i = 0; i < digit; i++) {
            pattern += opaque;
        }

        for (int i = digit; i < length; i++) {
            pattern += translucent;
        }

        return pattern;
    }

public:
    Clock(int base) : BASE(base) {
        if (BASE == 5) {
            pos = "█";
            pts = "░";
            pol = "██ ";
            ptl = "░░ ";
        } else {
            pos = "█ ";
            pts = "░ ";
            pol = "█ ";
            ptl = "░ ";
        }

        pattern_H = new string[24 / BASE + 1];
        pattern_L = new string[BASE];
        pattern_S = new string[60 / BASE];

        for (int k = 0; k < 24 / BASE + 1; k++) {
            pattern_H[k] = makePattern(k, 24 / BASE, pol, ptl);
        }

        for (int k = 0; k < 60 / BASE; k++) {
            pattern_S[k] = makePattern(k, 60 / BASE - 1, pos, pts);
        }

        for (int k = 0; k < BASE; k++) {
            pattern_L[k] = makePattern(k, BASE - 1, pol, ptl);
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

            auto currentTime = std::chrono::system_clock::to_time_t(
                std::chrono::system_clock::now());

            std::tm *localTime = std::localtime(&currentTime);

            cout << "\n";
            cout << pattern_H[localTime->tm_hour / BASE];
            BASE == 5 ? cout << "\n" : cout << "H ";
            cout << pattern_L[localTime->tm_hour % BASE];
            BASE == 5 ? cout << "\n" : cout << ": ";
            cout << pattern_S[localTime->tm_min / BASE];
            BASE == 5 ? cout << "\n" : cout << "M ";
            cout << pattern_L[localTime->tm_min % BASE];
            BASE == 5 ? cout << "\n" : cout << ": ";
            cout << pattern_S[localTime->tm_sec / BASE];
            BASE == 5 ? cout << "\n" : cout << "S ";
            cout << pattern_L[localTime->tm_sec % BASE];
            cout << "\n\n";

            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }
};

int main(int argc, char *argv[]) {
    int BASE = 5;

    if (argc > 1) {
        string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            cout << "Usage: Mengenlehreuhr [options]\n";
            cout << "Options:\n";
            cout << "  -b [ 1 2 3 4 5 6 10 12 ]     Display time base-n (default -b 5)\n";
            cout << "  -h, --help      Display this help message\n";
            cout << "  --version       Display program version information\n";
            return 0;
        } else if (arg == "--version") {
            cout << "Program Version 1.0" << std::endl;
            return 0;
        } else if (arg == "-b" &&
                   (strcmp(argv[2], "1") == 0 || strcmp(argv[2], "2") == 0 ||
                    strcmp(argv[2], "3") == 0 || strcmp(argv[2], "4") == 0 ||
                    strcmp(argv[2], "5") == 0 || strcmp(argv[2], "6") == 0 ||
                    strcmp(argv[2], "10") == 0 || strcmp(argv[2], "12") == 0)) {
            BASE = std::atoi(argv[2]);
        } else {
            std::cerr << "Unknown option \
            \nusage: Mengenlehreuhr -b [ 1 2 3 4 5 6 10 12 ] \
            \ntry for example: Mengenlehreuhr -b 5"
                      << std::endl;
            return 1;
        }
    }

    Clock clock(BASE);
    clock.displayTime();

    return 0;
}
