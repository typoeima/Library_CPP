#pragma once
#include <string>
#include <iostream>

class LibraryItem {
protected:
    int id;
    std::string title;
    int year;
    bool available;
public:
    LibraryItem(int id, const std::string& title, int year, bool available);
    virtual ~LibraryItem();
    int getId() const;
    std::string getTitle() const;
    int getYear() const;
    bool isAvailable() const;
    void setAvailable(bool value);
    virtual std::string type() const = 0;
    virtual void printInfo() const;
    virtual std::string specific1() const = 0;
    virtual std::string specific2() const = 0;
};