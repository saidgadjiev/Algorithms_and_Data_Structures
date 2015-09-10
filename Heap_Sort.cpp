/*Напишите программу, печатающую набор строк в лексикографическом порядке.
 Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n', считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать свою функцию сравнения строк. Реализована пиромидальная сортировка.*/
/*T(n) = O(n)*/

#include <iostream>
#include <string>
#include <cstdlib>

void heapMake(std::string *heap, int n)
{
    for (int i = n / 2; i >= 1; --i) {
        for (int j = i; j <= n / 2;) {
            int k = j * 2;
            if (k + 1 <= n and heap[k] < heap[k+1]) {
                ++k;
            }
            if (heap[j] < heap[k]) {
                swap(heap[k], heap[j]);
                j = k;
            } else {
                break;
            }
        }
    }
}
void heapPop(std::string *heap, int n)
{
    swap(heap[n], heap[1]);
    for (int i = 1; 2 * i < n;) {
        i *= 2;
        if (i + 1 < n && heap[i] < heap[i + 1]) {
            i += 1;
        }
        if (heap[i / 2] < heap[i]) {
            swap(heap[i / 2], heap[i]);
        }
    }
}

void heapSortFast(std::string *data, int n)
{
    heapMake(data - 1, n);
    for (int i = 0; i < n; ++i) {
        heapPop(data - 1, n - i);
    }
}

int main ()
{
    int i = 0;
    int count = 0;
    std::cin >> count;
    std::string line;
    std::string* heap = new std::string[count];
    
    while( i < count ) {
        std::cin >> line;
        heap[i] = line;
        i++;
    }
    heapSortFast(heap, count);
    for (int i = 0; i < count; i++) {
        std::cout << heap[i] << std::endl;
    }
    
    delete [] heap;
    return 0;
}
