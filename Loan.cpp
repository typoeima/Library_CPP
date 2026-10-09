#include "Loan.h"
#include <iostream>

Loan::Loan() : id(0), readerTicket(0), itemId(0), active(true) {}

Loan::Loan(int id, int readerTicket, int itemId, bool active)
    : id(id), readerTicket(readerTicket), itemId(itemId), active(active) {}

int Loan::getId() const { return id; }
int Loan::getReaderTicket() const { return readerTicket; }
int Loan::getItemId() const { return itemId; }
bool Loan::isActive() const { return active; }

void Loan::setId(int value) { id = value; }
void Loan::setReaderTicket(int value) { readerTicket = value; }
void Loan::setItemId(int value) { itemId = value; }
void Loan::setActive(bool value) { active = value; }

void Loan::printInfo() const {
    std::cout << "Выдача id=" << id
              << " | ticket: " << readerTicket
              << " | itemId: " << itemId
              << " | активна: " << (active ? "да" : "нет") << "\n";
}