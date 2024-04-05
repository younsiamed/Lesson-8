#include <iostream>
#include <string>
#include <windows.h>
#include <stdexcept>

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "Вы ввели слово запретной длины!";
    }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length)
        throw bad_length();
    return str.length();
}

int main() {
    SetConsoleOutputCP(65001);
    int forbidden_length;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    std::string input;
    try {
        while (true) {
            std::cout << "Введите слово: ";
            std::cin >> input;
            int length = function(input, forbidden_length);
            std::cout << "Длина слова \"" << input << "\" равна " << length << std::endl;
        }
    }
    catch (const bad_length& e) {
        std::cerr << e.what() << " До свидания" << std::endl;
    }

    return 0;
}