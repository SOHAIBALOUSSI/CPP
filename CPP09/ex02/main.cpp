#include "PmergeMe.hpp"


int main(int ac, char **av) {
    if (ac < 3) {
        std::cout << "not enough arguments\n";
        return 1;
    }

    PmergeMe merger;
    try {
        merger.parseArguments(ac, av);
        std::cout <<"before\n" << std::endl;
        for (int i = 0; i < merger.vector.size(); i++)
            std::cout << merger.vector[i];
        std::cout << std::endl;
        merger.sortVector();
        std::cout << "result =\n";
        for (int i = 0; i < merger.vector.size(); i++) {
            std::cout << merger.vector[i];
        }
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
}