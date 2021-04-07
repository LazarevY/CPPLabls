#include "AssociativeArray/hashtable.h"
#include <iostream>
#include <QHash>
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
    map[1] =  '1';
    map[2] =  '2';
    map[3] =  '3';
    map[4] =  '4';
    map[5] =  '5';

    std::cout << map[1] << std::endl;
    std::cout << map[2] << std::endl;
    std::cout << map[3] << std::endl;
    std::cout << map[4] << std::endl;
    std::cout << map[5] << std::endl;

    map.remove(2);
    std::cout << std::endl;
    map[2] = 'a';

    std::cout << map[1] << std::endl;
    std::cout << map[2] << std::endl;
    std::cout << map[3] << std::endl;
    std::cout << map[4] << std::endl;
    std::cout << map[5] << std::endl;

    std::cout << map.contains(1) << std::endl;
    std::cout << map.contains(2) << std::endl;
    std::cout << map.contains(3) << std::endl;
    std::cout << map.contains(4) << std::endl;
    std::cout << map.contains(5) << std::endl;
    std::cout << map.contains(6) << std::endl;
    std::cout << map.contains(1000) << std::endl;

}

