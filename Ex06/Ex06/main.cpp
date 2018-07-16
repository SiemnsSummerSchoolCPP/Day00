#include <iostream>

int main(int argc, const char * argv[])
{
    auto str = std::string("Hello World");
    
    for (auto& c : str)
        c = 'X';
    
    std::cout << str << std::endl;
    return 0;
}
