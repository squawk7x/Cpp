#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>

// Function to convert a digit (0-9) to its corresponding pattern
std::string convertDigitToPattern(int digit, int row) {
    std::string pattern;
    switch (digit) {
        case 0:
            if (row == 3 || row == 5)
                pattern = "░░░░░░░░░░░";
            else
                pattern = "░░ ░░ ░░ ░░";
            break;
        case 1:
            if (row == 3 || row == 5)
                pattern = "█░░░░░░░░░░";
            else
                pattern = "██ ░░ ░░ ░░";
            break;
        case 2:
            if (row == 3 || row == 5)
                pattern = "██░░░░░░░░░";
            else
                pattern = "██ ██ ░░ ░░";
            break;
        case 3:

            if (row == 3 || row == 5)
                pattern = "███░░░░░░░░";
            else
                pattern = "██ ██ ██ ░░";
            break;
        case 4:

            if (row == 3)
                pattern = "████░░░░░░░";
            else
                pattern = "██ ██ ██ ██";
            break;
        case 5:
            pattern = "█████░░░░░░";
            break;
        case 6:
            pattern = "██████░░░░░";
            break;
        case 7:
            pattern = "███████░░░░";
            break;
        case 8:
            pattern = "████████░░░";
            break;
        case 9:
            pattern = "█████████░░";
            break;
        case 10:
            pattern = "██████████░";
            break;
        case 11:
            pattern = "███████████";
            break;
        default:
            pattern = "";
            break;
    }

    return pattern;
}

int main() {
    while (true) {
        // Get the current system time
        auto currentTime = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());

        // Convert the time to a tm structure for local time
        std::tm *localTime = std::localtime(&currentTime);

        // Display the time in the Menenlehreuhr format
        std::cout << "\n"
                  << convertDigitToPattern((localTime->tm_hour / 5), 1) << "\n"
                  << convertDigitToPattern((localTime->tm_hour % 5), 2) << "\n"
                  << convertDigitToPattern(localTime->tm_min / 5, 3) << "\n"
                  << convertDigitToPattern(localTime->tm_min % 5, 4) << "\n"
                  << convertDigitToPattern(localTime->tm_sec / 5, 5) << "\n"
                  << convertDigitToPattern(localTime->tm_sec % 5, 6) << "\n"
                  << std::endl;

        // Wait for one second before updating the time again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
