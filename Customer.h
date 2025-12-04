#pragma once
#include <string>
#include "Bank.h"
class Customer
{
public:
	Customer(std::string fName, std::string lName);
	void viewAccounts();
private:
	std::string m_fName;
	std::string m_lName;
};

