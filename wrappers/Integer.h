//
// Created by Саид on 07.06.16.
//

#ifndef INTEGER_INTEGER_H
#define INTEGER_INTEGER_H

#include <iostream>

class Integer {
public:
    Integer(int value) {
        value_ = value;
    }
    int hashOne(int m) {
        return value_ % m;
    }

    int hashTwo(int m) {
        int result = value_ % m;

        if (result % 2 == 1) {
            return result + 1;
        }

        return result;
    }

    friend Integer operator + (Integer obj1, Integer obj2)  {
        Integer newObj = 0;

        newObj.value_ = obj1.value_ + obj2.value_;

        return newObj;
    }
    friend void operator += (Integer &obj1, Integer obj2) {
        obj1.value_ += obj2.value_;

    }
    bool operator == (Integer obj2) {
        return value_ == obj2.value_;

    }
    friend std::ostream &operator << (std::ostream &os, Integer &obj) {
        os << obj.value_;

        return os;
    }
private:
    int value_;
};


#endif //INTEGER_INTEGER_H
