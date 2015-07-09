/*Дано число N < 106 и последовательность целых чисел из [-231..231] длиной N.
 Требуется построить бинарное дерево, заданное наивным порядком вставки.
 Т.е., при добавлении очередного числа K в дерево с корнем root, если root→Key ≤ K, то узел K добавляется в правое поддерево root; иначе в левое поддерево root. Выведите элементы в порядке level-order (по слоям, “в ширину”).*/

#include <iostream>
#include <queue>
using namespace std;

struct BstNode {
    int data;
    BstNode* right;
    BstNode* left;
};

BstNode* GetNewNode(int data)
{
    BstNode* newNode = new BstNode();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
BstNode* Insert(BstNode* root, int data)
{
    if (root == NULL) {    //empty
        root = GetNewNode(data);
    } else if (data <= root->data) {
        root->left = Insert(root->left, data);
    } else {
        root->right = Insert(root->right, data);
    }
    return root;
}

bool Search(BstNode* root, int data)
{
    if (root == NULL) return false;
    else if (root->data == data) return true;
    else if (data <= root->data) return Search(root->left, data);
    else return Search(root->right, data);
}

void PrintLevelOrder(BstNode* root)
{
    if (root == NULL)
        return;
    queue<BstNode*> Q;
    Q.push(root);
    while (!Q.empty()) {
        BstNode* current = Q.front();
        cout << current->data << " ";
        if (current->left != NULL) Q.push(current->left);
        if (current->right != NULL) Q.push(current->right);
        Q.pop();
    }
}
int main()
{
    BstNode* root = NULL;       //Creating an empty tree
    int count = 0;
    cin >> count;
    int data = 0;
    for (int i = 0; i < count; i++) {
        cin >> data;
        root = Insert(root, data);
    }
    PrintLevelOrder(root);
    return 0;
}
