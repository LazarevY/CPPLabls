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
    map.insert(1, '1');
    map.insert(2, '2');
    map.insert(3, '3');
    map.insert(4, '4');
    map.insert(5, '5');
    map.insert(5, '6');

    std::cout << map.value(1) << std::endl;
    std::cout << map.value(2) << std::endl;
    std::cout << map.value(3) << std::endl;
    std::cout << map.value(4) << std::endl;
    std::cout << map.value(5) << std::endl;
    map.remove(2);
    std::cout << map.value(1) << std::endl;
    std::cout << map.value(5) << std::endl;
    std::cout << map.value(4) << std::endl;
    std::cout << map.value(3) << std::endl;

}

