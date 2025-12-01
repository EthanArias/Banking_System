#pragma once
#include "Account.h";

class AccountCreator {
public:
	virtual ~AccountCreator() {};
	virtual Account* FactoryMethod() const = 0;
};

class ConcreteSavingsAccountCreator : public AccountCreator {

};

class ConcreteCheckingAccountCreator : public AccountCreator {

};