/*Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв. Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте в случае, когда коэффициент заполнения таблицы достигает 3/4.
 Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.  Для разрешения коллизий используйте двойное хеширование.
 Формат входных данных
 Каждая строка входных данных задает одну операцию над множеством. Запись операции состоит из типа операции и следующей за ним через пробел строки, над которой проводится операция.
 Тип операции  – один из трех символов:
 +  означает добавление данной строки в множество;
 -  означает удаление  строки из множества;
 ?  означает проверку принадлежности данной строки множеству.
 При добавлении элемента в множество НЕ ГАРАНТИРУЕТСЯ, что он отсутствует в этом множестве. При удалении элемента из множества НЕ ГАРАНТИРУЕТСЯ, что он присутствует в этом множестве.
 Формат выходных данных
 Программа должна вывести для каждой операции одну из двух строк OK или FAIL, в зависимости от того, встречается ли данное слово в нашем множестве.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Treap {
    int key;
    int priority;
    Treap* left;
    Treap* right;
    Treap() : left(NULL), right(NULL) {}
    Treap(int key, int priority) : key(key), priority(priority), left(NULL), right(NULL) {}
};

struct BinaryTree {
    int key;
    BinaryTree* left;
    BinaryTree* right;
    BinaryTree() : left(NULL), right(NULL) {}
    BinaryTree(int key) : key(key), left(NULL), right(NULL) {}
};

void Split(Treap* currentNode, int key, Treap*& left, Treap*& right) {
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

void InsertTreap(Treap*& node, int key, int priority)
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
     if (node->key > key)
        InsertTreap(node->left, key, priority);
    else
        InsertTreap(node->right, key, priority);
}

void InsertBinaryTree(BinaryTree*& node, int key) {
    if (node == NULL) {
        node = new BinaryTree(key);
        return;
    }
    if (node->key > key)
        InsertBinaryTree(node->left, key);
    else
        InsertBinaryTree(node->right, key);
}

template <typename T>
int height(T* node)
{
   if (node==NULL)
     return 0;
   else
   {
     /* compute the height of each subtree */
     int lHeight = height(node->left);
     int rHeight = height(node->right);
     /* use the larger one */

     return (lHeight > rHeight)? (lHeight+1): (rHeight+1);
   }
}

template <typename T>
int getMaxWidth(T* root)
{
  int maxWidth = 0;
  int width;
  int h = height(root);
  int i;

  /* Get width of each level and compare
     the width with maximum width so far */
  for(i=1; i<=h; i++)
  {
    width = getWidth(root, i);
    if(width > maxWidth)
      maxWidth = width;
  }

  return maxWidth;
}

template <typename T>
/* Get width of a given level */
int getWidth(T* root, int level)
{

  if(root == NULL)
    return 0;

  if(level == 1)
    return 1;

  else if (level > 1)
    return getWidth(root->left, level-1) +
             getWidth(root->right, level-1);
}

int main()
{
    int n;
    cin >> n;
    int key, priority;
    Treap* rootTreap = NULL;
    BinaryTree* rootBinary = NULL;

    for (int i = 0; i < n; ++i) {
        cin >> key >> priority;
        InsertTreap(rootTreap, key, priority);
        InsertBinaryTree(rootBinary, key);
    }
    cout << getMaxWidth<Treap>(rootTreap) - getMaxWidth<BinaryTree>(rootBinary);
    return 0;
}
