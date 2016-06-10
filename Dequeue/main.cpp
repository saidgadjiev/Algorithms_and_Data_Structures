#include <iostream>
#include <cstring>
#include "dequeue.h"

using namespace std;


int main() {
    Dequeue<std::string> dequeue;

    for (int i = 0; i < 100; ++i) {
        dequeue.pushBack("test" + std::to_string(i));
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << dequeue.popBack() << std::endl;
    }

    return 0;
}