#pragma once

#include <bits/stdc++.h>

const std::string digits = "0123456789";

class PmergeMe
{
private:
std::deque<int>  deque;

public:

std::vector<int> vector;
    void    parseArguments(int ac, char **av);
    void    sortVector();

    std::vector<int>    mergeInsert(std::vector<int> main);
    std::vector<int> getJacobSeq(int n);
    // void    sortDeque();
    PmergeMe();
    ~PmergeMe();
};


