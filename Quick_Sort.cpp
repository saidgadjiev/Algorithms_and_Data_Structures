#include <iostream>
#define SIZEDIGIT 64
using namespace std;

int digit(long long element, int w)
{
    long long temp = element;
    for (long long i = 0; i < SIZEDIGIT - w; i++) {
        temp = temp >> 1;
    }
    return temp & 1;
}

void binaryQuickSort(long long arr[], long long l, long long r, long long w)
{
    long long i = l, j = r;
    if(r <= l || w > SIZEDIGIT) return;
    while(j != i) {
        while(digit(arr[i], w) == 0 && (i < j)) i++;
        while(digit(arr[j], w) == 1 && (j > i)) j--;
        swap(arr[i], arr[j]);
    }
    if(digit(arr[r], w) == 0) j++;
    binaryQuickSort(arr, l, j -1, w + 1);
    binaryQuickSort(arr, j, r, w + 1);
}
int main()
{
    long long count = 0;
    cin >> count;
    long long arr[count];

    for (long long i = 0; i < count; i++) {
        cin >> arr[i];
    }
    binaryQuickSort(arr, 0, count - 1, 1);
    for (long long i = 0; i < count; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
