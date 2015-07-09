/*Реализовать дек с динамическим зацикленным буфером. Используется динамический зацикленный буфер.*/
#include <iostream>
#include <cstring>
using namespace std;

class CDequeue {
public:
    CDequeue();
    ~CDequeue(){delete buffer;}
    void push_front(int elem);
    void push_back(int elem);
    int pop_front();
    int pop_back();
    bool IsEmpty();
private:
    int* buffer;
    int last;
    int first;
    int realsize;
    int buffersize;
    void grow();
};

CDequeue::CDequeue():
    buffer(0),
    last(0),
    first(0),
    realsize(0),
    buffersize(0)
{}

bool CDequeue::IsEmpty()
{
    if (realsize == 0) return true;
    else return false;
}
void CDequeue::push_front(int elem)
{
    if (realsize == buffersize) {
        grow();
    }
    if (first > 0) {
        buffer[--first] = elem;
    } else {
        first = buffersize - 1;
        buffer[first] = elem;
    }
    realsize++;
}

int CDequeue::pop_front()
{
    int result = 0;

    if (IsEmpty()) {
        return -1;
    }
    result = buffer[first++];
    if (first == buffersize) {
        first = 0;
    }
    realsize--;
    return result;
}

void CDequeue::push_back(int elem)
{
    if (realsize == buffersize) {
        grow();
    }
    if (last == buffersize) {
        last = 0;
    }
    buffer[last++] = elem;
    realsize++;
}

int CDequeue::pop_back()
{
    int result = 0;
    if (IsEmpty()) {
        return -1;
    }
    if (last == 0) {
        last = buffersize;
    }
    result = buffer[--last];
    realsize--;
    return result;
}

void CDequeue::grow()
{
    int newbuffersize = max( buffersize * 2, 1 );
    int *newbuffer = new int[newbuffersize];
    if (!IsEmpty()) {
        memcpy(newbuffer, buffer + first, (realsize - first) * sizeof(int));
        memcpy(newbuffer + realsize - first, buffer, first * sizeof(int));
        last = realsize;
        first = 0;
    }
    delete[] buffer;
    buffer = newbuffer;
    buffersize = newbuffersize;
}
int main()
{
    int element = 0;
    int number_comand = 0;
    int key = 0;
    cin >> number_comand;
    CDequeue dq;

    for (int i = 0; i < number_comand; i++) {
       cin >> key >> element;
        switch(key)
        {
            case 1: dq.push_front(element);
                    break;
            case 2: if (dq.pop_front() != element){
                        cout << "NO";
                        return 0;
                    }
                    break;
            case 3: dq.push_back(element);
                    break;
            case 4: if (dq.pop_back() != element) {
                        cout << "NO";
                        return 0;
                    }
                    break;
        }
    }
    cout << "YES";
    return 0;
}
