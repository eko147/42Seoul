#include "Span.hpp"

Span::Span() {}

Span::Span(unsigned int N) : _span(0){

    this->_span.reserve(N);
}

Span::Span(const Span &other){
	*this = other;
}

Span &Span::operator=(const Span &obj)
{
    if (this == &obj)
		return (*this);
    this->_span.clear();
    this->_span = obj._span;
	return (*this);
}

void Span::addNumber(int number){
    if(_span.capacity() == _span.size())
        throw SpanIsFull();
    _span.push_back(number);
}


int Span::longestSpan()
{
    if (_span.size() < 2)
		throw NumbersNotEnough();
    std::vector<int> tmp = _span;
    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

int Span::shortestSpan() {
    if (_span.size() < 2)
		throw NumbersNotEnough();
    std::vector<int> tmp = _span;
    std::sort(tmp.begin(), tmp.end());
    int min = std::abs(tmp[1] - tmp[0]);
    for(unsigned int i = 2; i < _span.size(); i++)
    {
        int len = std::abs(tmp[i] - tmp[i - 1]);
        if(len < min)
            min = len;
    }
    return (min);
}

const char *Span::SpanIsFull::what() const throw(){
    return "Span is full: cannot add more numbers";
}

const char *Span::NumbersNotEnough::what() const throw(){
    return "Not enough numbers to calculate span";
}

Span::~Span(){};