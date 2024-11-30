#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_value(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num) : _fixed_point_value(num << _fractionalBits)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num) : _fixed_point_value(roundf(num * static_cast<float>(1 << _fractionalBits)))
{
    std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->_fixed_point_value = other.getRawBits();
    }
    return (*this);
}
std::ostream &operator<<(std::ostream &os, const Fixed &fixed)
{
    os << fixed.toFloat();
    return (os);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "Copy assignment operator called" << std::endl;
    _fixed_point_value = raw;
}

int Fixed::toInt(void) const
{
    return (_fixed_point_value >> _fractionalBits);
}
float Fixed::toFloat(void) const
{
    return (_fixed_point_value / static_cast<float>(1 << _fractionalBits));
}
