#include <iostream>
#include <vector>

void swap(int* num1, int* num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

std::vector<int> sort(std::vector<int> array) {
    int index = 1;
    while (index < array.size()) {
        if(index == 0 || array[index - 1] <= array[index]) {
            index++;
            continue;
        }
        swap(&array[index - 1], &array[index]);
    }

    return array;
}