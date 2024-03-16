// build test executable with CTRL+SHIFT+B or:
// g++ test.cpp -o test -lgtest -lgtest_main -pthread && "/home/andreas/C++/Tutorials/test/"test

#include <gtest/gtest.h>
#include "../include/c11_gtest_mystack.h"

// Death Test:  Verify a statement will cause process to exit with certain exit code and error
// message

void function1() {

    std::cerr << "Bad thing happened";
    std::exit(1); // exit(0) is not a death
}

void function2() {
    std::cerr << "Bad thing happend again.";
    std::exit(22);
}

TEST(tutorial_DeathTest, simpletest) { // Convention: test case name should end with "DeathTest"
                                       // DeathTests usually need to be run before other test
    int x = 90;

    // Reasons of death:
    //    1. Process exited with non-zero code
    //    2. Process was killed by a signal

    EXPECT_DEATH(function1(), "Bad thing happened");

    EXPECT_EXIT(function1(), ::testing::ExitedWithCode(1),
                ""); // "" means I don't care about cerr message

    // EXPECT_EXIT(function1(), ::testing::KilledBySignal(SIGKILL), ".*");  // Not on Windows
}

TEST(tutorial_exceptionTest, simpletest) {
    // MyStack st;

    // EXPECT_THROW(st.pop(), OUT_OF_RANGE_EXCEPTION); // Expect st.pop() to throw an exception of
    // EXPECT_ANY_THROW(st.pop()); // Expect st.pop() to throw an exception of any type
    // EXPECT_NO_THROW(st.pop());  // Expect st.pop() not to throw exception.

    // FAIL();

    // switch (st.size()) {
    // case 1:; //
    // case 2:; //
    // case -1:
    //     FAIL() << "Size cannot be negativ.";
    // }
}