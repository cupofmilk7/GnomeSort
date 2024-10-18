#include <iostream>

// Функция checkInt() для проверки ввода целого числа
int checkInt() {
    int forCheck;

    while(true) {
        std::cout << "Please enter an integer: ";
        std::cin >> forCheck;
        if(std::cin.good()) {
            std::cin.ignore(std::numeric_limits<int>::max(), '\n');
            break;
        }
        std::cin.clear();
       std:: cin.ignore(std::numeric_limits<int>::max(), '\n');
    }

    return forCheck;
}