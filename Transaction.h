// Command patern
#pragma once
#include "Account.h"
// Transaction interface
class Transaction
{
public:
	virtual ~Transaction() {
	}
	virtual void Execute() const = 0;

protected:
	void setRecieverAccount(Account* acc) { m_account = acc; };
	float m_amount;
	Account* m_account;
};

class Withdraw : public Transaction {
public:
	explicit Withdraw(float amount, Account* acc) {
		m_amount = amount;
		m_account = acc;
	};
	void Execute() const override {

	}
};

class Deposit : public Transaction {
public:
	explicit Deposit(float amount, Account* acc) {
		m_amount = amount;
		m_account = acc;
	};
	void Execute() const override {

	}
};

class Transfer : public Transaction {
public:
	explicit Transfer(float amount, Account* acc, Account* to) : m_to(to) {
		m_amount = amount;
		m_account = acc;
	};
	void Execute() const override {
		
	}
private:
	Account* m_to;
};

/* When an Account class uses it's member Invoker,
  the Invoker will execute the command and return a pointer to the Transaction object.
  The Account will store these Transaction objects as a transaction history.
*/
class Invoker {
public:
	~Invoker() {
	}

	Transaction* withdraw();
	Transaction* deposit();
	Transaction* transfer();
private:
	Account* m_account;
};