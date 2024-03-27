#include "clock.cpp"
#include <iostream>
#include <set>

const std::set<std::string> validValues = {"1", "2", "3", "4", "5", "6", "10", "12"};

int main(int argc, char* argv[]) {
    int BASE = 5;

    if (argc > 1) {
        std::string arg = argv[1];
        if (arg == "-h" || arg == "--help") {
            std::cout << "Usage: " << argv[0] << " [options]\n";
            std::cout << "Options:\n";
            std::cout << "  -b [ 1 2 3 4 5 6 10 12 ]     Display time base-n "
                         "(default -b 5)\n";
            std::cout << "  -h, --help      Display this help message\n";
            std::cout << "  --version       Display program version information\n";
            return 0;
        } else if (arg == "--version") {
            std::cout << "Program Version 1.0" << std::endl;
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
