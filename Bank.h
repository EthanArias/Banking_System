// save info with momento pattern
// connect customers with mediator pattern
// alows customers to manage there account through the mediator pattern with command pattern
// thread-safe singlton
#pragma once
#include "AccountCreator.h"
#include "Database.h"
#include <mutex>
class Bank
{
public:
    Bank(Bank& other) = delete;
    void operator=(const Bank&) = delete;
    static Bank* GetInstance(const std::string& value);
protected:
    Bank(const std::string value) : value_(value) {};
    ~Bank() {}
    std::string value_;
private:
	static Bank* s_instance;
	static std::mutex s_mutex;
    Database* m_database;
};

Bank* Bank::s_instance{ nullptr };
std::mutex Bank::s_mutex;