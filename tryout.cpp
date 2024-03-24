#include <iostream>
#include <vector>
#include <algorithm>

// Function to find the longest increasing subsequence
std::vector<int> longestIncreasingSubsequence(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> dp(n, 1);
    std::vector<int> prev(n, -1);

    int max_length = 1;
    int end_index = 0;

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
                if (dp[i] > max_length) {
                    max_length = dp[i];
                    end_index = i;
                }
            }
        }
    }

    std::vector<int> lis;
    while (end_index != -1) {
        lis.push_back(nums[end_index]);
        end_index = prev[end_index];
    }

    std::reverse(lis.begin(), lis.end());
    return lis;
}

int main() {
    std::vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60};
    std::vector<int> lis = longestIncreasingSubsequence(nums);

    std::cout << "Longest increasing subsequence: ";
    for (size_t i = 0; i < lis.size(); ++i) {
        std::cout << lis[i];
        if (i != lis.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    std::cout << "Length of longest increasing subsequence: " << lis.size() << std::endl;

    return 0;
}
