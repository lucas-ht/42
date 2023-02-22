#include "Fixed.hpp"

Fixed::Fixed() {
    this->value = 0;
}

Fixed::Fixed(const Fixed& f) {
    this->value = f.getRawBits();
}

Fixed::Fixed(const int i) {
    setRawBits(i << this->mantis);
}

Fixed::Fixed(const float f) {
    this->value = roundf(f * (1 << this->mantis));
}

Fixed::~Fixed() {
}

Fixed& Fixed::operator= (const Fixed& f) {
    this->value = f.getRawBits();
    return *this;
}

bool    Fixed::operator> (const Fixed& f) const {
    return this->value > f.value;
}

bool    Fixed::operator< (const Fixed& f) const {
    return this->value < f.value;
}

bool    Fixed::operator<= (const Fixed& f) const {
    return this->value <= f.value;
}

bool    Fixed::operator>= (const Fixed& f) const {
    return this->value >= f.value;
}

bool    Fixed::operator== (const Fixed& f) const {
    return this->value == f.value;
}

bool    Fixed::operator!= (const Fixed& f) const {
    return this->value != f.value;
}

Fixed   Fixed::operator+ (const Fixed& f) const {
    return Fixed( this->toFloat() + f.toFloat() );
}

Fixed   Fixed::operator- (const Fixed& f) const {
    return Fixed( this->toFloat() - f.toFloat() );
}

Fixed   Fixed::operator* (const Fixed& f) const {
    return Fixed( this->toFloat() * f.toFloat() );
}
Fixed   Fixed::operator/ (const Fixed& f) const {
    return Fixed( this->toFloat() / f.toFloat() );
}

Fixed&  Fixed::operator++ () {
    this->value += 1;
    return *this;
}
Fixed   Fixed::operator++ (int) {
    Fixed   f = (*this);
    this->value += 1;
    return (f);
}
Fixed&  Fixed::operator-- () {
    this->value -= 1;
    return (*this);
}
Fixed   Fixed::operator-- (int) {
    Fixed   f = (*this);
    this->value -= 1;
    return (f);
}

int Fixed::getRawBits(void) const {
    return (this->value);
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

int Fixed::toInt(void) const
{
    return (int) getRawBits() >> this->mantis;
}

float   Fixed::toFloat(void) const
{
    return (float) getRawBits() / (1 << this->mantis);
}

const Fixed&  Fixed::max(const Fixed& f1, const Fixed& f2) {
    return (f1 > f2) ? f1 : f2;
}

const Fixed&  Fixed::min(const Fixed& f1, const Fixed& f2) {
    return (f1 < f2) ? f1 : f2;
}

std::ostream&   operator<< (std::ostream &o, Fixed const &f)
{
    return o << f.toFloat();
}