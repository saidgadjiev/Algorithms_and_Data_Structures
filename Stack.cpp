/*Пара слов называется стековой анаграмой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова).
 Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные.
 Формат входных данных. Пара слов, являющихся анаграммой.
 Формат выходных данных. YES, если последовательность стековых операций существует и NO в противном случае.*/

#include <iostream>
#include <cstring>

struct CNode {
    char data;
    CNode *next, *prev;
    
    CNode():next(0), prev(0) {}
};

typedef CNode *PNode;

struct CStack {
    PNode head, tail;
    
    CStack():head(0), tail(0) {}
};

void Push(CStack &stack, char x)
{
    PNode NewNode;
    
    NewNode = new CNode;
    NewNode->data = x;
    NewNode->next = stack.head;
    NewNode->prev = NULL;
    if (stack.head) {
        stack.head->prev = NewNode;
    }
    stack.head = NewNode;
    if (!stack.tail) {
        stack.tail = stack.head;
    }
}

char Pop(CStack &stack)
{
    PNode TopNode = stack.head;
    char data;
    
    if (!TopNode) {
        return -1;
    }
    data = TopNode->data;
    stack.head = TopNode->next;
    if (stack.head) {
        stack.head->prev = NULL;
    } else {
        stack.tail = NULL;
    }
    
    delete TopNode;
    return data;
}

char sow(CStack &stack)
{
    char data;
    PNode topNode = stack.head;
    if (!topNode) {
        return -1;
    }
    data = topNode->data;
    
    return data;
}

bool IsEmpty(CStack &stack)
{
    return stack.head == 0;
}

int main()
{
    CStack stack;
    std::string compWord = "";
    std::string wordOne = " ";
    std::string wordTwo = " ";
    std::cin >> wordOne >> wordTwo;
    int indexOne = 0, indexTwo = 0;
    
    while(indexOne < wordOne.length()) {
        Push(stack, wordOne[indexOne]);
        indexOne++;
        if (!IsEmpty(stack)) {
            while (sow(stack) == wordTwo[indexTwo]) {
                compWord += Pop(stack);
                indexTwo++;
            }
        }
    }
    if (compWord.compare(wordTwo) == 0) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    
    return 0;
}

