/*Дана очень длинная последовательность целых чисел длины n. Требуется вывести в отсортированном виде её первые k элементов. Последовательность может не помещаться в память. Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void insertionSort(vector<int>& arr)
{
    int n = arr.size();
    int tmp = 0;
    int j = 0;

    for (int i = 1; i < n; i++) {
        tmp = arr[i];
        for (j = i; j > 0 && tmp < arr[j - 1]; j--) {
            arr[j] = arr[j - 1];
        }
        arr[j] = tmp;
    }
}

void merge(vector<int>& arr1, vector<int>& arr2, int k)
{
    int i = 0;
    int pos1 = 0;
    int pos2 = 0;
    int len_arr1 = arr1.size();
    int len_arr2 = arr2.size();
    vector<int> temp;

    for (i = 0; i < k && pos2 < len_arr2; i++) {
        if(arr1[pos1] < arr2[pos2]) {
            temp.push_back(arr1[pos1++]);
        } else {
            temp.push_back(arr2[pos2++]);
        }
    }
    while (i < len_arr1) {
        temp.push_back(arr1[pos1++]);
        i++;
    }
    swap(arr1, temp);
}
int main()
{
    int size = 0;
    int k = 0;
    cin >> size >> k;
    int element;
    vector<int> buff;

    for (int i = 0; i < k; i++) {
        cin >> element;
        buff.push_back(element);
    }
    insertionSort(buff);
    size -= k;
    while(size > 0) {
        vector<int> buffForMerge;
        for (int i = 0; i < k && i < size; i++) {
            cin >> element;
            buffForMerge.push_back(element);
        }
        insertionSort(buffForMerge);
        merge(buff, buffForMerge, k);
        size -= k;
    }
    for (int i = 0; i < k; i++) {
        cout << buff[i] << " ";
    }
    cout << endl;
    return 0;
}
