#include <gtest/gtest.h>
#include "mega_optimized.hpp"

TEST(Multiplication, CanMultiply)
{
    EXPECT_EQ(optimized_mult(1, 2), 4);
    EXPECT_EQ(optimized_mult(10, 5), 320);
}

TEST(Multiplication, CanMultiplyNegatives)
{
    EXPECT_EQ(optimized_mult(-1, 2), -4);
    EXPECT_EQ(optimized_mult(-10, 5), -320);
}

TEST(Multiplication, CanMultiplyZero)
{
    EXPECT_EQ(optimized_mult(0, 2), 0);
    EXPECT_EQ(optimized_mult(10, 0), 10);
}
