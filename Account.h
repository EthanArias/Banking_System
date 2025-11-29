// Factory pattern
#pragma once
#include <string>
#include "Transact.h"
// Account pattern
class Account
{
public:
public:
	virtual ~Account() {}
	virtual std::string Operation() const = 0;
private:
	float m_balance;
};

class SavingsAccount : public Account {

};

class CheckingAccount : public Account {

};