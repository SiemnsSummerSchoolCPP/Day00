#include "mega_optimized.hpp"

int     optimized_mult(int x, int power_of_two)
{
    return x << power_of_two;
}

int     optimized_div(int x, int power_of_two)
{
    return x >> power_of_two;
}

int     optimized_even(int x)
{
    return !(x & 1);
}

int     optimized_bit_check(int x, int n)
{
    return (x & (1 << n)) ? 1 : 0;
}
