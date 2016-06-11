#include <iostream>
#include <vector>
#include <cstdlib>

template<typename T>
int partition(std::vector<T> &mas, int l, int r) {
    if (l != r) {
        swap(mas[l + rand() % (r - l)], mas[l]);
    }
    int x = mas[l];
    int i = r + 1;
    
    for (int j = r; j >= l; j--) {
        if (mas[j] >= x)
            std::swap(mas[--i], mas[j]);
    }
    
    return i;
}
template<typename T>
T kStatistik(std::vector<T> mas, int n) {
    int l = 0, r = mas.size() - 1;
    
    while(true) {
        int pos = partition(mas,l,r);
        
        if (pos < n) {
            l = pos + 1;
        } else if (pos > n) {
            r = pos - 1;
        } else {
            return mas[n];
        }
    }
}

int main()
{
    std::vector<int> array;
    int element = 0;
    int count = 0;
    
    std::cin >> count;
    int k = 0;
    
    std::cin >> k;
    
    for (int i = 0; i < count; i++) {
        std::cin >> element;
        array.push_back(element);
    }
    std::cout << kStatistik(array, k);
}
