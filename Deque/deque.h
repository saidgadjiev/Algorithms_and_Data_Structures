//
// Created by Саид on 10.06.16.
//

#ifndef DEQUEUE_DEQUEUE_H
#define DEQUEUE_DEQUEUE_H

#include <iostream>
#include <cassert>

template <class T>
class Deque {
public:
    Deque();
    ~Deque();
    void pushFront(T elem);
    void pushBack(T elem);
    T popFront();
    T popBack();
    bool isEmpty();
private:
    T* buffer;
    int last;
    int first;
    int realSize;
    int bufferSize;
    void grow();
};

template <class T>
Deque<T>::Deque():
        buffer(0),
        last(0),
        first(0),
        realSize(0),
        bufferSize(0)
{ }

template <class T>
Deque<T>::~Deque() {
    delete[] buffer;
}

template <class T>
bool Deque<T>::isEmpty() {
    return realSize == 0;
}

template <class T>
void Deque<T>::grow() {
    int newBufferSize = std::max(bufferSize * 2, 1);
    T *newBuffer = new T[newBufferSize];

    if (!isEmpty()) {
        std::memcpy(newBuffer, buffer + first, (realSize - first) * sizeof(T));
        std::memcpy(newBuffer + realSize - first, buffer, first * sizeof(T));
        last = realSize;
        first = 0;
    }
    delete[] buffer;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

template <class T>
void Deque<T>::pushFront(T elem) {
    if (realSize == bufferSize) {
        grow();
    }
    if (first > 0) {
        buffer[--first] = elem;
    } else {
        first = bufferSize - 1;
        buffer[first] = elem;
    }
    realSize++;
}

template <class T>
T Deque<T>::popFront() {
    assert(!isEmpty());
    T result = buffer[first++];

    if (first == bufferSize) {
        first = 0;
    }
    realSize--;

    return result;
}

template <class T>
void Deque<T>::pushBack(T elem) {
    if (realSize == bufferSize) {
        grow();
    }
    if (last == bufferSize) {
        last = 0;
    }
    buffer[last++] = elem;
    realSize++;
}

template <class T>
T Deque<T>::popBack() {
    assert(!isEmpty());
    if (last == 0) {
        last = bufferSize;
    }
    T result = buffer[--last];

    realSize--;

    return result;
}

#endif //DEQUEUE_DEQUEUE_H
