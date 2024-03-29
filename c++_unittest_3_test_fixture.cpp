//############################################################################
// Unit Test - Test Fixture
//############################################################################

#include "../src/c++_unittest_mystack.cpp"
#include <gtest/gtest.h>

class MyStackTest : public ::testing::Test {
    // must be derived from ::testing::Test
protected:                 // Either public or protected. Cannot be private.
    virtual void SetUp() { // Capital 'U'
        st.push(34);
        st.push(28);
        st.push(56);
    }
    virtual void TearDown() {}

    MyStackTest() {
        std::cout << "MyStackTest is constructed." << std::endl;
        st.push(22);
    }
    ~MyStackTest() { std::cout << "Destructing MyStackTest." << std::endl; }

    MyStack st; // common data for tests
};

// Test with fixture: TEST_F
TEST_F(MyStackTest, testPop) {
    // First argument must be test fixture class name

    // Construct an instance of MyStackTest m and calls m.SetUp();

    int val = st.pop();
    // Member of test fixture is accessible here
    EXPECT_EQ(56, val);
    EXPECT_EQ(54, val); // << "This value must be 56";
    // EXPECT_EQ(54, val); // << "This value cannot be different from " << val;
    // EXPECT_EQ(54, val); // << "Let's see what is inside st: " << st;

    // m.TearDown();
}

TEST_F(MyStackTest, testPop2) { // independant from testPop

    int val = st.pop();
    EXPECT_EQ(56, val);
}

/*
Question:  Should I use constructor/destructor or SetUp()/TearDown()?
1. As a guideline,
    - a constructor should do minimum thing to put the object in a valid state and
    - a destructor should do the reverse of constructor.
2. If a function is virtual, put it in Setup()/TearDown()
3. If exception might be thrown, put the code in TearDown(), not in destructor.
4. Put gtest assertions in TearDown(), not in destructor
*/
