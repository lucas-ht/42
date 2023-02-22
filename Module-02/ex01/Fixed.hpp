#ifndef __FIXED_HPP__
#define __FIXED_HPP__

#include <iostream>
#include <fstream>
#include <cmath>

class Fixed {
private:
    static const int    mantis = 8;
    int                 value;

public:
    Fixed();
    Fixed(const Fixed& f);
    Fixed(const int i);
    Fixed(const float f);
    ~Fixed();
    Fixed& operator=(const Fixed& f);

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
};

std::ostream&   operator<< (std::ostream &o, Fixed const &f);

#endif