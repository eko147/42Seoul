#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
private:
    std::vector<int> _span;
    Span();
public:

    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &obj);
    ~Span();  

    void addNumber(int number);
    int shortestSpan();
    int longestSpan();

    class SpanIsFull : public std::exception
    {
		const char *what() const throw();
    };
    class NumbersNotEnough : public std::exception
    {
		const char *what() const throw();
    };
};

#endif