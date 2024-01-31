#include <iostream>
#include <vector>

std::vector<int> primeFactorization(int n) {
    std::vector<int> factors;

    // Divide the number by 2 until it is even
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Divide the number by odd numbers starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        factors.push_back(n);
    }

    return factors;
}

int main() {
    int num;

    std::cout << "Enter a number: ";
    std::cin >> num;

    std::vector<int> factors = primeFactorization(num);

    std::cout << "Prime factors of " << num << " are: ";
    for (int factor : factors) {
        std::cout << factor << " ";
    }
    std::cout << std::endl;

    return 0;
}
