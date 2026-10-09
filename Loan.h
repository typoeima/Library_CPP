#ifndef LOAN_H
#define LOAN_H

class Loan {
private:
    int id;
    int readerTicket;
    int itemId;
    bool active;

public:
    Loan();
    Loan(int id, int readerTicket, int itemId, bool active);

    int getId() const;
    int getReaderTicket() const;
    int getItemId() const;
    bool isActive() const;

    void setId(int value);
    void setReaderTicket(int value);
    void setItemId(int value);
    void setActive(bool value);

    void printInfo() const;
};

#endif