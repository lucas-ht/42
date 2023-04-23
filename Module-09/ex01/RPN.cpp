#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const & src) {
    *this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
    if (this == &rhs)
        return *this;
    this->stack = rhs.stack;
    return *this;
}

void RPN::parse(std::string av) {
    std::string::iterator   it = av.begin();
    for (; it != av.end(); it++) {

        if (*it == ' ') { continue; }

        if (it + 1 != av.end() && *(it + 1) != ' ')
            throw RPN::InvalidInputException();

        if (!std::isdigit(*it) && (*it) != '+' && (*it) != '-' && (*it) != '*' && (*it) != '/' && (*it) != '%')
            throw RPN::InvalidInputException();

        std::string next(1, *it); 
        stack.push_back(next);
    }
    if (stack.size() < 3)
        throw RPN::InvalidInputException();
}

void RPN::calculate() {
    std::list<std::string>::iterator    it = this->stack.begin();
    int                                 a = 0;
    int                                 b = 0;
    int                                 c = 0;

    for (; it != this->stack.end(); it++) {

        char    op = (*it)[0];

        if (std::isdigit(op) || (op == '-' && (*it).size() > 1)) { continue; }

        if ( (*std::prev(it, 2)).empty() )
            throw RPN::InvalidInputException();

        a = std::stoi( *std::prev(it, 2) );
        b = std::stoi( *std::prev(it, 1) );

        switch (op) {
            case '+': { c = a + b; break; }
            case '-': { c = a - b; break; }
            case '*': { c = a * b; break; }
            case '/': { c = a / b; break; }
            case '%': { c = a % b; break; }
        }

        this->stack.insert(std::next(it, 1), std::to_string(c));
        this->stack.erase(std::prev(it, 2), std::next(it, 1));

        it = this->stack.begin();
    }

    for (std::list<std::string>::iterator it = this->stack.begin(); it != this->stack.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
