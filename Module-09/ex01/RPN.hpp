#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <iostream>
#include <string>
#include <list>

class RPN {
private:
    std::list<std::string>      stack;

public:
    RPN();
    ~RPN();
    RPN(RPN const & src);
    RPN & operator=(RPN const & rhs);

    void parse(std::string av);
    void calculate();

    class InvalidInputException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid input";
        }
    };

};

#endif