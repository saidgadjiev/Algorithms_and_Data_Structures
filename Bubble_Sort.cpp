/*Пузырьковая сортировка*/

#include <iostream>
#include <assert.h>
using namespace std;

class CArray {
public:
    CArray() : buffer( 0 ), bufferSize( 0 ), realSize( 0 ) {}
    ~CArray() { delete[] buffer; }
    int GetAt( int index ) const;
    int GetSize() const { return realSize; }
    int operator[]( int index ) const { return GetAt( index ); }
    int& operator[]( int index ) { return buffer[index]; }
    void Add( int element );
    void bubble_sort();
private:
    int* buffer;
    int bufferSize;
    int realSize;
    void grow();
};


int CArray::GetAt( int index ) const
{
    assert( index >= 0 && index < realSize && buffer != 0 );
    return buffer[index];
}

void CArray::grow()
{
    int newBufferSize = max(bufferSize * 2, 1);
    int* newBuffer = new int[newBufferSize];
    for( int i = 0; i < realSize; ++i )
        newBuffer[i] = buffer[i];
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

void CArray::bubble_sort()
{
    for (int i = GetSize() - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (buffer[j] > buffer[j+1]) {
                swap(buffer[j], buffer[j+1]);
            }
        }
    }
}
int main()
{
    int element = 0;
    CArray arr_sort;

    while(cin >> element) {
        arr_sort.Add(element);
    }
    arr_sort.bubble_sort();
    for (int i = 0; i < arr_sort.GetSize(); i++) {
        cout << arr_sort[i] << endl;
    }
    return 0;
}
