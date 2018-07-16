#include <gtest/gtest.h>
#include "mega_optimized.hpp"
#include <limits.h>

TEST(BitCheck, General)
{
    EXPECT_EQ(optimized_bit_check(0b001, 0), 1);
    EXPECT_EQ(optimized_bit_check(0b010, 1), 1);
    EXPECT_EQ(optimized_bit_check(0b100, 2), 1);
}

TEST(BitCheck, AllWrong)
{
    EXPECT_NE(optimized_bit_check(0b000, 1), 1);
    EXPECT_NE(optimized_bit_check(0b11101, 1), 1);
}
