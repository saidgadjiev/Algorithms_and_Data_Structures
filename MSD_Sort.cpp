/*Дан массив неотрицательных целых 64-разрядных чисел. Количество чисел не больше 106. Отсортировать массив методом MSD по битам (бинарный QuickSort).*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdio>
#include <iostream>
#define MINQUICKSORTSIZE 50
#define READSIZE 10
#define UINTSIZE 4

void insertion_sort(unsigned int* arr, unsigned int start, unsigned int end) {
    for (unsigned int i = start + 1; i <= end; ++i) {
        unsigned int tmp = arr[i];
        unsigned int j;
        for (j = i; j > start && tmp < arr[j - 1]; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

unsigned int partition(unsigned int* array, unsigned int start, unsigned int end) {
    if (start == end)
        return start;

    unsigned int part = (start + end) / 2;
    if (array[end] >= array[start]) {
        if (array[end] >= array[part]) {
            if (array[part] >= array[start])
                std::swap(array[end], array[part]);
            else
                std::swap(array[end], array[start]);
        }
    } else if (array[end] < array[part]) {
        if (array[part] >= array[start])
            std::swap(array[end], array[start]);
        else
            std::swap(array[end], array[part]);
    }

    unsigned int p = array[end];
    unsigned int i = start;
    unsigned int j = end - 1;
    while (i <= j) {
        for ( ; array[i] < p; ++i) {}
        for ( ; j >= 0 && array[j] >= p; --j) {}
        if (i < j)
            std::swap(array[i++], array[j--]);
    }
    std::swap(array[i], array[end]);
    return i;
}

void quicksort (unsigned int* array, unsigned int start, unsigned int end) {
    if (end - start + 1 <= MINQUICKSORTSIZE) {
        insertion_sort(array, start, end);
        return;
    }
    unsigned int pivot = partition (array, start, end);
    quicksort (array, start, pivot - 1);
    quicksort (array, pivot + 1, end);
}

int main()
{
    unsigned int k = 0, numRead = 1;
    unsigned int* array = (unsigned int*) malloc(READSIZE * UINTSIZE);
    while (scanf("%u %u %u %u %u %u %u %u %u %u ", array + k, array + k + 1, array + k + 2, array + k + 3, array + k + 4, array + k + 5, array + k + 6, array + k + 7, array + k + 8, array + k + 9) == READSIZE) {
        k += READSIZE;
        ++numRead;
        array = (unsigned int*) realloc(array, READSIZE * UINTSIZE * numRead);
    }
    quicksort(array, 0, k - 1);
    k = 0;
    --numRead;
    while (numRead > 0) {
        printf("%u ", array[k+9]);
        k += READSIZE;
        --numRead;
    }
    return 0;
}


