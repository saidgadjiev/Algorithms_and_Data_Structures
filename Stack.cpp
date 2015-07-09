/*Пара слов называется стековой анаграмой, если одно слово можно получить из другого, проведя последовательность стековых операций с его буквами (взять очередную букву исходного слова и поместить ее в стек; взять букву из стека и добавить ее в конец выходного слова).
 Для заданной пары слов требуется определить, можно ли выполнить последовательность стековых операций, переводящую первое слово во второе. Все буквы в слове различные.
 Формат входных данных. Пара слов, являющихся анаграммой.
 Формат выходных данных. YES, если последовательность стековых операций существует и NO в противном случае.*/

#include <iostream>
#include <cstring>
using namespace std;

struct CNode {
        char data;
        CNode *next, *prev;
        CNode(): next(0), prev(0) {}
};

typedef CNode *PNode;

struct CStack {
        PNode Head, Tail;
        CStack(): Head(0), Tail(0) {}
};

void Push ( CStack &S, char x )
{
    PNode NewNode;
    NewNode = new CNode;
    NewNode->data = x;
    NewNode->next = S.Head;
    NewNode->prev = NULL;
    if ( S.Head )
        S.Head->prev = NewNode;
    S.Head = NewNode;
    if ( ! S.Tail )
        S.Tail = S.Head;
}

char Pop ( CStack &S )
{
    PNode TopNode = S.Head;
    char x;

    if ( ! TopNode )
        return -1;
    x = TopNode->data;
    S.Head = TopNode->next;
    if ( S.Head ) S.Head->prev = NULL;
    else S.Tail = NULL;
    delete TopNode;
    return x;
}

char sow(CStack &S)
{
    char x;
    PNode TopNode = S.Head;
    if ( ! TopNode )
        return -1;
    x = TopNode->data;
    return x;
}

bool IsEmpty(CStack &S)
{
    return S.Head == 0;
}

int main()
{
    CStack st;
    char st_elem = ' ';
    string comp_word = "";
    string word_one = " ";
    string word_two = " ";
    cin >> word_one >> word_two;
    int index_one = 0, index_two = 0;

    while(index_one < word_one.length()) {
        Push(st, word_one[index_one]);
        index_one++;
        if (!IsEmpty(st)) {
            while (sow(st) == word_two[index_two]) {
                comp_word += Pop(st);
                index_two++;
            }
        }
    }
    if (comp_word.compare(word_two) == 0) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}

