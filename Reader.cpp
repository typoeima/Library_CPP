#include "Reader.h"
#include <iostream>

Reader::Reader() : ticket(0), fullName("") {}

Reader::Reader(int ticket, const std::string& fullName)
    : ticket(ticket), fullName(fullName) {}

int Reader::getTicket() const { return ticket; }
std::string Reader::getFullName() const { return fullName; }

void Reader::setTicket(int value) { ticket = value; }
void Reader::setFullName(const std::string& value) { fullName = value; }

void Reader::printInfo() const {
    std::cout << "Читатель ticket=" << ticket
              << " | ФИО: " << fullName << "\n";
}