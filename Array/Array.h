//
// Created by Саид on 10.06.16.
//

#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H

#include <cassert>
#include <iostream>

template <class T>
class Array {
public:
    Array();
    ~Array();
    T getAt(int index) const;
    int getSize() const;
    T operator[](int index) const;
    T &operator[](int index);
    void add(T element);
    void bubbleSort();
private:
    T *buffer_;
    int bufferSize_;
    int realSize_;
    void grow();
};

template <class T>
Array<T>::Array():
    buffer_(nullptr),
    bufferSize_(0),
    realSize_(0)
{}

template <class T>
Array<T>::~Array() {
    delete[] buffer_;
}

template <class T>
T Array<T>::getAt(int index) const {
    assert(index >= 0 && index < realSize_ && buffer_ != 0);
    return buffer_[index];
}

template <class T>
void Array<T>::grow() {
    int newBufferSize = std::max(bufferSize_ * 2, 1);
    T *newBuffer = new T[newBufferSize];

    for(int i = 0; i < realSize_; ++i) {
        newBuffer[i] = buffer_[i];
    }
    delete[] buffer_;
    buffer_ = newBuffer;
    bufferSize_ = newBufferSize;
}

template <class T>
void Array<T>::add(T element) {
    if(realSize_ == bufferSize_) {
        grow();
    }
    assert(realSize_ < bufferSize_ && buffer_ != 0);
    buffer_[realSize_++] = element;
}

template <class T>
void Array<T>::bubbleSort() {
    for (int i = getSize() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (buffer_[j] > buffer_[j+1]) {
                std::swap(buffer_[j], buffer_[j+1]);
            }
        }
    }
}

template <class T>
int Array<T>::getSize() const {
    return realSize_;
}

template <class T>
T Array<T>::operator[](int index) const {
    return getAt(index);
}

template <class T>
T &Array<T>::operator[](int index) {
    return buffer_[index];
}

#endif //ARRAY_ARRAY_H
