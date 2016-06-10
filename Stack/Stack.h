//
// Created by Саид on 10.06.16.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

template <class T>
class Stack {
public:
    Stack();
    ~Stack();
    void push(T value);
    T pop();
    T top();
    bool isEmpty();
private:
    struct Node {
        T data;
        Node *next;

        Node(): next(0) {}
    };

    Node *head_;
};

template <class T>
Stack<T>::Stack():
    head_(nullptr)
{ }

template <class T>
Stack<T>::~Stack()
{
    while (head_) {
        Node *tmp = head_;

        head_ = head_->next;

        delete tmp;
    }
}

template <class T>
bool Stack<T>::isEmpty() {
    return head_ == nullptr;
}

template <class T>
void Stack<T>::push(T value) {
    if (!head_) {
        head_ = new Node();
        head_->data = value;

        return;
    }
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = head_;
    head_ = newNode;
}

template <class T>
T Stack<T>::pop() {
    if (isEmpty()) {
        return -1;
    }
    Node *node = head_;

    T data = node->data;
    head_ = node->next;

    delete node;
    return data;
}

template <class T>
T Stack<T>::top() {
    if (isEmpty()) {
        return -1;
    }
    Node *node = head_;
    T data = node->data;

    return data;
}


#endif //STACK_STACK_H
