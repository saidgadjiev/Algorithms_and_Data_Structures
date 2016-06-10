#include <iostream>
#include "Stack.h"

int main()
{
    Stack<int> stack;

    stack.push(1);

    for (int i = 0; i < 100; ++i) {
        stack.push(i);

        std::cout << stack.pop() << std::endl;
    }

    return 0;
}

