#ifndef HASH_CHAINING_HPP
#define HASH_CHAINING_HPP

#include <array>
#include <list>
#include <algorithm>
#include <iostream>

namespace hash
{

struct HashElement
{
    char key;
    int value;
};

struct HashChainingTable
{
    std::array<std::list<HashElement>, 100> bucket;
};

int hash(HashChainingTable &table, char key)
{
    return key % table.bucket.size();
}

HashChainingTable create()
{
    HashChainingTable newTable;
    return newTable;
}

bool isEmpty(HashChainingTable &table)
{
    for (int i = 0; i < table.bucket.size(); ++i)
        if (!table.bucket[i].empty())
            return false;
    return true;
}

int size(HashChainingTable &table)
{
    int mSize = 0;
    for (int i = 0; i < table.bucket.size(); ++i)
        mSize += table.bucket[i].size();
    return mSize;
}

bool find(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (HashElement &element : slot)
        if (element.key == key)
            return true;
    return false;
}

int &at(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (HashElement &element : slot)
        if (element.key == key)
            return element.value;

    std::cout << "Key not found!" << std::endl;
    exit(1);
}

void insert(HashChainingTable &table, char key, int value)
{
    if (!find(table, key))
    {
        HashElement newElement{key, value};
        int index = hash(table, key);
        std::list<HashElement> &slot = table.bucket[index];
        slot.push_back(newElement);
    }
}

void remove(HashChainingTable &table, char key)
{
    int index = hash(table, key);
    std::list<HashElement> &slot = table.bucket[index];
    for (auto it = slot.begin(); it != slot.end(); ++it)
        if (it->key == key)
            slot.erase(it);
}

int &value(HashChainingTable &table, char key)
{
    if (!find(table, key))
    {
        insert(table, key , 0 );
    }
    return at(table, key);
}

void clear(HashChainingTable &table)
{
    for (auto &slot : table.bucket)
        slot.clear();
}

void printAll(HashChainingTable &table)
{
    for (auto &slot : table.bucket)
        for (auto &element : slot)
            std::cout << element.key << ":" << element.value << std::endl;
}
}

#endif