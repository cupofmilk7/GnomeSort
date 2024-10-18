#include <iostream>
#include <vector>

#include "checkData.h"

// Функция swap(int* num1, int* num2)
// меняет два числа друг с другом
void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

// Функция sort(std::vector<int>& array) для сортировки
// есть возможность выбора типа сортировки
void sort(std::vector<int>& array) {
    std::cout << "1. Ascending, 2. Descending" << std::endl;
    int choice = checkInt();
    while (choice < 1 || choice > 2) {
        std::cout << "Choose an option from 1 to 2" << std::endl;
        choice = checkInt();
    }
    if (choice == 1) {
        int index = 1;
        while (index < array.size()) {
            if(index == 0 || array[index - 1] <= array[index]) {
                index++;
                continue;
            }
            swap(&array[index - 1], &array[index]);
            index--;
        }
    }
    else {
        int index = 1;
        while (index < array.size()) {
            if(index == 0 || array[index - 1] >= array[index]) {
                index++;
                continue;
            }
            swap(&array[index - 1], &array[index]);
            index--;
        }
    }
}