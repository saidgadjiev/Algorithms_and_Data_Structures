#include <iostream>
#include "MergeSort.h"

int main() {
    int arr[] = {0, 4, 3, 1, 4};

    MergeSort<int>::sort(arr, 0, 4);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i];
    }

    return 0;
}
