#include "Reader.h"

Reader::Reader(int ticket, const std::string& fullName)
    : ticket(ticket), fullName(fullName) {}

int Reader::getTicket() const { return ticket; }
std::string Reader::getFullName() const { return fullName; }