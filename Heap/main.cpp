#include <iostream>
#include "heap.h"

int main() {
    Heap<int> heap;

    for (int i = 0; i < 100; ++i) {
        heap.add(i);
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << heap.extractMax() << std::endl;
    }

    return 0;
}
