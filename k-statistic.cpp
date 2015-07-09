/* Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется найти k-ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k (0..n-1) в отсортированном массиве. Напишите нерекурсивный алгоритм.
 Требования к дополнительной памяти: O(n). Требуемое среднее время работы: O(n).*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

template<typename T>
int partition(vector<T> &mas, int l, int r) {
  if (l != r)
    swap(mas[l + rand() % (r - l)], mas[l]);
  int x = mas[l];
  int i = r + 1;
  for (int j = r; j >= l; j--) {
      if (mas[j] >= x)
        swap(mas[--i],mas[j]);
  }
  return i;
}
template<typename T>
T k_statistik(vector<T> mas, int n) {
    int l = 0, r = mas.size() - 1;
    for(;;) {
        int pos = partition(mas,l,r);
        if (pos < n)
            l = pos + 1;
        else if (pos > n)
            r = pos - 1;
        else return mas[n];
  }
}

int main()
{
    vector<int> arr_number;
    int element = 0;
    int count = 0;
    cin >> count;
    int k = 0;
    cin >> k;

    for (int i = 0; i < count; i++) {
        cin >> element;
        arr_number.push_back(element);
    }
    cout << k_statistik(arr_number, k);
}
