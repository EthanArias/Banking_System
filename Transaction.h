// Command patern
#pragma once
#include "Account.h"
// Transaction interface
class Transaction
{
public:
	virtual ~Transaction() {
	}
	virtual float Execute() const = 0;

protected:
	float m_amount;
	Account* m_account;
};

class Withdraw : public Transaction {
public:
	explicit Withdraw(float amount, Account* acc) {
		m_amount = amount;
		m_account = acc;
	};
	float Execute() const override {
		if (m_account->getBalance() > m_amount) {
			return m_account->getBalance() - m_amount;
		};
	}
};

class Deposit : public Transaction {
public:
	explicit Deposit(float amount, Account* acc) {
		m_amount = amount;
		m_account = acc;
	};
	float Execute() const override {
		return m_account->getBalance() + m_amount;
	}
};

class Transfer : public Transaction {
public:
	explicit Transfer(float amount, Account* me, Account* you) : m_to(you) {
		m_amount = amount;
		m_account = me;
	};
	float Execute() const override {
		if (m_account->getBalance() > m_amount) {
			return m_account->getBalance() - m_amount;
		}
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

	Transaction* withdraw(float amount) {
		Withdraw* withdrawTransaction = new Withdraw(amount,m_account);
		m_account->setBalance(withdrawTransaction->Execute());

		return withdrawTransaction;
	};
	Transaction* deposit(float amount) {
		Deposit* depositTransaction = new Deposit(amount, m_account);
		m_account->setBalance(depositTransaction->Execute());

		return depositTransaction;
	}
	Transaction* transfer(float amount, Account* other) {
		Transfer* outTransfer = new Transfer(amount, m_account, other);
		m_account->setBalance(outTransfer->Execute());

		Transfer* inTransfer = new Transfer(invert(amount), other, m_account);
		other->setBalance(inTransfer->Execute());
		
		other->m_history.push_back(inTransfer);
		return outTransfer;
	};
private:
	Account* m_account;
	float invert(float x) {// this funcion let me use the same transfer opject to both take from and give to accounts
		return (x * -1);
	};
};