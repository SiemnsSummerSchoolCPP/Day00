#include <iostream>

int     if_statements(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    if (b >= a && b >= c)
        return b;
    return c;
}

int     tennaries(int a, int b, int c)
{
    return
    (a >= b && a >= c) ? a :
    (b >= a && b >= c) ? b : c;
}

int     if_else(int a, int b, int c)
{
    if (a >= b && a >= c)
        return a;
    else if (b >= a && b >= c)
        return b;
    else
        return c;
}

int     no_logic_operators(int a, int b, int c)
{
    return std::max(std::max(a, b), std::max(a, c));
}
