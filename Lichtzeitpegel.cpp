#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread> // For std::this_thread::sleep_for

// Function to convert a digit (0-9) to its corresponding pattern
std::string convertDigitToPattern(int digit, int pos) {
    std::string pattern;
    switch (digit) {
        case 0:
            if (pos == 1)
                pattern = "░░";
            if (pos == 3 || pos == 5)
                pattern = "░░░░░";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░░░░░░";
            break;
        case 1:
            if (pos == 1)
                pattern = "░█";
            if (pos == 3 || pos == 5)
                pattern = "░░░░█";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░░░░░█";
            break;
        case 2:
            if (pos == 1)
                pattern = "██";
            if (pos == 3 || pos == 5)
                pattern = "░░░██";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░░░░██";
            break;
        case 3:
            if (pos == 3 || pos == 5)
                pattern = "░░███";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░░░███";
            break;
        case 4:
            if (pos == 3 || pos == 5)
                pattern = "░████";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░░████";
            break;
        case 5:
            if (pos == 3 || pos == 5)
                pattern = "█████";
            if (pos == 2 || pos == 4 || pos == 6)
                pattern = "░░░░█████";
            break;
        case 6:
            pattern = "░░░██████";
            break;
        case 7:
            pattern = "░░███████";
            break;
        case 8:
            pattern = "░████████";
            break;
        case 9:
            pattern = "█████████";
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

        // Display the time in the Düsseldorfer Tower format
        std::cout << "21H987654321:54321M987654321:54321S987654321\n"
                  << convertDigitToPattern((localTime->tm_hour / 10), 1) << "H"
                  << convertDigitToPattern((localTime->tm_hour % 10), 2) << ":"
                  << convertDigitToPattern(localTime->tm_min / 10, 3) << "M"
                  << convertDigitToPattern(localTime->tm_min % 10, 4) << ":"
                  << convertDigitToPattern(localTime->tm_sec / 10, 5) << "S"
                  << convertDigitToPattern(localTime->tm_sec % 10, 6)
                  << std::endl;

        // Wait for one second before updating the time again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
