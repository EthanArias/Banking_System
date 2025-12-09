#pragma once
#include <iostream>
#include <string>
#include <fstream>

#define MIN_BALANCE 500

class InsufficientFunds {
};
class Account
{
public:
    Account() {};
    Account(std::string fname, std::string lname, float balance, long number) {
        m_accountNumber = number;
        m_firstName = fname;
        m_lastName = lname;
        this->m_balance = balance;
    };

    long getAccNo() const{
        return m_accountNumber;
    }
    std::string getFirstName(){
        return m_firstName;
    }
    std::string getLastName(){
        return m_lastName;
    }

    float getBalance() const{
        return m_balance;
    }
    void Deposit(float amount);
    void Withdraw(float amount);

    friend std::ofstream& operator << (std::ofstream& ofs, Account& acc);
    friend std::ifstream& operator >> (std::ifstream& ifs, Account& acc);
    friend std::ostream& operator << (std::ostream& os, Account& acc);
private:
    long m_accountNumber;
    std::string m_firstName;
    std::string m_lastName;
    float m_balance;
};