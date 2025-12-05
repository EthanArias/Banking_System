// thread-safe singlton
#pragma once
#include <mutex>
class Database
{
public:
    Database(Database& other) = delete;
    void operator=(const Database&) = delete;
    static Database* GetInstance(const std::string& value);
protected:
    Database();
    ~Database() {};
private:
    static Database* s_instance;
    static std::mutex s_mutex;
};

Database* Database::s_instance{ nullptr };
std::mutex Database::s_mutex;