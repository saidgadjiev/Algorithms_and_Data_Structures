#include <iostream>
#include "CartesianTree.h"

int main() {
    Treap<int> treap;
    
    for (int i = 0; i < 10; ++i) {
        treap.insert(i, i);
    }
    
    return 0;
}
