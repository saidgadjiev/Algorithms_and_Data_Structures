#include <iostream>
#include "HeapSort.h"

int main () {
    int arr[] = {4, 0, 5, 2, 6};

    HeapSort<int>::sort(arr, 4);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << std::endl;
    }
    return 0;
}
