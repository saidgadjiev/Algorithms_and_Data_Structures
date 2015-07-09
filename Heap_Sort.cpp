/*Напишите программу, печатающую набор строк в лексикографическом порядке.
 Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n', считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать свою функцию сравнения строк. Реализована пиромидальная сортировка.*/

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

void heap_make(string *a, int n)
{
    for (int i = n / 2; i >= 1; --i) {
        for (int j = i; j <= n / 2;) {
            int k = j * 2;
            if (k + 1 <= n and a[k] < a[k+1]) {
                ++k;
            }
            if (a[j] < a[k]) {
                swap(a[k], a[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}
void heap_pop(string *a, int n)
{
    swap(a[n], a[1]);
    for (int i = 1; 2 * i < n;) {
        i *= 2;
        if (i + 1 < n && a[i] < a[i + 1]) {
            i += 1;
        }
        if (a[i / 2] < a[i]) {
            swap(a[i / 2], a[i]);
        }
    }
}

void heap_sort_fast(string *data, int n)
{
    heap_make(data - 1, n);
    for (int i = 0; i < n; ++i) {
        heap_pop(data - 1, n - i);
    }
}

int main ()
{
    int i = 0;
    int count = 0;
    cin >> count;
    string line;
    string* arr_line = new string[count];
    while( i < count ) {
        cin >> line;
        arr_line[i] = line;
        i++;
    }
    heap_sort_fast(arr_line, count);
    for (int i = 0; i < count; i++) {
        cout << arr_line[i] << endl;
    }
    delete [] arr_line;
    return 0;
}
