#include <iostream>
#include "QuickSort.h"

using namespace std;

int main() {
    int arr[] = {2, 0, 1, 4, 3};

    QuickSort<int>::sort(arr, 0, 4);

    for (int i = 0; i < 5; ++i) {
        std::cout << arr[i] << std::endl;
    }

    return 0;
}