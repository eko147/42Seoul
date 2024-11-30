#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
    int _fixed_point_number;
    static const int _fractionalBits = 8;

public:
    /*Orthodox Canonical Form*/
    Fixed();                              // Default constructor
    Fixed(const Fixed &fixed);            // Copy constructor
    Fixed &operator=(const Fixed &other); // Copy assignment operator
    ~Fixed();                             // Destructor

    int getRawBits(void) const;
    void setRawBits(int const raw);
};
#endif