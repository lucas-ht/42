#include <iostream>
#include <iomanip>
#include "Account.hpp"

int Account::_nbAccounts                    = 0;
int Account::_totalAmount                   = 0;
int Account::_totalNbDeposits               = 0;
int Account::_totalNbWithdrawals            = 0;

int Account::getNbAccounts()                { return Account::_nbAccounts;          }
int Account::getTotalAmount()               { return Account::_totalAmount;         }
int Account::getNbDeposits()                { return Account::_totalNbDeposits;     }
int Account::getNbWithdrawals()             { return Account::_totalNbWithdrawals;  }

void    Account::displayAccountsInfos() {
    Account::_displayTimestamp();
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit) : _accountIndex(Account::_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    Account::_nbAccounts++;
    Account::_totalAmount += Account::checkAmount();
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << Account::checkAmount() << ";created" << std::endl;
}

Account::~Account() {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << Account::checkAmount() << ";closed" << std::endl;
    Account::_nbAccounts--;
    Account::_totalAmount -= Account::checkAmount();
}

void    Account::makeDeposit(int deposit) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << Account::checkAmount() << ";";
    std::cout << "deposit:" << deposit << ";";
    this->_amount += deposit;
    Account::_totalAmount += deposit;
    std::cout << "amount:" << Account::checkAmount() << ";";
    this->_nbDeposits++;
    Account::_totalNbDeposits++;
    std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool    Account::makeWithdrawal(int withdrawal) {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "p_amount:" << Account::checkAmount() << ";";
    if (Account::checkAmount() - withdrawal < 0) {
    	std::cout   << "withdrawal:refused" << std::endl;
    	return (false);
    }
    std::cout << "withdrawal:" << withdrawal << ";";
    this->_amount -= withdrawal;
    Account::_totalAmount -= withdrawal;
    std::cout << "amount:" << Account::checkAmount() << ";";
    this->_nbWithdrawals++;
    Account::_totalNbWithdrawals++;
    std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
    return (true);
}

int     Account::checkAmount() const {
    return this->_amount;
}

void    Account::displayStatus() const {
    Account::_displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << Account::checkAmount() << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp() {
    std::time_t t   = std::time(0);
    struct tm *now  = localtime(&t);
    std::cout << "[" << (now->tm_year + 1900);
    std::cout << std::setw(2) << std::setfill('0') << (now->tm_mon + 1);
    std::cout << std::setw(2) << std::setfill('0') << now->tm_mday;
    std::cout << '_';
    std::cout << std::setw(2) << std::setfill('0') << now->tm_hour;
    std::cout << std::setw(2) << std::setfill('0') << now->tm_min;
    std::cout << std::setw(2) << std::setfill('0') << now->tm_sec;
    std::cout << "] ";
}