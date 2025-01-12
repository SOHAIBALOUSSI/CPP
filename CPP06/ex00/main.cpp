#include "ScalarConverter.hpp"

int main(int ac, char **av) {

    if (ac != 2) return 1;
    // if the input is a char check if its pritable
    try
    {
        ScalarConverter::convert(av[1]);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}