#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include <cstdlib>
#include <string.h>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

// #define BASE 5

std::string makePattern(int digit, int length, std::string opaque,
                        std::string translucent) {
    std::string pattern = "";

    for (int i = 0; i < digit; i++) {
        pattern += opaque;
    }

    for (int i = digit; i < length; i++) {
        pattern += translucent;
    }

    return pattern;
}

int main(int argc, char *argv[]) {
    int BASE = 5;

    if (argc == 2 && (strcmp(argv[1], "1") == 0 || strcmp(argv[1], "2") == 0 ||
                      strcmp(argv[1], "3") == 0 || strcmp(argv[1], "4") == 0 ||
                      strcmp(argv[1], "5") == 0 || strcmp(argv[1], "6") == 0 ||
                      strcmp(argv[1], "10") == 0 || strcmp(argv[1], "12") == 0)) {
        BASE = std::atoi(argv[1]);
    }

    std::string pattern_H[24 / BASE + 1];
    std::string pattern_L[BASE];
    std::string pattern_S[60 / BASE];

    std::string pos;
    std::string pts;

    if (BASE == 5) {
        pos = "█";
        pts = "░";
    } else {
        pos = "█ ";
        pts = "░ ";
    }
    std::string pol;
    std::string ptl;

    if (BASE == 5) {
        pol = "██ ";
        ptl = "░░ ";
    } else {
        pol = "█ ";
        ptl = "░ ";
    }

    // (BASE -1) +

    for (int k = 0; k < 24 / BASE + 1; k++) {
        pattern_H[k] = makePattern(k, 24 / BASE, pol, ptl);
    }

    for (int k = 0; k < 60 / BASE; k++) {
        pattern_S[k] = makePattern(k, 60 / BASE - 1, pos, pts);
    }

    for (int k = 0; k < BASE; k++) {
        pattern_L[k] = makePattern(k, BASE - 1, pol, ptl);
    }

    while (true) {
        system(CLEAR_SCREEN);

        auto currentTime = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());

        std::tm *localTime = std::localtime(&currentTime);

        std::cout << "\n";
        std::cout << pattern_H[localTime->tm_hour / BASE];
        if (BASE == 5)
            std::cout << "\n";
        else
            std::cout << "H ";
        std::cout << pattern_L[localTime->tm_hour % BASE];
        if (BASE == 5)
            std::cout << "\n";
        else
            std::cout << ": ";
        std::cout << pattern_S[localTime->tm_min / BASE];
        if (BASE == 5)
            std::cout << "\n";
        else
            std::cout << "M ";
        std::cout << pattern_L[localTime->tm_min % BASE];
        if (BASE == 5)
            std::cout << "\n";
        else
            std::cout << ": ";
        std::cout << pattern_S[localTime->tm_sec / BASE];
        if (BASE == 5)
            std::cout << "\n";
        else
            std::cout << "S ";
        std::cout << pattern_L[localTime->tm_sec % BASE];
        std::cout << "\n\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
