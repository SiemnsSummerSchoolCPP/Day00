#include <gtest/gtest.h>
#include "mega_optimized.hpp"
#include <limits.h>

TEST(Even, General)
{
    EXPECT_EQ(optimized_even(1), 0);
    EXPECT_EQ(optimized_even(2), 1);
}

TEST(Even, Negatives)
{
    EXPECT_EQ(optimized_even(-1), 0);
    EXPECT_EQ(optimized_even(-2), 1);
}

TEST(Even, Zero)
{
    EXPECT_EQ(optimized_even(0), 1);
}

TEST(Even, Limits)
{
    EXPECT_EQ(optimized_even(INT_MAX), 0);
    EXPECT_EQ(optimized_even(INT_MIN), 1);
}
