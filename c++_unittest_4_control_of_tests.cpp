//############################################################################
// Unit Test - Control of Tests
//############################################################################

#include "../src/c++_unittest_mystack.cpp"
#include <gtest/gtest.h>

// DISABLED
// TEST(StackTest, DISABLED_testPop) {
TEST(StackTest, testPop) {
    MyStack st;
    st.push(9);
    EXPECT_EQ(8, st.pop());
}

TEST(StackTest, testAll) {
    MyStack st;
    st.push(9);
    st.push(28);

    int val = st.pop();
    EXPECT_EQ(28, val);
}

// another way to control tests: via commandline
// --gtest_filter=StackTest.*

GTEST_API_ int main(int argc, char** argv) {
    std::cout << "Runing main from gtest_main.cc\n";

    // only StackTest.testAll performed
    // ::testing::GTEST_FLAG(filter) = "StackTest.testAll";

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}