#include "Harl.hpp"

void    Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do !" << std::endl << std::endl;
}

void    Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking for more !" << std::endl << std::endl;
}

void    Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl << std::endl;
}

void    Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable ! I want to speak to the manager now." << std::endl << std::endl;
}

int     Harl::getLevel( std::string level ) {
    std::string levels[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    for (int i = 0; i < 4; i++) {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void    Harl::complain( std::string level ) {

    switch (this->getLevel(level)) {
        case -1: { std::cout << "[ Probably complaining about insignificant problems ]" << std::endl; break; }
        case 0:  { this->debug(); }
        case 1:  { this->info(); }
        case 2:  { this->warning(); }
        case 3:  { this->error(); }
    }
}