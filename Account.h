// Factory pattern
#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
// Account pattern
class Account
{
public:
	virtual ~Account() {}
	virtual std::string Operation() const = 0;

	virtual float getBalance() const = 0;
	virtual void setBalance(float) const = 0;

	virtual void withdraw(float) const = 0;
	virtual void deposite(float) const = 0;
	virtual void transfer(float) const = 0;
protected:
	float m_balance;
	std::vector<Transaction*> m_history;
};

class SavingsAccount : public Account {

};

class CheckingAccount : public Account {

};