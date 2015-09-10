/*В супермаркете решили оптимизировать показ рекламы. Известно расписание прихода и ухода покупателей (два целых числа). Каждому покупателю необходимо показать минимум 2 рекламы.  Рекламу можно транслировать только в целочисленные моменты времени. Покупатель может видеть рекламу от момента прихода до момента ухода из магазина.
 В каждый момент времени может показываться только одна реклама. Считается, что реклама показывается мгновенно. Если реклама показывается в момент ухода или прихода, то считается, что посетитель успел её посмотреть. Требуется определить минимальное число показов рекламы. Реализована сортировка слиянием.*/
/*T(n) = O(nlogn)
 M(n) = O(n)*/

#include <iostream>
#include <cstdio>

template<class T>
struct Point{
    T begin;
    T end;
    int count;
    
    Point(): begin(0), end(0), count(0) {}
    Point<T> &operator =(Point<T>& p);
};

template<class T>
Point<T> &Point<T>::operator =(Point<T> &p)
{
    begin = p.begin;
    end = p.end;
    return *this;
}

template<class T>
void merge(Point<T> *arr, int p, int q, int r)
{
    int i = p, j = q + 1, k = 0;
    int n1 = q - p + 1;
    int n2 = r - q;
    Point<T> *temp = new Point<T>[n1 + n2];
    
    while (i <= q && j <= r) {
        if (arr[i].end < arr[j].end) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while(i <= q) {
        temp[k++] = arr[i++];
    }
    while(j <= r) {
        temp[k++] = arr[j++];
    }
    for(int i = 0; i < n1 + n2; i++) {
        arr[p + i] = temp[i];
    }
}

template<class T>
void mergeSort(Point<T> *arr, int p, int r)
{
    if (p < r) {
        int q = (r + p) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}

template<class T>
bool viewsAds(Point<T> *array, int time, int index)
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
    int indexAds = 0;
    int count = 0;
    int minK = 0;
    std::cin >> count;
    Point<int> *array = new Point<int>[count];
    
    for(int i = 0; i < count; i++) {
        std::cin >> array[i].begin >> array[i].end;
    }
    mergeSort(array, 0, count - 1);
    int timeOne = array[0].end - 1;
    int timeTwo = array[0].end;
    
    indexAds = array[0].end;
    minK = 2;
    for (int index = 1; index < count; index++) {
        if(!viewsAds(array, timeOne, index)) {
            if(viewsAds(array, timeTwo, index)) {
                if (timeTwo == array[index].end) {
                    minK++;
                    timeOne = array[index].end - 1;
                    timeTwo = array[index].end;
                } else {
                    minK++;
                    timeOne = timeTwo;
                    timeTwo = array[index].end;
                }
                
            } else {
                minK += 2;
                timeOne = array[index].end - 1;
                timeTwo = array[index].end;
            }
        }
    }
    std::cout << minK;
    return 0;
}
