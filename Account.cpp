#include "Account.h"

SavingsAccount::SavingsAccount()
{
}

float SavingsAccount::getBalance() const
{
	return m_balance;
}

void SavingsAccount::setBalance(float amount)
{
	m_balance = amount;
}

void SavingsAccount::withdraw(float amount)
{
	m_history.push_back(m_invoker->withdraw(amount));
}

void SavingsAccount::deposit(float amount)
{
	m_history.push_back(m_invoker->deposit(amount));
}

void SavingsAccount::transfer(float amount, Account* other)
{
	m_history.push_back(m_invoker->transfer(amount, other));
}

CheckingAccount::CheckingAccount()
{
}

float CheckingAccount::getBalance() const
{
	return m_balance;
}

void CheckingAccount::setBalance(float amount)
{
	m_balance = amount;
}

void CheckingAccount::withdraw(float amount)
{
	m_history.push_back(m_invoker->withdraw(amount));
}

void CheckingAccount::deposit(float amount)
{
	m_history.push_back(m_invoker->deposit(amount));
}

void CheckingAccount::transfer(float amount, Account* other)
{
	m_history.push_back(m_invoker->transfer(amount, other));
}