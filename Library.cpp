#include "Library.h"
#include "Book.h"
#include "Magazine.h"
#include "Utils.h"
#include <iostream>
#include <fstream>

Library::Library() : nextItemId(1), nextLoanId(1) {}

Library::~Library() {
    for (auto* item : items) delete item;
}

bool Library::isItemIdUnique(int id) const {
    for (auto* item : items) {
        if (item->getId() == id) return false;
    }
    return true;
}

bool Library::isTicketUnique(int ticket) const {
    for (const auto& r : readers) {
        if (r.getTicket() == ticket) return false;
    }
    return true;
}

LibraryItem* Library::findItemPtr(int id) const {
    for (auto* item : items) {
        if (item->getId() == id) return item;
    }
    return nullptr;
}

void Library::addBook() {
    std::string title = readNonEmpty("Название: ");
    int year = readInt("Год (1500-2100): ", 1500, 2100);
    std::string author = readNonEmpty("Автор: ");
    std::string isbn = readNonEmpty("ISBN: ");
    addBookDirect(title, year, author, isbn);
    std::cout << "Книга добавлена.\n";
}

void Library::addBookDirect(const std::string& title, int year, const std::string& author, const std::string& isbn) {
    int id = nextItemId++;
    items.push_back(new Book(id, title, year, true, author, isbn));
}

void Library::addMagazine() {
    std::string title = readNonEmpty("Название: ");
    int year = readInt("Год (1500-2100): ", 1500, 2100);
    int issueNumber = readInt("Номер выпуска: ", 1, 1000000);
    int month = readInt("Месяц (1-12): ", 1, 12);
    addMagazineDirect(title, year, issueNumber, month);
    std::cout << "Журнал добавлен.\n";
}

void Library::addMagazineDirect(const std::string& title, int year, int issueNumber, int month) {
    int id = nextItemId++;
    items.push_back(new Magazine(id, title, year, true, issueNumber, month));
}

void Library::addReader() {
    int ticket = readInt("Номер билета: ", 1, 1000000);
    if (!isTicketUnique(ticket)) {
        std::cout << "Читатель с таким билетом уже существует.\n";
        return;
    }
    std::string fullName = readNonEmpty("ФИО: ");
    addReaderDirect(ticket, fullName);
    std::cout << "Читатель зарегистрирован.\n";
}

void Library::addReaderDirect(int ticket, const std::string& fullName) {
    readers.push_back(Reader(ticket, fullName));
}

void Library::findById() {
    int id = readInt("Введите id издания: ", 1, 1000000);
    LibraryItem* item = findItemPtr(id);
    if (!item) {
        std::cout << "Издание не найдено.\n";
        return;
    }
    item->printInfo();
}

void Library::issueItem() {
    int id = readInt("Введите id издания: ", 1, 1000000);
    LibraryItem* item = findItemPtr(id);
    if (!item) {
        std::cout << "Издание не найдено.\n";
        return;
    }
    if (!item->isAvailable()) {
        std::cout << "Издание уже выдано.\n";
        return;
    }
    int ticket = readInt("Введите билет читателя: ", 1, 1000000);
    bool readerExists = false;
    for (const auto& r : readers) {
        if (r.getTicket() == ticket) { readerExists = true; break; }
    }
    if (!readerExists) {
        std::cout << "Читатель не найден.\n";
        return;
    }
    item->setAvailable(false);
    loans.push_back(Loan(nextLoanId++, ticket, id, true));
    std::cout << "Издание выдано.\n";
}

void Library::returnItem() {
    int id = readInt("Введите id издания: ", 1, 1000000);
    LibraryItem* item = findItemPtr(id);
    if (!item) {
        std::cout << "Издание не найдено.\n";
        return;
    }
    bool found = false;
    for (auto& loan : loans) {
        if (loan.getItemId() == id && loan.isActive()) {
            loan.setActive(false);
            found = true;
            break;
        }
    }
    if (!found) {
        std::cout << "Активная выдача не найдена.\n";
        return;
    }
    item->setAvailable(true);
    std::cout << "Издание возвращено.\n";
}

void Library::printAvailable() const {
    bool any = false;
    for (auto* item : items) {
        if (item->isAvailable()) {
            item->printInfo();
            any = true;
        }
    }
    if (!any) std::cout << "Нет доступных изданий.\n";
}

void Library::printActiveLoans() const {
    bool any = false;
    for (const auto& loan : loans) {
        if (loan.isActive()) {
            loan.printInfo();
            any = true;
        }
    }
    if (!any) std::cout << "Нет активных выдач.\n";
}

void Library::saveAll() const {
    std::ofstream fitems("items.txt");
    for (auto* item : items) {
        if (item->type() == "Book") {
            Book* b = dynamic_cast<Book*>(item);
            fitems << "Book;" << b->getId() << ";" << b->getTitle() << ";"
                   << b->getYear() << ";" << b->isAvailable() << ";"
                   << b->getAuthor() << ";" << b->getIsbn() << "\n";
        } else if (item->type() == "Magazine") {
            Magazine* m = dynamic_cast<Magazine*>(item);
            fitems << "Magazine;" << m->getId() << ";" << m->getTitle() << ";"
                   << m->getYear() << ";" << m->isAvailable() << ";"
                   << m->getIssueNumber() << ";" << m->getMonth() << "\n";
        }
    }
    fitems.close();

    std::ofstream freaders("readers.txt");
    for (const auto& r : readers) {
        freaders << r.getTicket() << ";" << r.getFullName() << "\n";
    }
    freaders.close();

    std::ofstream floans("loans.txt");
    for (const auto& l : loans) {
        floans << l.getId() << ";" << l.getReaderTicket() << ";"
               << l.getItemId() << ";" << l.isActive() << "\n";
    }
    floans.close();

    std::cout << "Данные сохранены.\n";
}

void Library::loadAll() {
    std::ifstream fitems("items.txt");
    if (fitems.is_open()) {
        std::string line;
        while (std::getline(fitems, line)) {
            if (line.empty()) continue;
            auto parts = split(line, ';');
            if (parts.size() < 7) continue;
            std::string type = parts[0];
            int id = std::stoi(parts[1]);
            std::string title = parts[2];
            int year = std::stoi(parts[3]);
            bool available = std::stoi(parts[4]);
            if (type == "Book") {
                items.push_back(new Book(id, title, year, available, parts[5], parts[6]));
            } else if (type == "Magazine") {
                items.push_back(new Magazine(id, title, year, available,
                                             std::stoi(parts[5]), std::stoi(parts[6])));
            }
            if (id >= nextItemId) nextItemId = id + 1;
        }
        fitems.close();
    }

    std::ifstream freaders("readers.txt");
    if (freaders.is_open()) {
        std::string line;
        while (std::getline(freaders, line)) {
            if (line.empty()) continue;
            auto parts = split(line, ';');
            if (parts.size() < 2) continue;
            readers.push_back(Reader(std::stoi(parts[0]), parts[1]));
        }
        freaders.close();
    }

    std::ifstream floans("loans.txt");
    if (floans.is_open()) {
        std::string line;
        while (std::getline(floans, line)) {
            if (line.empty()) continue;
            auto parts = split(line, ';');
            if (parts.size() < 4) continue;
            int id = std::stoi(parts[0]);
            loans.push_back(Loan(id, std::stoi(parts[1]),
                                 std::stoi(parts[2]), std::stoi(parts[3])));
            if (id >= nextLoanId) nextLoanId = id + 1;
        }
        floans.close();
    }
}