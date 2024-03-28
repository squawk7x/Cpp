#include "../include/clock.h" // Include the header file for the Clock class
#include "gtest/gtest.h"

// Test case to check pattern_H[0]
TEST(ClockTest, Pattern_H_Index_0) {
    // Create a Clock object with BASE 5
    Clock clock(5);

    std::string expectedPattern;

    // expectedPattern = "██ ░░ ░░ ░░ ";
    expectedPattern = "░░ ░░ ░░ ░░ ";
    // Assuming that e.g. pattern_H[0] should equal "░░ ░░ ░░ ░░ "
    EXPECT_EQ(clock.pattern_H[0], expectedPattern);
}

TEST(ClockTest2, Pattern_H_Index_1_4) {
    // Create a Clock object with BASE 5
    Clock clock(5);

    std::string expectedPattern;

    expectedPattern = "██ ░░ ░░ ░░ ";
    EXPECT_EQ(clock.pattern_H[1], expectedPattern);

    expectedPattern = "██ ██ ░░ ░░ ";
    EXPECT_EQ(clock.pattern_H[2], expectedPattern);

    expectedPattern = "██ ██ ██ ░░ ";
    EXPECT_EQ(clock.pattern_H[3], expectedPattern);

    expectedPattern = "██ ██ ██ ██ ";
    EXPECT_EQ(clock.pattern_H[4], expectedPattern);
}

// Main function to run all the tests
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
