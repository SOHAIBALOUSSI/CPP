#include "Span.hpp"

typedef std::vector<int>::iterator vecIt;

struct randomGen {
	int operator()() { return rand() % 10000; }
};

Span::Span() : _size(0), _maxSize(0) {}

Span::~Span() {}

Span::Span(unsigned int n) : _size(0), _maxSize(n){}

Span::Span(const Span& other)
    : _ints(other._ints), _size(other._size), _maxSize(other._maxSize) {}

Span& Span::operator=(const Span& assign) {
    if (this != &assign) {
        _ints = assign._ints;
        _size = assign._size;
        _maxSize = assign._maxSize;
    }
    return *this;
}

unsigned int Span::getSize() const  { return _size; }

void    Span::addNumber(int num) {
    if (_size < _maxSize) {
       _ints.push_back(num);
        _size++;
        return ;
    }
    throw std::out_of_range("cannot add more numbers");
}

int    Span::shortestSpan() {
    if (_ints.size() < 2)
        throw std::runtime_error("cannot get shortestSpan : Low elements");
    int shortestSpan = std::numeric_limits<int>::max();

    std::sort(_ints.begin(), _ints.end());
    for (vecIt it = ++_ints.begin(); it != _ints.end(); it++) {
        int absDiff = std::abs(*it - *(it - 1));
        if (absDiff < shortestSpan) {
            shortestSpan = absDiff;
        }
    }
    return shortestSpan;
}

int Span::longestSpan() {
    if (_ints.size() < 2)
        throw std::runtime_error("cannot get longestSpan : Low elements");
    return (*std::max_element(_ints.begin(), _ints.end()) - *std::min_element(_ints.begin(), _ints.end()));
}

void    Span::fillRange() {
    _ints.resize(_maxSize);
    std::generate(_ints.begin(), _ints.end(), randomGen());
}