/*В супермаркете решили оптимизировать показ рекламы. Известно расписание прихода и ухода покупателей (два целых числа). Каждому покупателю необходимо показать минимум 2 рекламы.  Рекламу можно транслировать только в целочисленные моменты времени. Покупатель может видеть рекламу от момента прихода до момента ухода из магазина.
 В каждый момент времени может показываться только одна реклама. Считается, что реклама показывается мгновенно. Если реклама показывается в момент ухода или прихода, то считается, что посетитель успел её посмотреть. Требуется определить минимальное число показов рекламы. Реализована сортировка слиянием.*/

#include <iostream>
#include <cstdio>
using namespace std;
template<class T>
struct Point{
    T begin;
    T end;
    int count;
    Point(): begin(0), end(0), count(0) {}
    Point<T>& operator =(Point<T>& p);
};
template<class T>
Point<T>& Point<T>::operator=(Point<T> &p)
{
    begin = p.begin;
    end = p.end;
    return *this;
}

template<class T>
void merge(Point<T>* arr, int p, int q, int r)
{
    int i = p, j = q + 1, k = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    Point<T>* temp = new Point<T>[n1 + n2];
    while( i <= q && j <= r) {
        if (arr[i].end < arr[j].end) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while( i <= q ) {
        temp[k++] = arr[i++];
    }
     while( j <= r ) {
        temp[k++] = arr[j++];
    }
    for(int i = 0; i < n1 + n2; i++) {
        arr[p + i] = temp[i];
    }
}

template<class T>
void mergesort(Point<T>* arr, int p, int r)
{
    if (p < r) {
        int q = (r + p) / 2;
        mergesort(arr, p, q);
        mergesort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
template<class T>
bool viewsAds(Point<T>* array, int time, int index)
{
    if(time <= array[index].end && time >= array[index].begin) {
        return true;
    }
    return false;
}
template<class T>
bool goNew(Point<T>* array, int index_sim, int index)
{
    if(array[index_sim].end <= array[index].end && array[index_sim].begin >= array[index].begin) {
        return true;
    }
    return false;
}

int main()
{
    int index = 0;
    int indexAds = 0;
    int count = 0;
    int min_k = 0;
    cin >> count;
    int* mass = new int[count];
    Point<int>* array = new Point<int>[count];

    for(int i = 0; i < count; i++) {
        cin >> array[i].begin >> array[i].end;
    }
    mergesort(array, 0, count - 1);
    int time_one = array[0].end - 1;
    int time_two = array[0].end;
    indexAds = array[0].end;
    min_k = 2;
    for (int index = 1; index < count; index++) {
        if(!viewsAds(array, time_one, index)) {
            if(viewsAds(array, time_two, index)) {
                  if (time_two == array[index].end) {
                    min_k ++;
                    time_one = array[index].end - 1;
                    time_two = array[index].end;
                } else {
                    min_k++;
                    time_one = time_two;
                    time_two = array[index].end;
                }

            } else {
                min_k += 2;
                time_one = array[index].end - 1;
                time_two = array[index].end;
            }
        }
    }
    cout << min_k;
    return 0;
}