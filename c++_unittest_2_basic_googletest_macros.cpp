// build test executable with CTRL+SHIFT+B or:
// g++ test.cpp -o test -lgtest -lgtest_main -pthread && "/home/andreas/C++/Tutorials/test/"test

#include "../src/c++_unittest_mystack.cpp"
#include <gtest/gtest.h>

TEST(StackTest, testPop) {
    MyStack st;
    st.push(9);
    EXPECT_EQ(9, st.pop());
}

TEST(StackTest, testAll) {
    MyStack st;
    st.push(9);
    st.push(28);

    int val = st.pop();

    // Nonfatal assertion -> EXPECT
    EXPECT_EQ(28, val);
    // Expect val to be 28
    EXPECT_NE(0, val);
    // Expect val not to be 0
    EXPECT_GT(29, val);
    // Greater than
    EXPECT_TRUE(val == 28) << "val somehow is not equal to 28";
    // Print customized message

    // Fatal assertion -> ASSERT
    // If this fails, the rest of current function is skipped  -- Fatal Error
    ASSERT_EQ(24, val);
    ASSERT_GT(29, val);
    ASSERT_TRUE(val == 28);
    ASSERT_STREQ("9 ", st.toString().c_str());
    ASSERT_STRCASEEQ("9 ", st.toString().c_str());
    // Ignore case

    // String Check
    EXPECT_STREQ("9 ", st.toString().c_str());
    EXPECT_STRCASEEQ("9 ", st.toString().c_str());
    // Ignore case

    EXPECT_FLOAT_EQ(7.0, ((float)val) / 4);
    // The two floats are almost the same: within 4 ULP's from each other
    // ULP: Unit in the Last Place  -- spacing between floating number variables.
    //      Example:  float X;  Y = the smallest float that is bigger than X
    //                ULP = Y - X;
    EXPECT_DOUBLE_EQ(7.0, ((double)val) / 4);
    EXPECT_NEAR(6.0, ((float)val) / 5, 1);
    // The difference is less than 1
}
