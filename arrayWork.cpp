#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "checkData.h"
#include "sort.h"
#include "arrayWork.h"

#include "fileFunctions.h"

std::vector<int> randomArray();
std::vector<int> enterArray();

// Функция menu() для вывда в консоль пунктов меню, а также выполнения этих пунктов
void menu() {
    std::vector<int> vectorNums;
    int choice = 0;

    do {
        std::cout << std::endl << "1. Sort the array" << std::endl
                << "2. Create a new array (random values)" << std::endl
                << "3. Delete an array" << std::endl
                << "4. Save an array in file" << std::endl
                << "5. Enter an array" << std::endl
                << "0. Exit" << std::endl;
        choice = checkInt();
        while (choice < 0 || choice > 5) {
            std::cout << "Enter choice (0-5): ";
            choice = checkInt();
        }
        switch (choice) {
            case 1:
                if (vectorNums.empty()) {
                    std::cout << "Empty array" << std::endl;
                    break;
                }
                sort(vectorNums);
                std::cout << "Sorted array:" << std::endl;
                for (int i = 0; i < vectorNums.size(); ++i) {
                    std::cout << vectorNums[i] << " ";
                }
                std::cout << std::endl;
                break;
            case 2:
                if(!vectorNums.empty()) {
                    std::cout << "Array is not empty, overwrite it?" << std::endl
                        << "1. Yes, 2. No" << std::endl;
                    int choiceOverwrite = checkInt();
                    while(choiceOverwrite < 1 || choiceOverwrite > 2) {
                        choiceOverwrite = checkInt();
                    }
                    if(choiceOverwrite == 2) {
                        break;
                    }
                    vectorNums.clear();
                }
                vectorNums = randomArray();
                std::cout << "Array: ";
                for (int i = 0; i < vectorNums.size(); ++i) {
                    std::cout << vectorNums[i] << " ";
                }
                std::cout << std::endl;
                break;
            case 3:
                if (vectorNums.empty()) {
                    std::cout << "Nothing to delete" << std::endl;
                    break;
                }
                vectorNums.clear();
                std::cout << "Array is deleted: ";
                break;
            case 4:
                addToFile(vectorNums);
                break;
            case 5:
                vectorNums = enterArray();
                std::cout << "Array: ";
                for (int i = 0; i < vectorNums.size(); ++i) {
                    std::cout << vectorNums[i] << " ";
                }
                break;
            case 0:
                break;
        }
    } while (choice != 0);
}

// Функция randomArray() заполняет массив случайными значениями,
// также запрашивает размер массива,
// возвращает этот массив

std::vector<int> randomArray() {
    std::cout << std::endl;
    std::srand(static_cast<unsigned int>(std::time(0)));

    std::cout << "Enter an array size: " << std::endl;
    int size = checkInt();
    while (size < 0) {
        size = checkInt();
    }

    std::vector<int> tempVector(size);

    for (int i = 0; i < size; ++i) {
        tempVector[i] = std::rand() % 100;
    }
    return tempVector;
}

// Функция enterArray() для ввода значений массива с клавиатуры

std::vector<int> enterArray() {
    std::cout << "Enter an array size: " << std::endl;
    int size = checkInt();
    while (size < 0) {
        size = checkInt();
    }
    std::vector<int> tempVector(size);
    for(int i = 0; i < size; ++i) {
        tempVector[i] = checkInt();
    }
    return tempVector;
}