#include <iostream>

int binarySearch(int *arr, int size) {
    int first = 0;
    int last = size;
    
    while(first < last) {
        int mid = (first + last) / 2;

        if(arr[mid - 1] > arr[mid]) {
            last = mid;
        } else {
            first = mid + 1;
        }
    }
    
    return first - 1;
}

int main() {
    int arr[] = {1, 3, 4, 5, 6};

    std::cout << binarySearch(arr, 5);

    return 0;
}
