#include <gtest/gtest.h>

// A dummy function to be tested
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

// Test case for the add function
TEST(AdditionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(add(1, 2), 3);
    EXPECT_EQ(add(5, 7), 12);
}

TEST(AdditionTest, HandlesNegativeNumbers) {
    EXPECT_EQ(add(-1, -2), -3);
    EXPECT_EQ(add(-5, -7), -12);
}

TEST(AdditionTest, HandlesMixedSignNumbers) {
    EXPECT_EQ(add(-1, 1), 0);
    EXPECT_EQ(add(7, -3), 4);
}

// Test case for the subtract function
TEST(SubtractionTest, HandlesPositiveNumbers) {
    EXPECT_EQ(subtract(10, 5), 5);
    EXPECT_EQ(subtract(20, 15), 5);
}

TEST(SubtractionTest, HandlesNegativeNumbers) {
    EXPECT_EQ(subtract(-10, -5), -5);
    EXPECT_EQ(subtract(-20, -15), -5);
}

TEST(SubtractionTest, HandlesMixedSignNumbers) {
    EXPECT_EQ(subtract(-10, 5), -15);
    EXPECT_EQ(subtract(10, -5), 15);
}