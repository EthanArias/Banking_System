#pragma once
#include "Account.h";

class AccountCreator {
public:
	virtual ~AccountCreator() {};
	virtual Account* FactoryMethod() const = 0;
};

class ConcreteSavingsAccountCreator : public AccountCreator {
public:
	Account* FactoryMethod() const override {
		return new SavingsAccount();
	}
};

class ConcreteCheckingAccountCreator : public AccountCreator {
public:
	Account* FactoryMethod() const override {
		return new CheckingAccount();
	}
};