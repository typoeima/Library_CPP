#include "Book.h"

Book::Book(int id, const std::string& title, int year, bool available,
           const std::string& author, const std::string& isbn)
    : LibraryItem(id, title, year, available), author(author), isbn(isbn) {}

std::string Book::type() const { return "Book"; }

void Book::printInfo() const {
    LibraryItem::printInfo();
    std::cout << " author=" << author << " isbn=" << isbn;
}

std::string Book::specific1() const { return author; }
std::string Book::specific2() const { return isbn; }
std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }