#include "CLI.h"

int CLI::mainMenu()
{
    std::cout << "***Banking System***" << std::endl;
    int result;
    std::cout << "\n\tSelect one option below:";
    std::cout << "\n\t1 Open an Account";
    std::cout << "\n\t2 Balance Enquiry";
    std::cout << "\n\t3 Deposit";
    std::cout << "\n\t4 Withdrawal";
    std::cout << "\n\t5 Close an Account";
    std::cout << "\n\t6 Show All Accounts";
    std::cout << "\n\t7 Quit";
    std::cout << "\nEnter your choice: ";
    std::cin >> result;
    return result;
}

void CLI::openAccount()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    std::cout << "Enter First Name: ";
    std::cin >> fname;
    std::cout << "Enter Last Name: ";
    std::cin >> lname;
    std::cout << "Enter initil Balance: ";
    std::cin >> balance;
    acc = b.OpenAccount(fname, lname, balance);

    system("cls");
    std::cout << "Congradulation Account is Created" << std::endl;
    std::cout << acc << std::endl;
}

void CLI::balanceEnquiry()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    std::cout << "Enter Account Number:";
    std::cin >> accountNumber;
    acc = b.BalanceEnquiry(accountNumber);

    system("cls");
    std::cout << "Your Account Details" << std::endl;
    std::cout << acc;
}

void CLI::deposit()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    std::cout << "Enter Account Number:";
    std::cin >> accountNumber;
    std::cout << "Enter Balance:";
    std::cin >> amount;
    acc = b.Deposit(accountNumber, amount);

    system("cls");
    std::cout << std::endl << "Amount is Deposited" << std::endl;
    std::cout << acc;
}

void CLI::withdraw()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    std::cout << "Enter Account Number:";
    std::cin >> accountNumber;
    std::cout << "Enter Balance:";
    std::cin >> amount;
    acc = b.Withdraw(accountNumber, amount);

    system("cls");
    std::cout << std::endl << "Amount Withdrawn" << std::endl;
    std::cout << acc;
}

void CLI::close()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    std::cout << "Enter Account Number:";
    std::cin >> accountNumber;
    b.CloseAccount(accountNumber);

    system("cls");
    std::cout << std::endl << "Account is Closed" << std::endl;
    std::cout << acc;
}

void CLI::showAll()
{
    system("cls");
    std::cout << "***Banking System***" << std::endl << std::endl;

    b.ShowAllAccounts();
}
