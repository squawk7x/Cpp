#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread> // For std::this_thread::sleep_for

// Function to convert a digit (0-9) to its corresponding pattern
std::string convertDigitToPattern(int digit, int cut) {
    std::string pattern;
    switch (digit) {
        case 0:
            pattern = ".........";
            break;
        case 1:
            pattern = "........o";
            break;
        case 2:
            pattern = ".......oo";
            break;
        case 3:
            pattern = "......ooo";
            break;
        case 4:
            pattern = ".....oooo";
            break;
        case 5:
            pattern = "....ooooo";
            break;
        case 6:
            pattern = "...oooooo";
            break;
        case 7:
            pattern = "..ooooooo";
            break;
        case 8:
            pattern = ".oooooooo";
            break;
        case 9:
            pattern = "ooooooooo";
            break;
        default:
            pattern = "";
            break;
    }

    return pattern.substr(pattern.length() - cut);
}

int main() {
    while (true) {
        // Get the current system time
        auto currentTime = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());

        // Convert the time to a tm structure for local time
        std::tm *localTime = std::localtime(&currentTime);

        // Display the time in the Düsseldorfer Tower format
        std::cout << convertDigitToPattern((localTime->tm_hour / 10), 2) << " "
                  << convertDigitToPattern((localTime->tm_hour % 10), 9)
                  << "  " << convertDigitToPattern(localTime->tm_min / 10, 5)
                  << " " << convertDigitToPattern(localTime->tm_min % 10, 9)
                  << "  " << convertDigitToPattern(localTime->tm_sec / 10, 5)
                  << " " << convertDigitToPattern(localTime->tm_sec % 10, 9)
                  << std::endl;

        // Wait for one second before updating the time again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
