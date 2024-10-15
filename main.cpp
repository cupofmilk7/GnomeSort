#include <iostream>
#include <vector>

#include "sort.h"

int main() {

    std::vector<int> v = {1, 5, 3, 4, 6, 7, 18, 2, 10};

    v = sort(v);
    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    return 0;
}
