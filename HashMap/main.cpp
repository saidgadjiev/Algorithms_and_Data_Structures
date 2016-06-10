#include <iostream>
#include "hashmap.h"
#include "../wrappers/Integer.h"

int main() {
    HashMap<Integer, int> map;

    for (int i = 0; i < 100; ++i) {
        map.put(i, i);
    }

    for (int j = 0; j < 100; ++j) {
        std::cout << map.get(j)->getValue() << std::endl;
    }

    return 0;
}
