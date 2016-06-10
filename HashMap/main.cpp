#include <iostream>
#include "hashmap.h"
#include "../wrappers/Integer.h"

int main() {
    HashMap<Integer, std::string> map;
    std::string value = "said";

    for (int i = 0; i < 100; ++i) {
        map.put(i, value + std::to_string(i));
    }

    for (int j = 0; j < 100; ++j) {
        std::cout << map.get(j) << std::endl;
    }

    return 0;
}
