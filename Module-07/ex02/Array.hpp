#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template <typename T>
class Array {
private:
    T               *array;
    unsigned int    len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& a);
    ~Array();
    Array&  operator=(const Array& a);
    T&      operator[](const unsigned int i);

    unsigned int  size() const;

    class InvalidIndex : public std::exception {
    public:
        const char *what() const throw();
    };
};

#include "Array.tpp"

#endif