#include <iostream>
#include "MSDSort.h"

int main() {
    long long arr[] = {12312342, 12541413, 65524252};

    MSDSort::sort(arr, 0, 3, 1);

    for (int i = 0; i < 3; ++i) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}

