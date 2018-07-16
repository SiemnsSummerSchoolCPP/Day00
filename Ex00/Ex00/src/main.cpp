#include <iostream>
#include "ex00.hpp"

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
