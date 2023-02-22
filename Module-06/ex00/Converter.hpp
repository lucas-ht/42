#ifndef __CONVERTER_HPP__
#define __CONVERTER_HPP__

#include <iostream>
#include <string>
#include <limits>

class Converter {
private:
    enum vType { STRING, DOUBLE };

    vType           valueType;
    std::string     valueString;
    double          valueDouble;

    void            convertType(std::string value);

    void            printChar();
    void            printInt();
    void            printFloat();
    void            printDouble();

    Converter();

public:
    Converter(std::string value);
    Converter(const Converter& c);
    ~Converter();
    Converter& operator=(const Converter& c);

    void            print();

    class InvalidValue : public std::exception {
    public:
        const char *what() const throw();
    };
};

#endif