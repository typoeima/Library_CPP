#include <iostream>
#include "LibraryItem.h"

LibraryItem::LibraryItem() : id(0), title(""), year(0), available(true) {}

LibraryItem::LibraryItem(int id, const std::string& title, int year, bool available)
    : id(id), title(title), year(year), available(available) {}

LibraryItem::~LibraryItem() {}

int LibraryItem::getId() const { return id; }
std::string LibraryItem::getTitle() const { return title; }
int LibraryItem::getYear() const { return year; }
bool LibraryItem::isAvailable() const { return available; }

void LibraryItem::setId(int value) { id = value; }
void LibraryItem::setTitle(const std::string& value) { title = value; }
void LibraryItem::setYear(int value) { year = value; }
void LibraryItem::setAvailable(bool value) { available = value; }