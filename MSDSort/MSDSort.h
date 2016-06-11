//
// Created by Саид on 10.06.16.
//

#ifndef MSDSORT_MSDSORT_H
#define MSDSORT_MSDSORT_H

#include <iostream>

class MSDSort {
public:
    static void sort(long long arr[], long long l, long long r, long long w);
private:
    constexpr static const int SIZEDIGIT = 64;
    static long long digit(long long element, long long w);
};

long long MSDSort::digit(long long element, long long w) {
    long long temp = element;
    for (long long i = 0; i < SIZEDIGIT - w; i++) {
        temp = temp >> 1;
    }

    return temp & 1;
}

void MSDSort::sort(long long arr[], long long l, long long r, long long w) {
    long long i = l, j = r;

    if (r <= l || w > SIZEDIGIT) {
        return;
    }
    while (j != i) {
        while (digit(arr[i], w) == 0 && (i < j)) i++;
        while (digit(arr[j], w) == 1 && (j > i)) j--;
        std::swap(arr[i], arr[j]);
    }
    if (digit(arr[r], w) == 0) {
        j++;
    }
    sort(arr, l, j -1, w + 1);
    sort(arr, j, r, w + 1);
}

#endif //MSDSORT_MSDSORT_H
