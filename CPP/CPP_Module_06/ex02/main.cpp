#include "Base.hpp"

int main()
{
	Base* randomValue = generate();

	identify(randomValue);
	identify(*randomValue);

	delete randomValue;
	return 0;
}