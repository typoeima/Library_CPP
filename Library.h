#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include "LibraryItem.h"
#include "Reader.h"
#include "Loan.h"

class Library {
private:
    std::vector<LibraryItem*> items;
    std::vector<Reader> readers;
    std::vector<Loan> loans;
    int nextItemId;
    int nextLoanId;

    LibraryItem* findItemPtr(int id) const;

public:
    Library();
    ~Library();

    bool isItemIdUnique(int id) const;
    bool isTicketUnique(int ticket) const;

    void addBook();
    void addMagazine();
    void addReader();
    void findById();
    void issueItem();
    void returnItem();
    void printAvailable() const;
    void printActiveLoans() const;
    void saveAll() const;

    void loadAll();

    void addBookDirect(const std::string& title, int year, const std::string& author, const std::string& isbn);
    void addMagazineDirect(const std::string& title, int year, int issueNumber, int month);
    void addReaderDirect(int ticket, const std::string& fullName);
};

#endif