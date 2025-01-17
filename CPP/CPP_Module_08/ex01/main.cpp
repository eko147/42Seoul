#include "Span.hpp"

int main()
{
    Span sp = Span(5);

    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl; 
    std::cout << sp.longestSpan() << std::endl;
	
	try
	{
		Span tmp = Span(1);
		tmp.addNumber(1);
		tmp.addNumber(2);
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

    try
	{
		Span tmp = Span(3);
		tmp.addNumber(1);

		std::cout << tmp.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}

   
    return 0;
}
