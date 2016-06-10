#include <iostream>
#include "dequeue.h"

using namespace std;


int main() {
    Dequeue<int> dequeue;

    for (int i = 0; i < 100; ++i) {
        dequeue.pushBack(i);
    }

    for (int i = 0; i < 100; ++i) {
        std::cout << dequeue.popBack() << std::endl;
    }

    return 0;
}