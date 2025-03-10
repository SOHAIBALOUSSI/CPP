#ifndef SPAN_HPP
#define SPAN_HPP

#include <bits/stdc++.h>

class Span
{
private:
	std::vector<int> _ints;
	unsigned    _size;
	unsigned    _maxSize;
public:

	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& assign); 
	~Span();

	void		addNumber(int num);
	int			shortestSpan();
	int			longestSpan();
	unsigned	getSize() const;
	void		fillRange();
};


#endif