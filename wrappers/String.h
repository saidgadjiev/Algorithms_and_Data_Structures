//
// Created by Саид on 08.06.16.
//

#ifndef HASHMAP_STRING_H
#define HASHMAP_STRING_H

#include <iostream>
#include <cstring>

class String {
public:
    String(std::string value):
        hash_(0),
        value_(value)
    { }

    int hashOne(int m) {
        int result = 0;

        for (int i = 0; i < value_.length(); ++i) {
            result = (result * STRING_HASH_PARAM + value_[i]);
        }

        return result % m;
    }
    int hashTwo(int m) {
        int result = 0;

        for (int i = 0; i < value_.length(); ++i) {
            result = (result * STRING_HASH_PARAM + value_[i]);
        }
        result = result % m;

        if (result % 2 == 1) {
            return result + 1;
        }

        return result;
    }
private:
    constexpr static const int STRING_HASH_PARAM = 37;
    int hash_;
    std::string value_;
};

#endif //HASHMAP_STRING_H
