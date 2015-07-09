/* Дан массив целых чисел А[0..n-1]). Известно, что на интервале [0, m] значения массива строго возрастают, а на интервале [m, n-1] строго убывают. Найти m за O(log m). Задача решается с помощью бинарного поиска.*/
#include <iostream>
using namespace std;

int BinarySearch( int *arr, int count_begin, int count_end )
{
    int first = count_begin;
    int last = count_end;// Элемент в last не учитывается.
    while( first < last ) {
        int mid = ( first + last ) / 2;
        if( arr[mid - 1] > arr[mid] )
            last = mid;
        else
            first = mid + 1; // Здесь отличие от BinarySearch1.
    }
    // Все элементы слева от first строго больше искомого.
    return first - 1;
}

int main()
{
    int arr_size = 0;
    cin >> arr_size;
    int arr[arr_size];
    int power = 1;

    for (int i = 0; i < arr_size; i++) {
        cin >> arr[i];
    }

    while (arr[power / 2] < arr[power] && power <= arr_size)
    {
        power = power * 2;
    }
    if (power > arr_size) cout << BinarySearch(arr, power / 2, arr_size);
    else cout << BinarySearch(arr, power / 2, power);
    return 0;
}
