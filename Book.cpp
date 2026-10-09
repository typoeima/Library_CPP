#include "Book.h"
#include <iostream>

Book::Book() : LibraryItem(), author(""), isbn("") {}

Book::Book(int id, const std::string& title, int year, bool available,
           const std::string& author, const std::string& isbn)
    : LibraryItem(id, title, year, available), author(author), isbn(isbn) {}

std::string Book::getAuthor() const { return author; }
std::string Book::getIsbn() const { return isbn; }

void Book::setAuthor(const std::string& value) { author = value; }
void Book::setIsbn(const std::string& value) { isbn = value; }

std::string Book::type() const { return "Book"; }

void Book::printInfo() const {
    std::cout << "Книга id=" << id
              << " | название: " << title
              << " | год: " << year
              << " | доступно: " << (available ? "да" : "нет")
              << " | автор: " << author
              << " | ISBN: " << isbn << "\n";
}