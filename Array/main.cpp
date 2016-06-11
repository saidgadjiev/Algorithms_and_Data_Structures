#include <iostream>
#include <assert.h>
#include "Array.h"

int main() {
    Array<int> arr;

    for (int j = 0; j < 5; ++j) {
        arr.add(j);
    }
    arr.bubbleSort();
    for (int i = 0; i < arr.getSize(); i++) {
        std::cout << arr.getAt(i) << std::endl;
    }

    return 0;
}