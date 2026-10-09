#include "Loan.h"

Loan::Loan(int id, int readerTicket, int itemId, bool active)
    : id(id), readerTicket(readerTicket), itemId(itemId), active(active) {}

int Loan::getId() const { return id; }
int Loan::getReaderTicket() const { return readerTicket; }
int Loan::getItemId() const { return itemId; }
bool Loan::isActive() const { return active; }
void Loan::setActive(bool value) { active = value; }