#include "Magazine.h"
#include <iostream>

Magazine::Magazine() : LibraryItem(), issueNumber(0), month(1) {}

Magazine::Magazine(int id, const std::string& title, int year, bool available,
                   int issueNumber, int month)
    : LibraryItem(id, title, year, available), issueNumber(issueNumber), month(month) {}

int Magazine::getIssueNumber() const { return issueNumber; }
int Magazine::getMonth() const { return month; }

void Magazine::setIssueNumber(int value) { issueNumber = value; }
void Magazine::setMonth(int value) { month = value; }

std::string Magazine::type() const { return "Magazine"; }

void Magazine::printInfo() const {
    std::cout << "Журнал id=" << id
              << " | название: " << title
              << " | год: " << year
              << " | доступно: " << (available ? "да" : "нет")
              << " | выпуск: " << issueNumber
              << " | месяц: " << month << "\n";
}