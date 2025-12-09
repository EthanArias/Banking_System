#pragma once
#include "Account.h"
#include <map>
#include <vector>
class Bank
{
public:
    Bank() {
        std::map <long, Account> accounts = std::map <long, Account>();
        m_topAccountNumber = 0;
    }
    Account OpenAccount(std::string fname, std::string lname, float balance);

    Account BalanceEnquiry(long accountNumber);
    Account Deposit(long accountNumber, float amount);
    Account Withdraw(long accountNumber, float amount);

    void CloseAccount(long accountNumber);
    void ShowAllAccounts();
    ~Bank();
private:
    std::map <long,Account> accounts;
    long m_topAccountNumber;
};