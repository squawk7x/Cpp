#include <algorithm>
#include <iostream>
#include <vector>

// Function to convert decimal to binary
std::vector<int> decimalToBinary(int n) {
    std::vector<int> binary;

    // Handling special case when n is 0
    if (n == 0) {
        binary.push_back(0);
        return binary;
    }

    // Keep dividing the number by 2 and store remainders
    while (n > 0) {
        binary.push_back(n % 2);
        n = n / 2;
    }

    // Reverse the vector to get the binary representation
    std::reverse(binary.begin(), binary.end());

    return binary;
}

int main() {
    int decimalNumber;
    std::cout << "Enter a decimal number: ";
    std::cin >> decimalNumber;

    // Convert decimal to binary
    std::vector<int> binary = decimalToBinary(decimalNumber);

    // Display the binary representation
    std::cout << "Binary representation: ";
    for (int bit : binary) {
        std::cout << bit;
    }
    std::cout << std::endl;

    return 0;
}
