#include "RPN.hpp"


int main(int ac, char **av) {
    RPN rpn;
    if (ac != 2) return 1;
    std::string exp =  std::string(av[1]);
    try {
        rpn.parseExpresion(exp);   
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}