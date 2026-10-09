#ifndef BOOK_H
#define BOOK_H

#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string author;
    std::string isbn;

public:
    Book();
    Book(int id, const std::string& title, int year, bool available,
         const std::string& author, const std::string& isbn);

    std::string getAuthor() const;
    std::string getIsbn() const;

    void setAuthor(const std::string& value);
    void setIsbn(const std::string& value);

    std::string type() const override;
    void printInfo() const override;
};

#endif