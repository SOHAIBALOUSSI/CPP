#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}


std::vector<int> PmergeMe::getJacobSeq(int n) {
    std::vector<int> Jacobseq;

    Jacobseq.push_back(0);
    Jacobseq.push_back(1);

    while (Jacobseq.back() < n) {
        int last = Jacobseq.back();
        int beforelast = Jacobseq[Jacobseq.size() - 2];
        Jacobseq.push_back(last + 2*beforelast);
    }
    return Jacobseq;
}

std::vector<int>    PmergeMe::mergeInsert(std::vector<int> main) {

    size_t mainSize = main.size();
    std::vector<int> JacobSeq = getJacobSeq(mainSize);
    std::vector<int> insertSequence;
    std::vector<bool> included(mainSize+1, false);

    for (size_t i=1; i < JacobSeq.size(); i++) {
        for (int j = JacobSeq[i]; j > JacobSeq[i - 1]; j--) {
            if (j <= mainSize && !included[j]) {
                insertSequence.push_back(j);
                included[j] = 1;
            }
        }
    }

    for (int i=1 ; i < mainSize; i++) {
        if (!included[i])
            insertSequence.push_back(i);
    }
    return insertSequence;
}


void    PmergeMe::sortVector() {
    if (vector.size() <= 1)
        return;
    
    bool   hasStraggler = 0;
    int straggler = 0;
    std::vector<int> mainchain, pendChain; 

    if (vector.size()%2) {
        hasStraggler = 1;
        straggler = vector.back();
        vector.pop_back();
    }
    for (size_t i = 0; i < vector.size(); i+=2) {
        if (vector[i] > vector[i + 1]) {
            mainchain.push_back(vector[i]);
            pendChain.push_back(vector[i+1]);
        }
        else {
            mainchain.push_back(vector[i+1]);
            pendChain.push_back(vector[i]);
        }
    }
    vector = mainchain;
    sortVector();
    mainchain = vector;
    std::vector<int> result = mainchain;
    std::vector<int> insertSeq = mergeInsert(result);

    for (size_t i = 0 ; i < insertSeq.size(); i++) {
        int idx = insertSeq[i];
        if (idx >= 0 && idx < (int)pendChain.size()) {
            std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(),  pendChain[idx - 1]);
            result.insert(pos,  pendChain[idx - 1]);
        }
    }
    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(result.begin(), result.end(), straggler);
        result.insert(pos, straggler);
    }
    vector = result;
}

void PmergeMe::parseArguments(int ac, char **av) {
    for (int i = 1; i < ac; i++) {
        std::string arg(av[i]);
        if (arg.find_first_not_of(digits) != std::string::npos)
            throw std::runtime_error("Error: bad argument");
        long long num = std::atoll(av[i]);
        if (num > INT_MAX || num < 0)
            throw std::runtime_error("Error: bad argument");
        vector.push_back(num);
        deque.push_back(num);
    }
}