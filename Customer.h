#pragma once
#include <string>
#include "AccountCreator.h"

class Customer
{
public:
	Customer(std::string fName, std::string lName);
	void viewAccounts();
private:
	std::string m_fName;
	std::string m_lName;
};

