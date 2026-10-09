#pragma once
#include "LibraryItem.h"

class Book : public LibraryItem {
private:
    std::string author;
    std::string isbn;
public:
    Book(int id, const std::string& title, int year, bool available,
         const std::string& author, const std::string& isbn);
    std::string type() const override;
    void printInfo() const override;
    std::string specific1() const override;
    std::string specific2() const override;
    std::string getAuthor() const;
    std::string getIsbn() const;
};