#include "Iter.hpp"

int main()
{
	std::string array[3] = {"HI", "IM", "EUNJI"};
	int i[3] = {0, 1, 2};
	double d[4] = {0.0, 1.1, 2.2, 3.3};
	char c[5] = {'e', 'u', 'n', 'j', 'i'};

	::iter(array, 3, ::print);
    std::cout << std::endl;
	::iter(i, 3, ::print);
    std::cout << std::endl;
	::iter(d, 4, ::print);
    std::cout << std::endl;
	::iter(c, 5, ::print);
	return 0;
}