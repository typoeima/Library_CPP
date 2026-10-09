#include "LibraryItem.h"

LibraryItem::LibraryItem(int id, const std::string& title, int year, bool available)
    : id(id), title(title), year(year), available(available) {}

LibraryItem::~LibraryItem() {}

int LibraryItem::getId() const { return id; }
std::string LibraryItem::getTitle() const { return title; }
int LibraryItem::getYear() const { return year; }
bool LibraryItem::isAvailable() const { return available; }
void LibraryItem::setAvailable(bool value) { available = value; }

void LibraryItem::printInfo() const {
    std::cout << "id=" << id
              << " title=" << title
              << " year=" << year
              << " available=" << (available ? "yes" : "no");
}