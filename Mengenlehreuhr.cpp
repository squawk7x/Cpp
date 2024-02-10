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

void displayHelp() {
    std::cout << "Usage: Mengenlehreuhr [options]\n";
    std::cout << "Options:\n";
    std::cout << "  -b [ 1 2 3 4 5 6 10 12 ]     Display time base-n (default -b 5)\n";
    std::cout << "  -h, --help      Display this help message\n";
    std::cout << "  --version       Display program version information\n";
}


int main(int argc, char *argv[]) {
    int BASE = 5;

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            displayHelp();
            return 0;
        } else if (arg == "--version") {
            std::cout << "Program Version 1.0" << std::endl;
            return 0;
        } else if (arg == "-b" &&
                   (strcmp(argv[2], "1") == 0 || strcmp(argv[2], "2") == 0 ||
                    strcmp(argv[2], "3") == 0 || strcmp(argv[2], "4") == 0 ||
                    strcmp(argv[2], "5") == 0 || strcmp(argv[2], "6") == 0 ||
                    strcmp(argv[2], "10") == 0 || strcmp(argv[2], "12") == 0)) {
            BASE = std::atoi(argv[2]);
        } else {
            std::cerr << "Unknown option, try: Mengenlehreuhr -b 5"
                      << std::endl;
            return 1;
        }
    }

    std::string pos;
    std::string pts;
    std::string pol;
    std::string ptl;

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

    std::string pattern_H[24 / BASE + 1];
    std::string pattern_L[BASE];
    std::string pattern_S[60 / BASE];
    
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
        BASE == 5 && std::cout << "\n";
        BASE != 5 && std::cout << "H ";
        std::cout << pattern_L[localTime->tm_hour % BASE];
        BASE == 5 && std::cout << "\n";
        BASE != 5 && std::cout << ": ";
        std::cout << pattern_S[localTime->tm_min / BASE];
        BASE == 5 && std::cout << "\n";
        BASE != 5 && std::cout << "M ";
        std::cout << pattern_L[localTime->tm_min % BASE];
        BASE == 5 && std::cout << "\n";
        BASE != 5 && std::cout << ": ";
        std::cout << pattern_S[localTime->tm_sec / BASE];
        BASE == 5 && std::cout << "\n";
        BASE != 5 && std::cout << "S ";
        std::cout << pattern_L[localTime->tm_sec % BASE];
        std::cout << "\n\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
