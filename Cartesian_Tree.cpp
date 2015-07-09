/*Дано число N < 106 и последовательность пар целых чисел из [-231..231] длиной N.
 Построить декартово дерево из N узлов, характеризующихся парами чисел {Xi, Yi}.
 Каждая пара чисел {Xi, Yi} определяет ключ Xi и приоритет Yi в декартовом дереве.*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <assert.h>
#define DEFAULT_TABLE_SIZE 8
#define HashParamA 37
#define EMPTY 0
#define BUSY 1
#define DELETED 2
using namespace std;

int HashOne( const string& s, int m ) {
    int result = 0;
    for ( int i = 0; i < static_cast<int>( s.length() ); ++i ) {
        result = ( result * HashParamA + s[i] ) % m;
    }
    return result;
}

int HashTwo( const string& s, int m ) {
    int result = 0;
    for ( int i = 0; i < static_cast<int>( s.length() ); ++i ) {
        result = ( result * (HashParamA - 1) + s[i] ) % m;
    }

    return result + 1;
}

class Entry {
public:
    Entry() : condition(EMPTY) {}
    void setValue(string value) { this->value = value; }
    string getValue() { return this->value; }
    void setCondition(int condition) { this->condition = condition; }
    int getCondition() { return this->condition; }
private:
    string value;
    int condition;
};

class HashMap {
public:
    HashMap();
    ~HashMap();
    bool has(string value);
    bool put(string value);
    bool remove(string value);
private:
    float threshold;
    int maxSize;
    int tableSize;
    int size;
    Entry **table;
    void resize();
};

HashMap::HashMap()
{
    threshold = 0.75f;
    tableSize = DEFAULT_TABLE_SIZE;
    maxSize = threshold * tableSize;
    table = new Entry*[tableSize];
    size = 0;
    for (int i = 0; i < tableSize; i++) {
        table[i] = new Entry();
    }
}

void HashMap::resize() {
    int oldTableSize = tableSize;
    tableSize *= 2;
    maxSize = (int) (tableSize * threshold);
    Entry **oldTable = table;
    table = new Entry*[tableSize];

    for (int i = 0; i < tableSize; i++) {
        table[i] = new Entry();
    }
    size = 0;
    for (int hash = 0; hash < oldTableSize; hash++) {
        if (oldTable[hash]->getCondition() == BUSY) {
            put(oldTable[hash]->getValue());
            delete oldTable[hash];
        }
    }
    delete [] oldTable;
}

bool HashMap::has(string value)
{
    int hash1 = HashOne(value, tableSize);
    int hash2 = HashTwo(value, tableSize);

    for (int i = 0 ; i < tableSize; i++) {
        int hash = (hash1 + i * hash2) % tableSize;
        if (table[hash]->getCondition() == EMPTY) {
            return false;
        }
        if (table[hash]->getValue() == value && table[hash]->getCondition() == BUSY) {
            return true;
        }
    }
    return false;
}

bool HashMap::put(string value)
{
    if (size >= maxSize) {
        resize();
    }
    int hash1 = HashOne(value, tableSize);
    int hash2 = HashTwo(value, tableSize);

    for (int i = 0 ; i < tableSize; i++) {
        int hash = (hash1 + i * hash2) % tableSize;
        if (table[hash]->getCondition() != BUSY) {
            table[hash]->setValue(value);
            table[hash]->setCondition(BUSY);
            size++;
            return true;
        }
        if (table[hash]->getValue() == value) {
            return false;
        }
    }
    return true;
}

bool HashMap::remove(string value)
{
    int hash1 = HashOne(value, tableSize);
    int hash2 = HashTwo(value, tableSize);

    for (int i = 0 ; i < tableSize; i++) {
        int hash = (hash1 + i * hash2) % tableSize;
        if (table[hash]->getCondition() == EMPTY) {
            return false;
        }
        if (table[hash]->getValue() == value && table[hash]->getCondition() == BUSY) {
            table[hash]->setCondition(DELETED);
            return true;
        }
    }
    return false;
}

HashMap::~HashMap()
{
    for (int hash = 0; hash < tableSize; hash++) {
        delete table[hash];
    }
    delete[] table;
}

int main()
{
    HashMap hashTable;
    char command = 0;
    string data;
    while( cin >> command >> data ) {
        switch( command ) {
            case '+':
                cout << ( hashTable.put( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '-':
                cout << ( hashTable.remove( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '?':
                cout << ( hashTable.has( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            default:
                assert( false );
        }
    }
    return 0;
}
