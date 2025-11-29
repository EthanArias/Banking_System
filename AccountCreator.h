#pragma once
#include "Account.h";

class Creator {
public:
	virtual ~Creator() {};
	virtual Account* FactoryMethod() const = 0;
};

class ConcreteSavingsAccountCreator : public Creator {

};

class ConcreteCheckingAccountCreator : public Creator {

};