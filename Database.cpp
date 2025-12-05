#include "Database.h"

Database* Database::GetInstance(const std::string& value)
{
    std::lock_guard<std::mutex> lock(s_mutex);
    if (s_instance == nullptr)
    {
        s_instance = new Database();
    }
    return s_instance;
}