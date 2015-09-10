/*Дан массив целых чисел А[0..n-1]). Известно, что на интервале [0, m] значения массива строго возрастают, а на интервале [m, n-1] строго убывают. Найти m за O(log m). Задача решается с помощью бинарного поиска.*/
/*T(n) = O(logn)
 M(n) = O(1)*/

#include <iostream>

int BinarySearch(int *arr, int countBegin, int countEnd)
{
    int first = countBegin;
    int last = countEnd;
    
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

int main()
{
    int arrSize = 0;
    std::cin >> arrSize;
    int arr[arrSize];
    int power = 1;
    
    for (int i = 0; i < arrSize; i++) {
        std::cin >> arr[i];
    }
    
    while (arr[power / 2] < arr[power] && power <= arrSize) {
        power = power * 2;
    }
    if (power > arrSize) {
        std::cout << BinarySearch(arr, power / 2, arrSize);
    } else {
        std::cout << BinarySearch(arr, power / 2, power);
    }
    
    return 0;
}
