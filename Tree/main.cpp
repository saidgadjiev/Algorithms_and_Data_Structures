#include <iostream>
#include "Tree.h"

int main() {
    Tree<int> tree;
    
    for (int i = 0; i < 10; ++i) {
        tree.insert(i);
    }
    
    return 0;
}
