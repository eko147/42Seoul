#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_number(0)
{
    std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &fixed)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = fixed;
}
Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixed_point_number = other.getRawBits();
    }
    return (*this);
}
Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed_point_number);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fixed_point_number = raw;
}
