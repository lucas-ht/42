#ifndef __SPAN_HPP__
#define __SPAN_HPP__

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span {
private:
    std::vector<int>    v;
    unsigned int        n;

    Span();

public:
    Span(unsigned int n);
    Span(const Span& s);
    ~Span();
    Span& operator=(const Span& s);

    void    addNumber(int n);
    int     shortestSpan();
    int     longestSpan();
    void    addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    class AlreadyFull : public std::exception {
    public:
        const char *what() const throw();
    };

    class NotEnoughValues : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif