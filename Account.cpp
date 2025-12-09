#include "Account.h"

void Account::Deposit(float amount)
{
    m_balance += amount;
}

void Account::Withdraw(float amount)
{
    if (m_balance - amount < MIN_BALANCE)
        throw InsufficientFunds();
    m_balance -= amount;
}

std::ofstream& operator << (std::ofstream& ofs, Account& acc)
{
    ofs << acc.m_accountNumber << std::endl;
    ofs << acc.m_firstName << std::endl;
    ofs << acc.m_lastName << std::endl;
    ofs << acc.m_balance << std::endl;
    return ofs;
}

std::ifstream& operator >> (std::ifstream& ifs, Account& acc)
{
    ifs >> acc.m_accountNumber;
    ifs >> acc.m_firstName;
    ifs >> acc.m_lastName;
    ifs >> acc.m_balance;
    return ifs;
}

std::ostream& operator << (std::ostream& os, Account& acc)
{
    os << "First Name: " << acc.getFirstName() << std::endl;
    os << "Last Name: " << acc.getLastName() << std::endl;
    os << "Account Number: " << acc.getAccNo() << std::endl;
    os << "Balance: $" << acc.getBalance() << std::endl;
    return os;
}