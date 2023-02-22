#ifndef __HARL_HPP__
# define __HARL_HPP__

#include <iostream>
#include <string>

class Harl {
private:
    void    debug();
    void    info();
    void    warning();
    void    error();

    int     getLevel( std::string level );

public:
    void complain( std::string level );

};

#endif