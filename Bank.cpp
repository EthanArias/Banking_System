#include "Bank.h"

Account Bank::OpenAccount(std::string fname, std::string lname, float balance){
    //std::ofstream outfile;
    Account account(fname, lname, balance, ++m_topAccountNumber);
    accounts.insert(std::pair < long, Account >(m_topAccountNumber, account));
    /*outfile.open("Bank.data", std::ios::trunc);
    std::map < long, Account >::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++)
    {
        outfile << itr->second;
    }
    outfile.close();*/
    return account;
}

Account Bank::BalanceEnquiry(long accountNumber){
    std::map < long, Account >::iterator itr = accounts.find(accountNumber);
    return itr->second;
}

Account Bank::Deposit(long accountNumber, float amount){
    std::map < long, Account >::iterator itr = accounts.find(accountNumber);
    itr->second.Deposit(amount);
    return itr->second;
}

Account Bank::Withdraw(long accountNumber, float amount){
    std::map < long, Account >::iterator itr = accounts.find(accountNumber);
    itr->second.Withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(long accountNumber){
    std::map < long, Account >::iterator itr = accounts.find(accountNumber);
    std::cout << "Account Deleted" << itr->second;
    accounts.erase(accountNumber);
}

void Bank::ShowAllAccounts()
{
    std::map < long, Account >::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        std::cout << "Account " << itr->first << std::endl << itr->second << std::endl;
    }
}

Bank::~Bank(){
    std::ofstream outfile;
    outfile.open("Bank.data", std::ios::trunc);
    std::map < long, Account >::iterator itr;
    for (itr = accounts.begin(); itr != accounts.end(); itr++){
        outfile << itr->second;
    }
    outfile.close();
}