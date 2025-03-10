#include "easyfind.hpp"

int main() {

    std::vector<int> arr;
    arr.push_back(13);
    arr.push_back(37);
    arr.push_back(42);
    arr.push_back(31);
    arr.push_back(33);
    
    int tofind = 42;
    int pos = 0;
    try {
        pos = easyfind(arr, tofind);
        std::cout << tofind << " found at index " << pos << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << std::endl;

    tofind = -1;
    try {
        pos = easyfind(arr, tofind);
        std::cout << tofind << " found at index " << pos << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << tofind << " " << e.what() << '\n';
    }

}