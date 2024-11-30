#include "Fixed.hpp"

Fixed::Fixed() : _fixed_point_value(0) {}

Fixed::Fixed(const int num) : _fixed_point_value(num << _fractionalBits) {}

Fixed::Fixed(const float num) : _fixed_point_value(roundf(num * static_cast<float>(1 << _fractionalBits))) {}

Fixed::Fixed(const Fixed &fixed)
{
    *this = fixed;
}

Fixed &Fixed::operator=(const Fixed &other)
{
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
Fixed::~Fixed() {}

int Fixed::getRawBits() const
{
    return (_fixed_point_value);
}

void Fixed::setRawBits(int const raw)
{
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

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    return (a < b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

/*comparison operators*/

bool Fixed::operator<(const Fixed &fixed) const
{
    return (this->_fixed_point_value < fixed._fixed_point_value);
}
bool Fixed::operator>(const Fixed &fixed) const
{
    return (this->_fixed_point_value > fixed._fixed_point_value);
}
bool Fixed::operator<=(const Fixed &fixed) const
{
    return (this->_fixed_point_value <= fixed._fixed_point_value);
}
bool Fixed::operator>=(const Fixed &fixed) const
{
    return (this->_fixed_point_value >= fixed._fixed_point_value);
}

bool Fixed::operator==(const Fixed &fixed) const
{
    return (this->_fixed_point_value == fixed._fixed_point_value);
}

bool Fixed::operator!=(const Fixed &fixed) const
{
    return (this->_fixed_point_value != fixed._fixed_point_value);
}

/*arithmetic operators*/

Fixed Fixed::operator+(const Fixed &fixed)
{
    Fixed newFixed(this->toFloat() + fixed.toFloat());
    return (newFixed);
};

Fixed Fixed::operator-(const Fixed &fixed)
{
    Fixed newFixed(this->toFloat() - fixed.toFloat());
    return (newFixed);
};

Fixed Fixed::operator*(const Fixed &fixed)
{
    Fixed newFixed(this->toFloat() * fixed.toFloat());
    return (newFixed);
};

Fixed Fixed::operator/(const Fixed &fixed)
{
    Fixed newFixed(this->toFloat() / fixed.toFloat());
    return (newFixed);
};

/*increment/decrement opoerators*/

Fixed &Fixed::operator++()
{
    this->_fixed_point_value++;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed old(*this);
    this->_fixed_point_value++;
    return old;
}

Fixed &Fixed::operator--()
{
    this->_fixed_point_value--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed old(*this);
    this->_fixed_point_value--;
    return old;
}
