#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
    return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
    return Account::_totalAmount;
}

int	Account::getNbDeposits( void )
{
    return Account::_totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
    return Account::_totalNbWithdrawals;
}

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
    this->_nbDeposits++;
    std::cout << " index:" << this->_accountIndex
              << ";p_amount" << oldAmount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits" << this->_nbDeposits << "\n";
    this->_totalNbDeposits++;
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
    this->_nbWithdrawals++;
    this->_totalNbWithdrawals++;
    std::cout << " index:" << this->_accountIndex
              << ";p_amount:" << oldAmount
              << ";withdrawal:" << withdrawal
              << ";amount:" << this->_amount
              << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
    return true;
}
int     Account::checkAmount(void) const
{
    return (Account::_amount);
}

void    Account::_displayTimestamp(void)
{
    std::time_t now = std::time(0);
    std::tm* localTime = std::localtime(&now);
    char    buffer[80];

    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", localTime);
    std::cout << buffer;  
}

void    Account::displayStatus(void) const
{
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->checkAmount()
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals << "\n";

}

Account::Account(void)
{
}



Account::Account(int initial_deposit)
{
    this->_accountIndex = Account::_nbAccounts++;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    Account::_totalAmount += initial_deposit;
    Account::_displayTimestamp();
    std::cout << " index:" << this->_accountIndex <<";amount:" << this->_amount << ";created\n";
}


Account::~Account(void)
{
    Account::_displayTimestamp();
    this->_nbAccounts--;
    std::cout << " index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed\n";
}