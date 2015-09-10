/*Дан массив натуральных чисел A[0..n), n не превосходит 10^8. Так же задан размер некотрого окна (последовательно расположенных элементов массива) в этом массиве k, k<=n. Требуется для каждого положения окна (от 0 и до n-k) вывести значение максимума в окне. Скорость работы O(n log n)
 Формат входных данных. Вначале вводится n - количество элементов массива. Затем вводится n строк со значением каждого элемента. Затем вводится k  - размер окна.
 Формат выходных данных. Разделенные пробелом значения максимумов для каждого положения окна.*/

#include <iostream>
#include <algorithm>
#include <assert.h>

struct CHeap {
    int element;
    int index;
};

void siftdown(CHeap heap[], int i, int size)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int largest = i;
    
    if(left < size && heap[left].element > heap[i].element) {
        largest = left;
    }
    if(right < size && heap[right].element > heap[largest].element) {
        largest = right;
    }
    if(largest != i) {
        std::swap(heap[i], heap[largest]);
        siftdown(heap, largest, size);
    }
}

int extractMax(CHeap heap[], int& size)
{
    assert(size > 0);
    int result = heap[0].element;
    
    heap[0] = heap[size - 1];
    size--;
    if(size > 0) {
        siftdown(heap, 0, size);
    }
    
    return result;
}

void siftup( CHeap heap[], int index )
{
    while (index > 0) {
        int parent = (index - 1) / 2;
        if(heap[index].element <= heap[parent].element)
            return;
        std::swap(heap[index].element, heap[parent].element);
        std::swap(heap[index].index, heap[parent].index);
        index = parent;
    }
}

void add(CHeap heap[], int& realsize, int element, int index)
{
    realsize++;
    heap[realsize - 1].element = element;
    heap[realsize - 1].index = index;
    siftup( heap, realsize - 1 );
}

int main()
{
    int realsize = 0;
    int number_read = 0;
    int arr_size = 0;
    int size_wind = 0;
    std::cin >> arr_size;
    CHeap heap[arr_size];
    int in_arr[arr_size];
    
    for (int i = 0; i < arr_size; i++) {
        std::cin >> in_arr[i];
    }
    std::cin >> size_wind;
    for (int i = 0; i < size_wind; i++) {
        add(heap, realsize, in_arr[i], i);
    }
    number_read = size_wind;
    while(number_read <= arr_size) {
        if (heap[0].index >= number_read - size_wind && heap[0].index <= number_read) {
            std::cout << heap[0].element << " ";
            add(heap, realsize, in_arr[number_read], number_read);
            number_read++;
        } else {
            extractMax(heap, realsize);
        }
    }
    
    return 0;
}
