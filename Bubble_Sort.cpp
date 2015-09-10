/*Пузырьковая сортировка*/
/*T(n) = O(n^2)*/

#include <iostream>
#include <assert.h>

class CArray {
public:
    CArray() : buffer(0), bufferSize(0), realSize(0) {}
    ~CArray() { delete[] buffer; }
    int GetAt(int index) const;
    int GetSize() const { return realSize; }
    int operator[](int index) const { return GetAt(index); }
    int& operator[](int index) { return buffer[index]; }
    void Add(int element);
    void bubbleSort();
private:
    int* buffer;
    int bufferSize;
    int realSize;
    void grow();
};


int CArray::GetAt(int index) const
{
    assert(index >= 0 && index < realSize && buffer != 0);
    return buffer[index];
}

void CArray::grow()
{
    int newBufferSize = std::max(bufferSize * 2, 1);
    int* newBuffer = new int[newBufferSize];
    
    for(int i = 0; i < realSize; ++i) {
        newBuffer[i] = buffer[i];
    }
    delete[] buffer;
    buffer = newBuffer;
    bufferSize = newBufferSize;
}

void CArray::Add( int element )
{
    if( realSize == bufferSize )
        grow();
    assert( realSize < bufferSize && buffer != 0 );
    buffer[realSize++] = element;
}

void CArray::bubbleSort()
{
    for (int i = GetSize() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (buffer[j] > buffer[j+1]) {
                std::swap(buffer[j], buffer[j+1]);
            }
        }
    }
}
int main()
{
    int element = 0;
    CArray arrSort;
    
    while(std::cin >> element) {
        arrSort.Add(element);
    }
    arrSort.bubbleSort();
    for (int i = 0; i < arrSort.GetSize(); i++) {
        std::cout << arrSort[i] << std::endl;
    }
    
    return 0;
}