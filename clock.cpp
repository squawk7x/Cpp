#include "../include/clock.h"
// #include "clock.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <thread>

#ifdef _WIN32
#define CLEAR_SCREEN "cls"
#else
#define CLEAR_SCREEN "clear"
#endif

Clock::Clock(int base) : BASE(base) {
    pos = (BASE == 5) ? "█" : "█ ";
    pts = (BASE == 5) ? "░" : "░ ";
    pol = (BASE == 5) ? "██ " : "█ ";
    ptl = (BASE == 5) ? "░░ " : "░ ";

    pattern_H = new std::string[24 / BASE + 1];
    pattern_L = new std::string[BASE];
    pattern_S = new std::string[60 / BASE];

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

Clock::~Clock() {
    delete[] pattern_H;
    delete[] pattern_L;
    delete[] pattern_S;
}

void Clock::displayTime() {
    while (true) {
        system(CLEAR_SCREEN);

        auto currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        std::tm* localTime = std::localtime(&currentTime);

        std::cout << "\n";
        std::cout << pattern_H[localTime->tm_hour / BASE];
        BASE == 5 ? std::cout << "\n" : std::cout << "H ";
        std::cout << pattern_L[localTime->tm_hour % BASE];
        BASE == 5 ? std::cout << "\n" : std::cout << ": ";
        std::cout << pattern_S[localTime->tm_min / BASE];
        BASE == 5 ? std::cout << "\n" : std::cout << "M ";
        std::cout << pattern_L[localTime->tm_min % BASE];
        BASE == 5 ? std::cout << "\n" : std::cout << ": ";
        std::cout << pattern_S[localTime->tm_sec / BASE];
        BASE == 5 ? std::cout << "\n" : std::cout << "S ";
        std::cout << pattern_L[localTime->tm_sec % BASE];
        std::cout << "\n\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

std::string Clock::makePattern(int digit, int length, std::string opaque, std::string translucent) {
    std::string pattern = "";

    for (int i = 0; i < digit; i++) {
        pattern += opaque;
    }

    for (int i = digit; i < length; i++) {
        pattern += translucent;
    }

    return pattern;
}
