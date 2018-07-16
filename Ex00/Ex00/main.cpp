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
    return std::max(
        std::max(a, b),
        std::max(a, c)
    );
}

int     main(int argc, const char * argv[])
{
    int a, b, c;
    
    std::cout << "Enter 3 numbers:" << std::endl;
    std::cin >> a >> b >> c;
    
    std::cout << if_statements(a, b, c) << std::endl;
    std::cout << tennaries(a, b, c) << std::endl;
    std::cout << if_else(a, b, c) << std::endl;
    std::cout << no_logic_operators(a, b, c) << std::endl;
    return 0;
}
