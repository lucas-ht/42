#include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->value = 0;
}

Fixed::Fixed(const Fixed& f) {
    std::cout << "Copy constructor called" << std::endl;
    this->value = f.getRawBits();
}

Fixed::Fixed(const int i) {
    setRawBits(i << this->mantis);
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float f) {
    this->value = roundf(f * (1 << this->mantis));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& f) {
    std::cout << "Copy assignment operator called" << std::endl;
    this->value = f.getRawBits();
    return *this;
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

std::ostream&   operator<< (std::ostream &o, Fixed const &f)
{
    return o << f.toFloat();
}