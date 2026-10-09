#ifndef LIBRARYITEM_H
#define LIBRARYITEM_H

#include <string>

class LibraryItem {
protected:
    int id;
    std::string title;
    int year;
    bool available;

public:
    LibraryItem();
    LibraryItem(int id, const std::string& title, int year, bool available);
    virtual ~LibraryItem();

    int getId() const;
    std::string getTitle() const;
    int getYear() const;
    bool isAvailable() const;

    void setId(int value);
    void setTitle(const std::string& value);
    void setYear(int value);
    void setAvailable(bool value);

    virtual std::string type() const = 0;
    virtual void printInfo() const = 0;
};

#endif