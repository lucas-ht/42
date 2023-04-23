#ifndef __BITCOIN_EXCHANGE_HPP__
#define __BITCOIN_EXCHANGE_HPP__

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include <sstream>
#include <map>

#define DATABASE_PATH                   "./data.csv"
#define DATABASE_SEPARATOR              ','
#define INPUT_SEPARATOR                 '|'

class BitcoinExchange {
private:
    std::map<int, float>    price;

    float   getPrice(int date);
    int     parseDate(std::string date);

    void    parseDatabase();

    void    showPrice(std::string date, std::string multiplier);

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const & src);
    BitcoinExchange & operator=(BitcoinExchange const & rhs);

    void    parseInput(std::string path);

    class InvalidFileException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid file";
        }
    };

    class InvalidDateException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid date";
        }
    };

    class InvalidPriceException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid price";
        }
    };

    class InvalidMultiplierException : public std::exception {
    public:
        virtual const char* what() const throw() {
            return "Invalid multiplier";
        }
    };
};


#endif
