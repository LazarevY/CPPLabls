#include "AssociativeArray/hashtable.h"
#include <iostream>
template<>
inline int hashOf<int>(const int & key){
    int x = key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

int main(int argc, char *argv[])
{

    HashTable<int, char> map;
    map.insert(1, 'e');
    map.insert(2, 't');

    std::cout << map.value(1) << std::endl;
    std::cout << map.value(2) << std::endl;
}

