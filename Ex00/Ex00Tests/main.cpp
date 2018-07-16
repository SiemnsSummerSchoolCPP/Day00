#include <iostream>
#include "ex00.hpp"
#include <gtest/gtest.h>

/*
** A set of 4 numbers, where the last one is the expected
** result.
*/

int tests[] =
{
    1, 2, 3, 3,
    2, 2, 3, 3,
    3, 2, 3, 3,
    3, 2, 2, 3,
    3, -10, 3, 3
};

TEST(Addition2, CanAddTwoNumbers)
{
    int tests_count = sizeof(tests) / (sizeof(*tests) * 4);
    for (int i = 0; i < tests_count - 2; i++)
    {
        auto test = tests + i * 4;
        EXPECT_EQ(if_statements(test[0], test[1], test[2]), test[3]);
        EXPECT_EQ(tennaries(test[0], test[1], test[2]), test[3]);
        EXPECT_EQ(if_else(test[0], test[1], test[2]), test[3]);
        EXPECT_EQ(no_logic_operators(test[0], test[1], test[2]), test[3]);
    }
    
    EXPECT_TRUE(2 + 2 == 4);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}
