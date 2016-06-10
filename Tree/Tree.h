//
// Created by Саид on 10.06.16.
//

#ifndef TREE_TREE_H
#define TREE_TREE_H

template <class T>
class Tree {
public:
    Tree();
    ~Tree();
    void insert(T value);
    bool containsValue(T value);
private:
    struct Node {
        T value;
        Node* right;
        Node* left;

        Node(): right(nullptr), left(nullptr) { }
    };
    Node *root_;
    void insertToNode(Node *&node, T value);
    bool searchData(Node *node, T value);
    void deleteNode(Node *&node);
};

template <class T>
Tree<T>::Tree():
    root_(nullptr)
{ }

template <class T>
Tree<T>::~Tree() {
    if (root_ != nullptr) {
        deleteNode(root_->left);
        deleteNode(root_->right);

        delete root_;
    }
}

template <class T>
void Tree<T>::deleteNode(Node *&node) {
    if (node != nullptr) {
        deleteNode(node->left);
        deleteNode(node->right);

        delete node;
    }
}

template <class T>
void Tree<T>::insert(T value) {
    insertToNode(root_, value);
}

template <class T>
void Tree<T>::insertToNode(Node *&node, T value) {
    if (node == nullptr) {
        node = new Node();

        node->value = value;
    } else if (value <= node->value) {
        insertToNode(node->left, value);
    } else {
        insertToNode(node->right, value);
    }
}

template <class T>
bool Tree<T>::containsValue(T value) {
    return searchData(root_, value);
}

template <class T>
bool Tree<T>::searchData(Node *node, T value) {
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

#endif //TREE_TREE_H
