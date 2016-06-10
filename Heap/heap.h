//
// Created by Саид on 10.06.16.
//

#ifndef HEAP_HEAP_H
#define HEAP_HEAP_H

#include <iostream>

template <class T>
class Heap {
public:
    Heap();
    ~Heap();
    T extractMax();
    void add(T value);
    bool isEmpty();
private:
    T *buffer;
    int realSize;
    int bufferSize;
    void siftDown(int i);
    void siftUp(int i);
    void grow();
};

template <class T>
Heap<T>::Heap():
    buffer(nullptr),
    realSize(0),
    bufferSize(0)
{ }

template <class T>
Heap<T>::~Heap() {
    delete[] buffer;
}

template <class T>
bool Heap<T>::isEmpty() {
    return realSize == 0;
}

template <class T>
void Heap<T>::add(T value) {
    if (realSize == bufferSize) {
        grow();
    }
    ++realSize;
    buffer[realSize - 1] = value;
    siftUp(realSize - 1);
}

template <class T>
void Heap<T>::siftDown(int i) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;

    if (left < realSize && buffer[left] > buffer[i]) {
        largest = left;
    }
    if (right < realSize && buffer[right] > buffer[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(buffer[i], buffer[largest]);
        siftDown(largest);
    }
}

template <class T>
void Heap<T>::siftUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;

        if(buffer[i] <= buffer[parent]) {
            return;
        }
        std::swap(buffer[i], buffer[parent]);
        i = parent;
    }
}

template <class T>
void Heap<T>::grow() {
    int newBufferSize = std::max(bufferSize * 2, 1);
    T *newBuffer = new T[newBufferSize] {0};

    if (!isEmpty()) {
        std::memcpy(newBuffer, buffer, realSize * sizeof(T));
    }
    delete[] buffer;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

template <class T>
T Heap<T>::extractMax() {
    T result = buffer[0];

    buffer[0] = buffer[realSize - 1];
    --realSize;
    if (realSize > 0) {
        siftDown(0);
    }

    return result;
}

#endif //HEAP_HEAP_H
