//
// Created by Саид on 10.06.16.
//

#ifndef QUICKSORT_QUICKSORT_H
#define QUICKSORT_QUICKSORT_H

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <cstdio>
#include <iostream>

template<class T>
class QuickSort {
public:
    static void sort(T *array, int start, int end);
private:
    constexpr static const int MINQUICKSORTSIZE = 50;
    static void insertionSort(T *arr, int start, int end);
    static int partition(T *array, int start, int end);
};

template<class T>
void QuickSort<T>::sort(T *array, int start, int end) {
    if (end - start + 1 <= MINQUICKSORTSIZE) {
        insertionSort(array, start, end);
        return;
    }
    int pivot = partition(array, start, end);
    sort(array, start, pivot - 1);
    sort(array, pivot + 1, end);
}

template<class T>
void QuickSort<T>::insertionSort(T *arr, int start, int end) {
    for (int i = start + 1; i <= end; ++i) {
        int tmp = arr[i];
        int j;

        for (j = i; j > start && tmp < arr[j - 1]; --j) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

template<class T>
int QuickSort<T>::partition(T *array, int start, int end) {
    if (start == end) {
        return start;
    }
    int part = (start + end) / 2;

    if (array[end] >= array[start]) {
        if (array[end] >= array[part]) {
            if (array[part] >= array[start]) {
                std::swap(array[end], array[part]);
            } else {
                std::swap(array[end], array[start]);
            }
        }
    } else if (array[end] < array[part]) {
        if (array[part] >= array[start]) {
            std::swap(array[end], array[start]);
        } else {
            std::swap(array[end], array[part]);
        }
    }
    int p = array[end];
    int i = start;
    int j = end - 1;

    while (i <= j) {
        while (array[i] < p) ++i;
        while (array[j] >= p && j >= 0) --j;
        if (i < j) {
            std::swap(array[i++], array[j--]);
        }
    }
    std::swap(array[i], array[end]);

    return i;
}


#endif //QUICKSORT_QUICKSORT_H
