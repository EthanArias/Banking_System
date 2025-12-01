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

	float const getAmount() { return m_amount; };
	void setAmount(float a) { m_amount = a; };
protected:
	float m_amount=0.0;
};

class Withdrawal : public Transaction {

};

class Deposit : public Transaction {

};

class Transfer : public Transaction {
public:
	explicit Transfer(Account* from, Account* to, float amount) : m_from(from), m_to(to) {
		setAmount(amount);
	}
	void Execute() const override {
		
	}
private:
	Account* m_from;
	Account* m_to;
};