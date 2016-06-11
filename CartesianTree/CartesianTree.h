//
// Created by Саид on 10.06.16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

template <class T>
class Treap {
public:
    Treap();
    ~Treap();
    void insert(int priority, T value);
    bool containsValue(T value);
private:
    struct Node {
        int priority;
        T value;
        Node *right;
        Node *left;

        Node() : left(nullptr), right(nullptr) {}
        Node(int priority, int value): priority(priority), value(value), left(nullptr), right(nullptr) {}
    };
    Node *root_;
    void split(Node *currentNode, int value, Node *&left, Node *&right);
    void insertNode(Node *&node, int priority, T value);
    bool searchData(Node *node, T value);
    void deleteNode(Node *&node);
};

template <class T>
Treap<T>::Treap():
    root_(nullptr)
{ }

template <class T>
Treap<T>::~Treap() {
    if (root_ != nullptr) {
        deleteNode(root_->left);
        deleteNode(root_->right);

        delete root_;
    }
}

template <class T>
void Treap<T>::deleteNode(Node *&node) {
    if (node != nullptr) {
        deleteNode(node->left);
        deleteNode(node->right);

        delete node;
    }
}

template <class T>
void Treap<T>::insert(int priority, T value) {
    insertNode(root_, priority, value);
}

template <class T>
void Treap<T>::insertNode(Node *&node, int priority, T value) {
    if (node == nullptr) {
        node = new Node(priority, value);

        return;
    }
    if (node->priority < priority) {
        Node *newNode, *tree1, *tree2;

        split(node, value, tree1, tree2);
        newNode = new Node(priority, value);
        newNode->left = tree1;
        newNode->right = tree2;
        node = newNode;
        return;
    }
    if (node->value > value) {
        insertNode(node->left, priority, value);
    } else {
        insertNode(node->right, priority, value);
    }
}

template <class T>
bool Treap<T>::containsValue(T value) {
    return searchData(root_, value);
}

template <class T>
bool Treap<T>::searchData(Node *node, T value) {
    if (node == nullptr) {
        return false;
    } else if (node->value == value) {
        return true;
    } else if (value <= node->value) {
        return searchData(node->left, value);
    } else {
        return searchData(node->right, value);
    }
}

template <class T>
void Treap<T>::split(Node *currentNode, int value, Node *&left, Node *&right) {
    if (currentNode == nullptr) {
        left = nullptr;
        right = nullptr;
    } else if (currentNode->value <= value) {
        split(currentNode->right, value, currentNode->right, right);
        left = currentNode;
    } else {
        split(currentNode->left, value, left, currentNode->left);
        right = currentNode;
    }
}


#endif //TREE_TREE_H
