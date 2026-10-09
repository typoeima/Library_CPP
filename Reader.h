#ifndef READER_H
#define READER_H

#include <string>

class Reader {
private:
    int ticket;
    std::string fullName;

public:
    Reader();
    Reader(int ticket, const std::string& fullName);

    int getTicket() const;
    std::string getFullName() const;

    void setTicket(int value);
    void setFullName(const std::string& value);

    void printInfo() const;
};

#endif