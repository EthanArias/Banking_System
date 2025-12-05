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
	virtual void deposit(float) = 0;
	virtual void transfer(float, Account*) = 0;
protected:
	friend Invoker;
	Invoker* m_invoker;
	float m_balance;
	std::vector<Transaction*> m_history;
private:
	void setBalance(float amount) { // made private so only the invoker can use it
		m_balance = amount;
	}
};

class SavingsAccount : public Account {
public:
	SavingsAccount();

	float getBalance() const override;

	void withdraw(float amount) override;
	void deposit(float amount) override;
	void transfer(float amount,Account* other) override;
private:
	void setBalance(float amount);
};

class CheckingAccount : public Account {
public:
	CheckingAccount();

	float getBalance() const override;

	void withdraw(float amount) override;
	void deposit(float amount) override;
	void transfer(float amount, Account* other) override;
private:
	void setBalance(float amount);
};