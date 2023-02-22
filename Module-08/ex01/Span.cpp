#include "Span.hpp"

Span::Span() : v(0), n(0) {}

Span::Span(unsigned int n) : v(0), n(n) {}

Span::Span(const Span& s) {
    *this = s;
}

Span::~Span() {}

Span&   Span::operator=(const Span& s) {
    if (this == &s)
        return *this;

    this->n = s.n;
    this->v = s.v;

    return *this;
}

void    Span::addNumber(int n) {
    if (this->v.size() == this->n)
        throw Span::AlreadyFull();
    v.push_back(n);
}

int     Span::shortestSpan() {
    if (this->v.size() < 2)
        throw Span::NotEnoughValues();

    std::vector<int>            v = this->v;
    std::sort(v.begin(), v.end());

    int                         result = *(v.begin() + 1) - *v.begin();
    if (this->v.size() == 2)
        return result;

    std::vector<int>::iterator  it;
    for (it = v.begin() + 1; it != v.end() - 1; it++)
        result = (*(it + 1) - *it < result) ? *(it + 1) - *it : result;
    return result;
}

int     Span::longestSpan() {
    if (this->v.size() < 2)
        throw Span::NotEnoughValues();

    std::vector<int>    v = this->v;
    std::sort(v.begin(), v.end());
    return *(v.end() - 1) - *v.begin();
}

void    Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    std::vector<int>    v(begin, end);
    if (v.size() + this->v.size() >= this->n)
        throw Span::AlreadyFull();
    std::copy(v.begin(), v.end(), std::back_inserter(this->v));
}

const char  *Span::AlreadyFull::what() const throw() {
    return "Already full";
}

const char  *Span::NotEnoughValues::what() const throw() {
    return "Not enough values";
}
