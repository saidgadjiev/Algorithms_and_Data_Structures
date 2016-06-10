#include <iostream>
#include <cstring>
#include "Deque.h"

using namespace std;


int main() {
    Deque<std::string> deque;

    for (int i = 0; i < 100; ++i) {
        deque.pushBack("test" + std::to_string(i));
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << deque.popBack() << std::endl;
    }

    return 0;
}