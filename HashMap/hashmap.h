//
// Created by Саид on 07.06.16.
//

#ifndef HASHMAP_HASHMAP_H
#define HASHMAP_HASHMAP_H

#include "hashentry.h"
#include <iostream>

template <class K, class V>
class HashMap {
public:
    HashMap();
    ~HashMap();
    void clear();
    bool containsKey(K key);
    bool containsValue(V value);
    HashEntry<K, V> *get(K key);
    bool isEmpty();
    void put(K key, V value);
    bool remove(K key);
    bool remove(K key, V value);
    int size();
private:
    constexpr static const float DEFAULT_LOAD_FACTOR = 0.75f;
    constexpr static const int DEFAULT_TABLE_SIZE = 8;
    float loadFactor;
    int threshold_;
    int tableSize_;
    int size_;
    HashEntry<K, V> **table_;
    void grow();
};


template <class K, class V>
HashMap<K, V>::HashMap():
    loadFactor(DEFAULT_LOAD_FACTOR),
    threshold_(DEFAULT_LOAD_FACTOR * DEFAULT_TABLE_SIZE),
    tableSize_(DEFAULT_TABLE_SIZE),
    size_(0)
{
    table_ = new HashEntry<K, V> *[tableSize_] {0};
    for (int i = 0; i < tableSize_; ++i) {
        table_[i] = new HashEntry<K,V>();
    }
}

template <class K, class V>
HashMap<K, V>::~HashMap() {
    size_ = 0;
    for (int i = 0; i < threshold_; ++i) {
        delete table_[i];
    }
    delete[] table_;
}

template <class K, class V>
void HashMap<K, V>::clear() {
    size_ = 0;
    for (int i = 0; i < threshold_; ++i) {
        delete table_[i];
        table_[i] = nullptr;
    }
}

template <class K, class V>
HashEntry<K, V> *HashMap<K, V>::get(K key) {
    int hash1 = key.hashOne(tableSize_);
    int hash2 = key.hashTwo(tableSize_);

    for (int i = 0 ; i < tableSize_; i++) {
        int hash = (hash1 + i * hash2) % tableSize_;

        if (table_[hash]->getStatus() == EMPTY) {
            return nullptr;
        }
        if (table_[hash]->getKey() == key) {
            return table_[hash];
        }
    }

    return nullptr;
}

template <class K, class V>
void HashMap<K, V>::grow() {
    int oldTableSize = tableSize_;

    tableSize_ *= 2;
    threshold_ = (int) (tableSize_ * loadFactor);
    HashEntry<K,V> **oldTable = table_;

    table_ = new HashEntry<K, V>*[tableSize_];

    for (int i = 0; i < tableSize_; i++) {
        table_[i] = new HashEntry<K, V>();
    }
    size_ = 0;
    for (int i = 0; i < oldTableSize; ++i) {
        if (oldTable[i]->getStatus() == BUSY) {
            put(oldTable[i]->getKey(), oldTable[i]->getValue());

            delete oldTable[i];
        }
    }

    delete [] oldTable;
}

template <class K, class V>
bool HashMap<K, V>::remove(K key, V value) {
    int hash1 = key.hashOne(tableSize_);
    int hash2 = key.hashTwo(tableSize_);

    for (int i = 0 ; i < tableSize_; ++i) {
        int hash = (hash1 + i * hash2) % tableSize_;

        if (table_[hash]->getStatus() == EMPTY || table_[hash]->getStatus() == DELETED) {
            return false;
        }
        if (table_[hash]->getValue() == value && table_[hash]->getKey() == key) {
            table_[hash]->setStatus(DELETED);

            return true;
        }
    }
}

template <class K, class V>
bool HashMap<K, V>::remove(K key) {
    int hash1 = key.hashOne(tableSize_);
    int hash2 = key.hashTwo(tableSize_);

    for (int i = 0 ; i < tableSize_; ++i) {
        int hash = (hash1 + i * hash2) % tableSize_;

        if (table_[hash]->getStatus() == EMPTY || table_[hash]->getStatus() == DELETED) {
            return false;
        }
        if (table_[hash]->getKey() == key) {
            table_[hash]->setStatus(DELETED);

            return true;
        }
    }
}

template <class K, class V>
bool HashMap<K, V>::containsValue(V value) {
    for (int i = 0 ; i < tableSize_; ++i) {
        if (table_[i]->getValue() == value) {
            return true;
        }
    }

    return false;
}

template <class K, class V>
bool HashMap<K, V>::containsKey(K key) {
    int hash1 = key.hashOne(tableSize_);
    int hash2 = key.hashTwo(tableSize_);

    for (int i = 0 ; i < tableSize_; ++i) {
        int hash = (hash1 + i * hash2) % tableSize_;

        if (table_[hash]->getStatus() == EMPTY || table_[hash]->getStatus() == DELETED) {
            return false;
        }
        if (table_[hash]->getKey() == key) {
            return true;
        }
    }

    return false;
}

template <class K, class V>
int HashMap<K, V>::size() {
    return size_;
}

template <class K, class V>
bool HashMap<K, V>::isEmpty() {
    return size_ == 0;
}

template <class K, class V>
void HashMap<K, V>::put(K key, V value) {
    if (size_ >= threshold_) {
        grow();
    }
    int hash1 = key.hashOne(tableSize_);
    int hash2 = key.hashTwo(tableSize_ - 1);

    for (int i = 0; i < tableSize_; ++i) {
        int hash = (hash1 +  i * hash2) % tableSize_;

        if (table_[hash]->getStatus() == EMPTY || table_[hash]->getStatus() == DELETED) {
            table_[hash]->setValue(value);
            table_[hash]->setKey(key);
            table_[hash]->setStatus(BUSY);
            ++size_;
        }
        if (table_[hash]->getValue() == value) {
            return;
        }
    }
}

#endif //HASHMAP_HASHMAP_H
