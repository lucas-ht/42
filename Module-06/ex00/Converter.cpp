#include "Converter.hpp"

Converter::Converter() : valueType(STRING), valueString(""), valueDouble(0) {}

Converter::Converter(std::string value) : valueString(""), valueDouble(0) {
    this->convertType(value);
}

Converter::Converter(const Converter& c) {
    *this = c;
}

Converter::~Converter() {}

Converter&  Converter::operator=(const Converter& c) {
    if (this == &c)
        return *this;
    this->valueString = c.valueString;
    this->valueDouble = c.valueDouble;
    return *this;
}

void    Converter::convertType(std::string value) {
    if (value.length() == 1 && std::isalpha(value[0])) {
        this->valueDouble = static_cast<int>(value[0]);
        this->valueType = DOUBLE;
        return;
    }

    if (std::isalpha(value[0]))
        throw Converter::InvalidValue();

    if (value == "-inff" || value == "+inff" || value == "nanf" || value == "-inf" || value == "+inf" || value == "nan") {
        this->valueString = value;
        this->valueType = STRING;
        return;
    }

    this->valueDouble = std::stod(value);
    this->valueType = DOUBLE;
}

void    Converter::printChar() {
    if (this->valueType == STRING) {
        std::cout << "impossible";
        return;
    }

    char    c = static_cast<char>(this->valueDouble);

    if (!std::isprint(c)) {
        std::cout << "Non displayable";
        return;
    }

    std::cout << "'" << c << "'";
}

void    Converter::printInt() {
    if (this->valueType == STRING) {
        std::cout << "impossible";
        return;
    }
    if (this->valueDouble > std::numeric_limits<int>::max() || this->valueDouble < std::numeric_limits<int>::lowest()) {
        std::cout << "impossible";
        return;
    }

    int     i = static_cast<int>(this->valueDouble);
    std::cout << i;
}

void    Converter::printFloat() {
    if (this->valueType == STRING) {
        if (this->valueString == "-inf")
            std::cout << "-inff";
        else if (this->valueString == "+inf")
            std::cout << "+inff";
       else if (this->valueString == "nan")
            std::cout << "nanf";
        else
            std::cout << this->valueString;
        return;
    }

    if (this->valueDouble > std::numeric_limits<float>::max() || this->valueDouble < std::numeric_limits<float>::lowest()) {
        std::cout << "impossible";
        return;
    }

    float   f = static_cast<float>(this->valueDouble);
    int     i = static_cast<int>(this->valueDouble);

    std::cout << f << (f - i ? "f" : ".0f");
}

void    Converter::printDouble() {
    if (this->valueType == STRING) {
        if (this->valueString == "-inff")
            std::cout << "-inf";
        else if (this->valueString == "+inff")
            std::cout << "+inf";
       else if (this->valueString == "nanf")
            std::cout << "nan";
        else
            std::cout << this->valueString;
        return;
    }

    int     i = static_cast<int>(this->valueDouble);
    std::cout << this->valueDouble << (this->valueDouble - i ? "" : ".0");
}

void    Converter::print() {
    std::cout << "char: "; this->printChar(); std::cout << std::endl;
    std::cout << "int: "; this->printInt(); std::cout << std::endl;
    std::cout << "float: "; this->printFloat(); std::cout << std::endl;
    std::cout << "double: "; this->printDouble(); std::cout << std::endl;
}

const char  *Converter::InvalidValue::what() const throw() {
    return "Invalid value";
}