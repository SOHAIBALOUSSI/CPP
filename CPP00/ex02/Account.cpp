#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::displayAccountsInfos( void )
{
    Account::_displayTimestamp();
    std::cout << " accounts:"<< _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << "\n";
}
void    Account::makeDeposit(int deposit)
{
    Account::_displayTimestamp();
    int oldAmount = this->_amount;
    this->_amount += deposit;
    this->_totalAmount += deposit;
    this->_nbDeposits++;
    this->_totalNbDeposits++;
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << oldAmount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits << "\n";
}
bool    Account::makeWithdrawal(int withdrawal)
{
    Account::_displayTimestamp();
    int oldAmount = this->_amount;
    bool canWhitdraw = (this->_amount - withdrawal > 0);
    if (!canWhitdraw)
    {
        std::cout << " index:"<< this->_accountIndex
                  << ";p_amount:" << this->_amount << ";withdrawal:refused\n";
        return false;
    }
    this->_amount -= withdrawal;
    this->_totalAmount -= withdrawal;
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << oldAmount
              << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void    Account::_displayTimestamp(void)
{
    std::time_t now = std::time(NULL);
    std::tm* localTime = std::localtime(&now);
    if (!localTime)
    {
        std::cout << "[localtime failed]"; 
        return ;
    }
    char    buffer[80];
    std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer;  
}

Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
    Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              <<";amount:" << this->_amount
              << ";created\n";
}

Account::~Account(void)
{
    Account::_displayTimestamp();
    this->_nbAccounts--;
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed\n";
}