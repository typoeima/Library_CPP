#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;
    int month;

public:
    Magazine();
    Magazine(int id, const std::string& title, int year, bool available,
             int issueNumber, int month);

    int getIssueNumber() const;
    int getMonth() const;

    void setIssueNumber(int value);
    void setMonth(int value);

    std::string type() const override;
    void printInfo() const override;
};

#endif