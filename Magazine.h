#pragma once
#include "LibraryItem.h"

class Magazine : public LibraryItem {
private:
    int issueNumber;
    int month;
public:
    Magazine(int id, const std::string& title, int year, bool available,
             int issueNumber, int month);
    std::string type() const override;
    void printInfo() const override;
    std::string specific1() const override;
    std::string specific2() const override;
    int getIssueNumber() const;
    int getMonth() const;
};