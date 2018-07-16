#include <gtest/gtest.h>
#include "mega_optimized.hpp"

TEST(Div, General)
{
    EXPECT_EQ(optimized_div(4, 2), 1);
    EXPECT_EQ(optimized_div(8, 2), 2);
}

TEST(Div, NAN)
{
    EXPECT_EQ(optimized_div(0, 0), 0);
}

TEST(Div, Zero)
{
    EXPECT_EQ(optimized_div(0, 10), 0);
    EXPECT_EQ(optimized_div(10, 0), 10);
}
