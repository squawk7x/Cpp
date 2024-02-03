#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <iomanip>

// Function to display the Qlocktwo-style clock
void displayQlocktwoClock() {
    // Clear the console screen
    std::system("clear");

    // Get the current system time
    auto currentTime = std::chrono::system_clock::to_time_t(
        std::chrono::system_clock::now());
    
    // Convert the time to a tm structure for local time
    std::tm *localTime = std::localtime(&currentTime);

    // Define the Qlocktwo-style clock grid
    std::string clockGrid[11][11] = {
        {"I", "T", "L", "I", "S", "A", "S", "T", "I", "M", "E"},
        {"A", "C", "Q", "U", "A", "R", "T", "E", "R", "D", "C"},
        {"T", "W", "E", "N", "T", "Y", "F", "I", "V", "E", "X"},
        {"H", "A", "L", "F", "B", "T", "E", "N", "F", "T", "O"},
        {"P", "A", "S", "T", "E", "R", "U", "N", "I", "N", "E"},
        {"O", "N", "E", "S", "I", "X", "T", "H", "R", "E", "E"},
        {"F", "O", "U", "R", "F", "I", "V", "E", "T", "W", "O"},
        {"E", "I", "G", "H", "T", "E", "L", "E", "V", "E", "N"},
        {"S", "E", "V", "E", "N", "T", "W", "E", "L", "V", "E"},
        {"T", "E", "N", "S", "E", "O", "C", "L", "O", "C", "K"},
        {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}, // Empty row for spacing
    };

    // Get the current hour, minute, and second
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    int second = localTime->tm_sec;

    // Convert the hour to 12-hour format
    if (hour > 12) hour -= 12;

    // Set the time in the Qlocktwo-style clock grid
    // Hours
    if (hour >= 10) {
        clockGrid[0][9] = "1";
        clockGrid[0][10] = std::to_string(hour - 10);
    } else {
        clockGrid[0][9] = " ";
        clockGrid[0][10] = std::to_string(hour);
    }

    // Minutes
    clockGrid[2][6] = std::to_string(minute / 10);
    clockGrid[2][7] = std::to_string(minute % 10);

    // Seconds
    clockGrid[4][8] = std::to_string(second / 10);
    clockGrid[4][9] = std::to_string(second % 10);

    // Display the current time in the Qlocktwo-style clock grid
    for (int i = 0; i < 11; ++i) {
        for (int j = 0; j < 11; ++j) {
            std::cout << clockGrid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    while (true) {
        // Display the Qlocktwo-style clock
        displayQlocktwoClock();

        // Wait for one second before updating the clock again
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}
