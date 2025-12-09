#pragma once
#include "bank.h"
#include <cstdlib>
// command-line-interface
class CLI
{
public:
	CLI() {
		Bank b;
		Account acc;
		int choice = 0;
		std::string fname = "";
		std::string lname = "";
		long accountNumber = 0;
		float balance = 0.0;
		float amount = 0.0;
	};
	int mainMenu();
	void openAccount();
	void balanceEnquiry();
	void deposit();
	void withdraw();
	void close();
	void showAll();
private:
	Bank b;
	Account acc;
	int choice = 0;
	std::string fname, lname;
	long accountNumber = 0;
	float balance = 0.0;
	float amount = 0.0;
};