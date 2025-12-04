// Factory pattern
// Invoker in Transaction's factory pattern
#pragma once
#include <string>
#include "Transaction.h"
#include <vector>
#include "Bank.h"
// Account pattern
class Account
{
public:
	virtual ~Account() {}

	virtual float getBalance() const = 0;
	virtual void setBalance(float) = 0;

	virtual void withdraw(float) = 0;
	virtual void deposite(float) = 0;
	virtual void transfer(float, Account*) = 0;
protected:
	Invoker* m_invoker;
	float m_balance;
	std::vector<Transaction*> m_history;
};

class SavingsAccount : public Account {
public:
	SavingsAccount();

	virtual float getBalance() const override;
	virtual void setBalance(float amount) override;

	virtual void withdraw(float amount) override;
	virtual void deposite(float amount) override;
	virtual void transfer(float amount,Account* other) override;
};

class CheckingAccount : public Account {
public:
	CheckingAccount();

	float getBalance() const override;
	void setBalance(float amount) override;

	void withdraw(float amount) override;
	void deposite(float amount) override;
	void transfer(float amount, Account* other) override;
};