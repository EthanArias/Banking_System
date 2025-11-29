// Command patern
#pragma once
// Transaction interface
class Transaction
{
public:
	virtual ~Transaction() {
	}
	virtual void Execute() const = 0;
};

class Withdrawal : public Transaction {

};

class Deposit : public Transaction {

};

class Transfer : public Transaction {

};