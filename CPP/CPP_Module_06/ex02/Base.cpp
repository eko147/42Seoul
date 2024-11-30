#include "Base.hpp"

Base::~Base(){}

Base* generate() {
    std::srand(std::time(NULL));
    int randomValue = std::rand() % 3;
    switch (randomValue) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
        default:
            return NULL;
    }
}

void identify(Base* p) {
    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "A" << std::endl;
    } 
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "B" << std::endl;
    } 
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "C" << std::endl;
    } 
    else {
        std::cout << "Unknown" << std::endl;
    }
}

void refIdentify(Base& p, std::string type) {
 	try
	{
		if (type == "A")
			(void)dynamic_cast<A &>(p);
		if (type == "B")
			(void)dynamic_cast<B &>(p);
		if (type == "C")
			(void)dynamic_cast<C &>(p);
		std::cout << type << "'s Reference" << std::endl;
	}
	catch (std::exception &err){}
}

void identify(Base &p)
{
	refIdentify(p, "A");
	refIdentify(p, "B");
	refIdentify(p, "C");
}


