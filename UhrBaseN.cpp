#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <thread>
#include <cstdlib> // Needed for the system() function

#ifdef _WIN32
// Windows
#define CLEAR_SCREEN "cls"
#else
// Assume UNIX-like system
#define CLEAR_SCREEN "clear"
#endif

int BASE = 5;

// Function to convert a digits to its corresponding pattern
std::string convertDigitToPattern(int digit, int row) {
    std::string pattern;

    pattern = "";
    int X = 2, Y = 1, Z = 1;

    if (row == 3 || row == 5) {
        for (int i = 0; i < digit; ++i) {
            for (int j = 0; j < Z; ++j) {
                pattern += "█";
            }
        }

        for (int i = digit; i < (60 / BASE - 1); ++i) {
            for (int j = 0; j < Z; ++j) {
                pattern += "░";
            }
        }

        // (Base-1)*p*x + (BASE-2)*p*y = [(60/BASE)-1]*p*z

    } else {

        for (int i = 0; i < digit; ++i) {
            pattern += "██ ";
        }
        for (int i = digit; i < (BASE - 1); ++i) {
            pattern += "░░ ";
        }
    }

    return pattern;
}

int main() {
    // system("tput civis"); // Hide the cursor

    while (true) {
        // Clear the screen
        system(CLEAR_SCREEN);

        // Get the current system time
        auto currentTime = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());

        // Convert the time to a tm structure for local time
        std::tm *localTime = std::localtime(&currentTime);

        // Display the time in the Menenlehreuhr format
        std::cout << "\n"
                  << convertDigitToPattern((localTime->tm_hour / BASE), 1)
                  << "\n"
                  << convertDigitToPattern((localTime->tm_hour % BASE), 2)
                  << "\n"
                  << convertDigitToPattern(localTime->tm_min / BASE, 3) << "\n"
                  << convertDigitToPattern(localTime->tm_min % BASE, 4) << "\n"
                  << convertDigitToPattern(localTime->tm_sec / BASE, 5) << "\n"
                  << convertDigitToPattern(localTime->tm_sec % BASE, 6) << "\n"
                  << std::endl;

        // Wait for one second before updating the time again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    // system("tput cnorm"); // Make the cursor visible again

    return 0;
}
