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
    Fixed&  operator= (const Fixed& f);
    bool    operator> (const Fixed& f) const;
    bool    operator< (const Fixed& f) const;
    bool    operator<= (const Fixed& f) const;
    bool    operator>= (const Fixed& f) const;
    bool    operator== (const Fixed& f) const;
    bool    operator!= (const Fixed& f) const;
    Fixed&  operator++ ();
    Fixed   operator++ (int i);
    Fixed&  operator-- ();
    Fixed   operator-- (int);
    Fixed   operator+ (const Fixed& f) const;
    Fixed   operator- (const Fixed& f) const;
    Fixed   operator/ (const Fixed& f) const;
    Fixed   operator* (const Fixed& f) const;

    int     getRawBits(void) const;
    void    setRawBits(int const raw);
    float   toFloat(void) const;
    int     toInt(void) const;
    static const Fixed&  max(const Fixed& f1, const Fixed& f2);
    static const Fixed&  min(const Fixed& f1, const Fixed& f2);
};

std::ostream&   operator<< (std::ostream &o, Fixed const &f);

#endif