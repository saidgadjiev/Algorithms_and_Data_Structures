/*Реализуйте структуру данных типа “множество строк” на основе динамической хеш-таблицы с открытой адресацией. Хранимые строки непустые и состоят из строчных латинских букв. Начальный размер таблицы должен быть равным 8-ми. Перехеширование выполняйте в случае, когда коэффициент заполнения таблицы достигает 3/4.
 Структура данных должна поддерживать операции добавления строки в множество, удаления строки из множества и проверки принадлежности данной строки множеству.  Для разрешения коллизий используйте двойное хеширование.
 Формат входных данных
 Каждая строка входных данных задает одну операцию над множеством. Запись операции состоит из типа операции и следующей за ним через пробел строки, над которой проводится операция.
 Тип операции  – один из трех символов:
 +  означает добавление данной строки в множество;
 -  означает удаление  строки из множества;
 ?  означает проверку принадлежности данной строки множеству.
 При добавлении элемента в множество НЕ ГАРАНТИРУЕТСЯ, что он отсутствует в этом множестве. При удалении элемента из множества НЕ ГАРАНТИРУЕТСЯ, что он присутствует в этом множестве.
 Формат выходных данных
 Программа должна вывести для каждой операции одну из двух строк OK или FAIL, в зависимости от того, встречается ли данное слово в нашем множестве.*/
/*insert T(n) = O(1) best T(n) = O(n) - bad
 remove T(n) = O(1) best T(n) = O(n) - bad*/

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

int HashOne(const std::string &str, int m ) {
    int result = 0;
    
    for (int i = 0; i < static_cast<int>(str.length()); ++i) {
        result = (result * HashParamA + str[i]) % m;
    }
    
    return result;
}

int HashTwo( const std::string &str, int m ) {
    int result = 0;
    
    for (int i = 0; i < static_cast<int>(str.length()); ++i) {
        result = (result * (HashParamA - 1) + str[i]) % m;
    }
    
    return result + 1;
}

class Entry {
public:
    Entry() : condition(EMPTY) {}
    void setValue(std::string value) { this->value = value; }
    std::string getValue() { return this->value; }
    void setCondition(int condition) { this->condition = condition; }
    int getCondition() { return this->condition; }
private:
    std::string value;
    int condition;
};

class HashMap {
public:
    HashMap();
    ~HashMap();
    bool has(std::string value);
    bool put(std::string value);
    bool remove(std::string value);
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

bool HashMap::has(std::string value)
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

bool HashMap::put(std::string value)
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

bool HashMap::remove(std::string value)
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
    std::string data;
    while( std::cin >> command >> data ) {
        switch( command ) {
            case '+':
                std::cout << ( hashTable.put( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '-':
                std::cout << ( hashTable.remove( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            case '?':
                std::cout << ( hashTable.has( data ) ? "OK" : "FAIL" ) << std::endl;
                break;
            default:
                assert( false );
        }
    }
    return 0;
}
