#ifndef MUTANSTACK_HPP
#define MUTANSTACK_HPP

#include <algorithm>
#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
public:
    typedef typename std::stack<T>::container_type  ctype;
    typedef typename ctype::iterator                iterator;

public:
    MutantStack();
    MutantStack(const MutantStack<T>& copy);
    MutantStack<T>& operator=(const MutantStack<T>& assing);
    ~MutantStack();

    iterator begin();
    iterator end();
};


template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& copy) : std::stack<T>(copy) {}

template<typename T>
MutantStack<T>&    MutantStack<T>::operator=(const MutantStack<T>& assing) {
    if (this != &assing) {
        std::stack<T>::operator=(assing);
    }
    return *this;
}

template<typename T>
typename MutantStack<T>::iterator   MutantStack<T>::begin() { return this->c.begin(); }

template<typename T>
typename MutantStack<T>::iterator   MutantStack<T>::end() { return this->c.end(); }


#endif