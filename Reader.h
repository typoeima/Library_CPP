#pragma once
#include <string>

class Reader {
private:
    int ticket;
    std::string fullName;
public:
    Reader(int ticket, const std::string& fullName);
    int getTicket() const;
    std::string getFullName() const;
};