#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<typename containerType>
int easyfind(containerType& container, int tofind) {
    typename containerType::iterator it;
    it = find(container.begin(), container.end(), tofind);
    if (it != container.end())
        return std::distance(container.begin(), it);
    throw std::runtime_error("not found");
}

#endif