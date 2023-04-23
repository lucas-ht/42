#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    this->parseDatabase();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & src) {
    *this = src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange const & rhs) {
    if (this == &rhs)
        return *this;
    this->price = rhs.price;
    return *this;
}


float BitcoinExchange::getPrice(int date) {
    if (this->price.find(date) != this->price.end())
        return this->price[date];

    std::map<int, float>::iterator it;
    it = this->price.upper_bound(date);
    if (it != this->price.begin())
        --it;
    return it->second;
}

int BitcoinExchange::parseDate(std::string date) {
    std::stringstream   stream(date);
    std::string         ymd[3];
    int                 y, m, d;
    int                 sum = 0;

    for (int i = 0; i < 3; i++) {
        std::getline(stream, ymd[i], '-');
        if (ymd[i].empty())
            throw BitcoinExchange::InvalidDateException();
    }
    y = std::stoi(ymd[0]);
    m = std::stoi(ymd[1]);
    d = std::stoi(ymd[2]);

    int                 days[12] = {31, (y - 2000) % 4 == 0 ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (y < 2000)
        throw BitcoinExchange::InvalidDateException();
    while (y > 2000) { sum += 365 + (y % 4 == 0 ? 1 : 0); y--; }

    if (m < 1 || m > 12)
        throw BitcoinExchange::InvalidDateException();
    for (int i = 0; i < m - 1; i++) { sum += days[i]; }

    if (d < 1 || d > days[m - 1])
        throw BitcoinExchange::InvalidDateException();
    sum += d;

    return sum;
}


void BitcoinExchange::parseDatabase() {
    std::ifstream       file(DATABASE_PATH);
    if (file.fail())
        throw BitcoinExchange::InvalidFileException();

    std::string         line;
    std::string         date;
    std::string         price;
    float               rate;

    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::getline(stream, date, DATABASE_SEPARATOR);
        std::getline(stream, price, DATABASE_SEPARATOR);

        if (date.empty())
            throw BitcoinExchange::InvalidDateException();
        if (price.empty())
            throw BitcoinExchange::InvalidPriceException();
        if (date == "date" || price == "exchange_rate")
            continue;

        rate = std::stof(price);
        if (rate < 0)
            throw BitcoinExchange::InvalidPriceException();
        this->price[this->parseDate(date)] = rate;
    }
}

void BitcoinExchange::showPrice(std::string date, std::string multiplier) {
    if (date.empty())
        throw BitcoinExchange::InvalidDateException();
    if (multiplier.empty())
        throw BitcoinExchange::InvalidMultiplierException();
    if (date == "date " || multiplier == " value")
        return;

    int     d = this->parseDate(date);
    float   m = std::stof(multiplier);

    if (m < 0 || m > 1000)
        throw BitcoinExchange::InvalidMultiplierException();

    float   price = this->getPrice(d) * m;

    std::cout << date << "=>" << multiplier << " = " << price << std::endl;
}

void BitcoinExchange::parseInput(std::string path) {
    std::ifstream       file(path);
    if (file.fail())
        throw BitcoinExchange::InvalidFileException();

    std::string         line;
    std::string         date;
    std::string         multiplier;

    while (std::getline(file, line)) {
         std::stringstream stream(line);
        std::getline(stream, date, INPUT_SEPARATOR);
        std::getline(stream, multiplier, INPUT_SEPARATOR);

        try {
            this->showPrice(date, multiplier);
        }
        catch(const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    }
}
