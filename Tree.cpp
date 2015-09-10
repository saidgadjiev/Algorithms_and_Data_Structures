/*Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
 Требуется построить бинарное дерево, заданное наивным порядком вставки.
 Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root. Выведите элементы в порядке level-order (по слоям, “в ширину”).*/

#include <iostream>
#include <queue>

struct BstNode {
    int data;
    BstNode* right;
    BstNode* left;
};

void deleteTree(BstNode *root)
{
    if (root != NULL) {
        deleteTree(root->left);
        deleteTree(root->right);
        
        delete root;
    }
}

BstNode *getNewNode(int data)
{
    BstNode* newNode = new BstNode();
    
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode *insert(BstNode *root, int data)
{
    if (root == NULL) {
        root = getNewNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

bool search(BstNode* root, int data)
{
    if (root == NULL) {
        return false;
    } else if (root->data == data) {
        return true;
    } else if (data <= root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
        
    }
}

void printLevelOrder(BstNode* root)
{
    if (root == NULL)
        return;
    std::queue<BstNode*> queue;
    queue.push(root);
    while (!queue.empty()) {
        BstNode* current = queue.front();
        
        std::cout << current->data << " ";
        if (current->left != NULL) {
            queue.push(current->left);
        }
        if (current->right != NULL) {
            queue.push(current->right);
        }
        queue.pop();
    }
}
int main()
{
    BstNode* root = NULL;
    int count = 0;
    std::cin >> count;
    int data = 0;
    
    for (int i = 0; i < count; i++) {
        std::cin >> data;
        root = insert(root, data);
    }
    printLevelOrder(root);
    
    return 0;
}
