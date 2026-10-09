#include <iostream>
#include "Library.h"
#include "Utils.h"

int main() {
    Library library;
    while (true) {
        std::cout << "\n1 - добавить книгу\n"
                  << "2 - добавить журнал\n"
                  << "3 - зарегистрировать читателя\n"
                  << "4 - найти издание по id\n"
                  << "5 - выдать издание\n"
                  << "6 - вернуть издание\n"
                  << "7 - вывести доступные издания\n"
                  << "8 - вывести активные выдачи\n"
                  << "9 - сохранить\n"
                  << "0 - выход\n";
        int cmd = readInt("Команда: ", 0, 9);
        switch (cmd) {
            case 1: library.addBook(); break;
            case 2: library.addMagazine(); break;
            case 3: library.registerReader(); break;
            case 4: library.findItemById(); break;
            case 5: library.issueItem(); break;
            case 6: library.returnItem(); break;
            case 7: library.printAvailable(); break;
            case 8: library.printActiveLoans(); break;
            case 9: library.save(); break;
            case 0: return 0;
            default: std::cout << "Неизвестная команда\n"; break;
        }
    }
}