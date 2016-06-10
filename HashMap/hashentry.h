//
// Created by Саид on 07.06.16.
//

#ifndef HASHMAP_ENTRY_H
#define HASHMAP_ENTRY_H

enum CellStatus {
    EMPTY,
    BUSY,
    DELETED
};

template <class K, class V>
class HashEntry {
public:
    HashEntry() :
        key_(0),
        status_(EMPTY)
    {}
    HashEntry(K key, V value) :
        key_(key),
        value_(value),
        status_(BUSY)
    {}

    void setValue(V value) {
        value_ = value;
    }

    void setKey(K key) {
        key_ = key;
    }

    V getValue() {
        return value_;
    }

    K getKey() {
        return key_;
    }

    void setStatus(CellStatus status) {
        status_ = status;
    }

    int getStatus() {
        return status_;
    }
private:
    K key_;
    V value_;
    CellStatus status_;
};


#endif //HASHMAP_ENTRY_H
