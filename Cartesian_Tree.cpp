/*Дано число N < 106 и последовательность пар целых чисел из [-231..231] длиной N.
 Построить декартово дерево из N узлов, характеризующихся парами чисел {Xi, Yi}.
 Каждая пара чисел {Xi, Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.*/

#include <iostream>
#include <ctime>
#include <cstdlib>

struct Treap {
    int key;
    int priority;
    Treap *left;
    Treap *right;
    Treap() : left(NULL), right(NULL) {}
    Treap(int key, int priority) : key(key), priority(priority), left(NULL), right(NULL) {}
};

struct BinaryTree {
    int key;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree() : left(NULL), right(NULL) {}
    BinaryTree(int key) : key(key), left(NULL), right(NULL) {}
};

void Split(Treap *currentNode, int key, Treap *&left, Treap *&right) {
    if (currentNode == NULL) {
        left = NULL;
        right = NULL;
    } else if (currentNode->key <= key) {
        Split(currentNode->right, key, currentNode->right, right);
        left = currentNode;
    } else {
        Split(currentNode->left, key, left, currentNode->left);
        right = currentNode;
    }
}

void InsertTreap(Treap *&node, int key, int priority)
{
    if (node == NULL) {
        node = new Treap(key, priority);
        return;
    }
    if (node->priority < priority) {
        Treap *newNode, *tree1, *tree2;
        Split(node, key, tree1, tree2);
        newNode = new Treap(key, priority);
        newNode->left = tree1;
        newNode->right = tree2;
        node = newNode;
        return;
    }
    if (node->key > key) {
        InsertTreap(node->left, key, priority);
    } else {
        InsertTreap(node->right, key, priority);
    }
}

void InsertBinaryTree(BinaryTree *&node, int key) {
    if (node == NULL) {
        node = new BinaryTree(key);
        return;
    }
    if (node->key > key) {
        InsertBinaryTree(node->left, key);
    } else {
        InsertBinaryTree(node->right, key);
    }
}

template <typename T>
int height(T *node)
{
    if (node == NULL) {
        return 0;
    } else {
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        
        return (lHeight > rHeight)?(lHeight+1):(rHeight+1);
    }
    return 0;
}

template <typename T>
int getMaxWidth(T* root)
{
    int maxWidth = 0;
    int width;
    int h = height(root);
    
    for (int i = 1; i <= h; i++) {
        width = getWidth(root, i);
        if(width > maxWidth) {
            maxWidth = width;
        }
    }
    
    return maxWidth;
}

template <typename T>
int getWidth(T* root, int level)
{
    
    if(root == NULL) {
        return 0;
    }
    
    if(level == 1) {
        return 1;
    } else if (level > 1) {
        return getWidth(root->left, level-1) +
        getWidth(root->right, level-1);
    }
    return 0;
}

int main()
{
    int n;
    std::cin >> n;
    int key, priority;
    Treap *rootTreap = NULL;
    BinaryTree *rootBinary = NULL;
    
    for (int i = 0; i < n; ++i) {
        std::cin >> key >> priority;
        InsertTreap(rootTreap, key, priority);
        InsertBinaryTree(rootBinary, key);
    }
    std::cout << getMaxWidth<Treap>(rootTreap) - getMaxWidth<BinaryTree>(rootBinary);
    
    return 0;
}
