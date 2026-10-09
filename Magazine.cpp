#include "Magazine.h"

Magazine::Magazine(int id, const std::string& title, int year, bool available,
                   int issueNumber, int month)
    : LibraryItem(id, title, year, available), issueNumber(issueNumber), month(month) {}

std::string Magazine::type() const { return "Magazine"; }

void Magazine::printInfo() const {
    LibraryItem::printInfo();
    std::cout << " issueNumber=" << issueNumber << " month=" << month;
}

std::string Magazine::specific1() const { return std::to_string(issueNumber); }
std::string Magazine::specific2() const { return std::to_string(month); }
int Magazine::getIssueNumber() const { return issueNumber; }
int Magazine::getMonth() const { return month; }