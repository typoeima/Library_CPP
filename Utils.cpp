#include "Utils.h"
#include <iostream>
#include <limits>
#include <sstream>

int readInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return value;
            }
            std::cout << "Значение должно быть в диапазоне [" << min << ", " << max << "].\n";
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. Введите целое число.\n";
        }
    }
}

std::string readNonEmpty(const std::string& prompt) {
    std::string value;
    while (true) {
        if (!prompt.empty()) std::cout << prompt;
        std::getline(std::cin, value);
        if (!value.empty()) return value;
        std::cout << "Строка не может быть пустой.\n";
    }
}

std::vector<std::string> split(const std::string& line, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string token;
    while (std::getline(ss, token, delimiter)) {
        result.push_back(token);
    }
    return result;
}