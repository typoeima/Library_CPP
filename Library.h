#pragma once
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
    int nextLoanId;
public:
    Library();
    ~Library();

    bool idExists(int id) const;
    bool ticketExists(int ticket) const;

    void addBook();
    void addMagazine();
    void registerReader();
    void findItemById();
    void issueItem();
    void returnItem();
    void printAvailable();
    void printActiveLoans();
    void save();
    void load();
};