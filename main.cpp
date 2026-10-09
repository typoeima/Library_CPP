#include <iostream>
#include <limits>
#include "Library.h"
#include "Utils.h"

int main() {
    Library library;
    library.loadAll();

    int choice = -1;
    while (choice != 0) {
        std::cout << "\n===== Библиотека колледжа =====\n";
        std::cout << "1 - добавить книгу\n";
        std::cout << "2 - добавить журнал\n";
        std::cout << "3 - зарегистрировать читателя\n";
        std::cout << "4 - найти издание по id\n";
        std::cout << "5 - выдать издание\n";
        std::cout << "6 - вернуть издание\n";
        std::cout << "7 - вывести доступные издания\n";
        std::cout << "8 - вывести активные выдачи\n";
        std::cout << "9 - сохранить\n";
        std::cout << "0 - выход\n";
        std::cout << "Выбор: ";

        choice = readInt("", 0, 9);

        switch (choice) {
            case 1: library.addBook(); break;
            case 2: library.addMagazine(); break;
            case 3: library.addReader(); break;
            case 4: library.findById(); break;
            case 5: library.issueItem(); break;
            case 6: library.returnItem(); break;
            case 7: library.printAvailable(); break;
            case 8: library.printActiveLoans(); break;
            case 9: library.saveAll(); break;
            case 0: std::cout << "Выход.\n"; break;
            default: std::cout << "Неизвестная команда\n"; break;
        }
    }
    return 0;
}