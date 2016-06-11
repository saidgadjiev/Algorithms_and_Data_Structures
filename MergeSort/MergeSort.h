//
// Created by Саид on 10.06.16.
//

#ifndef MERGESORT_MERGESORT_H
#define MERGESORT_MERGESORT_H

template <class T>
class MergeSort {
public:
    static void sort(T *arr, int p, int r);
private:
    static void merge(T *arr, int p, int q, int r);
};

template <class T>
void MergeSort<T>::sort(T *arr, int p, int r) {
    if (p < r) {
        int q = (r + p) / 2;

        sort(arr, p, q);
        sort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

template <class T>
void MergeSort<T>::merge(T *arr, int p, int q, int r) {
    int i = p, j = q + 1, k = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    T *temp = new T[n1 + n2];

    while (i <= q && j <= r) {
        if (arr[i] < arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= q) {
        temp[k++] = arr[i++];
    }
    while(j <= r) {
        temp[k++] = arr[j++];
    }
    for(int i = 0; i < n1 + n2; i++) {
        arr[p + i] = temp[i];
    }

    delete[] temp;
}

#endif //MERGESORT_MERGESORT_H
