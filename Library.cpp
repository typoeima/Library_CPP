#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

Library::Library() : nextLoanId(1) {
    load();
}

Library::~Library() {
    for (auto* item : items) delete item;
}

bool Library::idExists(int id) const {
    for (auto* item : items) if (item->getId() == id) return true;
    return false;
}

bool Library::ticketExists(int ticket) const {
    for (const auto& r : readers) if (r.getTicket() == ticket) return true;
    return false;
}

void Library::addBook() {
    int id = readInt("id: ", 1, 1000000);
    if (idExists(id)) { std::cout << "id уже существует\n"; return; }
    std::string title = readNonEmpty("title: ");
    int year = readInt("year: ", 1500, 2100);
    std::string author = readNonEmpty("author: ");
    std::string isbn = readNonEmpty("isbn: ");
    items.push_back(new Book(id, title, year, true, author, isbn));
    std::cout << "Книга добавлена\n";
}

void Library::addMagazine() {
    int id = readInt("id: ", 1, 1000000);
    if (idExists(id)) { std::cout << "id уже существует\n"; return; }
    std::string title = readNonEmpty("title: ");
    int year = readInt("year: ", 1500, 2100);
    int issue = readInt("issueNumber: ", 1, 100000);
    int month = readInt("month: ", 1, 12);
    items.push_back(new Magazine(id, title, year, true, issue, month));
    std::cout << "Журнал добавлен\n";
}

void Library::registerReader() {
    int ticket = readInt("ticket: ", 1, 1000000);
    if (ticketExists(ticket)) { std::cout << "ticket уже существует\n"; return; }
    std::string name = readNonEmpty("fullName: ");
    readers.push_back(Reader(ticket, name));
    std::cout << "Читатель зарегистрирован\n";
}

void Library::findItemById() {
    int id = readInt("id: ", 1, 1000000);
    for (auto* item : items) {
        if (item->getId() == id) {
            item->printInfo();
            std::cout << "\n";
            return;
        }
    }
    std::cout << "Издание не найдено\n";
}

void Library::issueItem() {
    int ticket = readInt("readerTicket: ", 1, 1000000);
    if (!ticketExists(ticket)) { std::cout << "Читатель не найден\n"; return; }
    int itemId = readInt("itemId: ", 1, 1000000);
    LibraryItem* found = nullptr;
    for (auto* item : items) if (item->getId() == itemId) { found = item; break; }
    if (!found) { std::cout << "Издание не найдено\n"; return; }
    if (!found->isAvailable()) { std::cout << "Издание занято\n"; return; }
    found->setAvailable(false);
    loans.push_back(Loan(nextLoanId++, ticket, itemId, true));
    std::cout << "Издание выдано\n";
}

void Library::returnItem() {
    int itemId = readInt("itemId: ", 1, 1000000);
    for (auto& loan : loans) {
        if (loan.getItemId() == itemId && loan.isActive()) {
            loan.setActive(false);
            for (auto* item : items) {
                if (item->getId() == itemId) item->setAvailable(true);
            }
            std::cout << "Издание возвращено\n";
            return;
        }
    }
    std::cout << "Активная выдача не найдена\n";
}

void Library::printAvailable() {
    bool any = false;
    for (auto* item : items) {
        if (item->isAvailable()) {
            item->printInfo();
            std::cout << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "Нет доступных изданий\n";
}

void Library::printActiveLoans() {
    bool any = false;
    for (const auto& loan : loans) {
        if (loan.isActive()) {
            std::cout << "id=" << loan.getId()
                      << " readerTicket=" << loan.getReaderTicket()
                      << " itemId=" << loan.getItemId() << "\n";
            any = true;
        }
    }
    if (!any) std::cout << "Нет активных выдач\n";
}

void Library::save() {
    std::ofstream fi("items.txt");
    for (auto* item : items) {
        fi << item->type() << ";" << item->getId() << ";" << item->getTitle()
           << ";" << item->getYear() << ";" << (item->isAvailable() ? 1 : 0)
           << ";" << item->specific1() << ";" << item->specific2() << "\n";
    }
    fi.close();

    std::ofstream fr("readers.txt");
    for (const auto& r : readers) {
        fr << r.getTicket() << ";" << r.getFullName() << "\n";
    }
    fr.close();

    std::ofstream fl("loans.txt");
    for (const auto& l : loans) {
        fl << l.getId() << ";" << l.getReaderTicket() << ";"
           << l.getItemId() << ";" << (l.isActive() ? 1 : 0) << "\n";
    }
    fl.close();

    std::cout << "Сохранено\n";
}

void Library::load() {
    std::ifstream fi("items.txt");
    std::string line;
    while (std::getline(fi, line)) {
        if (line.empty()) continue;
        auto p = split(line, ';');
        if (p.size() < 7) continue;
        int id = std::stoi(p[1]);
        int year = std::stoi(p[3]);
        bool avail = p[4] == "1";
        if (p[0] == "Book") {
            items.push_back(new Book(id, p[2], year, avail, p[5], p[6]));
        } else if (p[0] == "Magazine") {
            items.push_back(new Magazine(id, p[2], year, avail,
                                         std::stoi(p[5]), std::stoi(p[6])));
        }
    }
    fi.close();

    std::ifstream fr("readers.txt");
    while (std::getline(fr, line)) {
        if (line.empty()) continue;
        auto p = split(line, ';');
        if (p.size() < 2) continue;
        readers.push_back(Reader(std::stoi(p[0]), p[1]));
    }
    fr.close();

    std::ifstream fl("loans.txt");
    while (std::getline(fl, line)) {
        if (line.empty()) continue;
        auto p = split(line, ';');
        if (p.size() < 4) continue;
        int id = std::stoi(p[0]);
        loans.push_back(Loan(id, std::stoi(p[1]), std::stoi(p[2]), p[3] == "1"));
        if (id >= nextLoanId) nextLoanId = id + 1;
    }
    fl.close();
}