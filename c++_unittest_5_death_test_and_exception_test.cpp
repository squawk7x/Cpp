//############################################################################
// Unit Test - Death Test and Exception Test
//############################################################################

#include "../include/c++_unittest_mystack.h"
#include <gtest/gtest.h>

// Death Test:
// Verify a statement will cause process to exit in a expected fashion

void function1() {

    std::cerr << "Bad thing happened";
    std::exit(1); // exit(0) is not a death
}

void function2() {
    std::cerr << "Bad thing happend again.";
    std::exit(22);
}

TEST(tutorial_DeathTest, simpletest) {
    // Convention: test case name should end with "DeathTest"
    // DeathTests usually need to be run before other test

    int x = 90;

    // Reasons of death:
    //    1. Process exited with non-zero code
    //    2. Process was killed by a signal

    EXPECT_DEATH(function1(), "Bad thing happened");

    EXPECT_EXIT(function1(), ::testing::ExitedWithCode(1), "");
    // "" means I don't care about cerr message

    EXPECT_EXIT(function1(), ::testing::KilledBySignal(SIGKILL), ".*");
    // Not on Windows
}

TEST(tutorial_exceptionTest, simpletest) {
    MyStack st;

    EXPECT_THROW(st.pop(), OUT_OF_RANGE_EXCEPTION);
    // Expect st.pop() to throw an exception of
    EXPECT_ANY_THROW(st.pop());
    // Expect st.pop() to throw an exception of any type
    EXPECT_NO_THROW(st.pop());
    // Expect st.pop() not to throw exception.

    FAIL();
    // report test has failed

    switch (st.size()) {
    case 1:; //
    case 2:; //
    case -1:
        FAIL() << "Size cannot be negative.";
    }
}