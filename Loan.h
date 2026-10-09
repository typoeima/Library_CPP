#pragma once

class Loan {
private:
    int id;
    int readerTicket;
    int itemId;
    bool active;
public:
    Loan(int id, int readerTicket, int itemId, bool active);
    int getId() const;
    int getReaderTicket() const;
    int getItemId() const;
    bool isActive() const;
    void setActive(bool value);
};