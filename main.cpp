#include <iostream>
#include <QHash>
#include "AssociativeArray/hashtable.h"
#include "hashtablecli.h"

int main(int argc, char *argv[])
{

    HashTableCLI cli;
    cli.run();
    return 0;
//    HashTable<int, char> map;
//    map[1] =  '1';
//    map[2] =  '2';

//    for (auto it = map.begin(); it != map.end(); ++it)
//        std::cout << "Key - " << it.key() << " value - " << it.value() << std::endl;

//    std::cout << std::endl;
//    map[3] =  '3';
//    map[4] =  '4';

//    for (auto it = map.begin(); it != map.end(); ++it)
//        std::cout << "Key - " << it.key() << " value - " << it.value() << std::endl;

//    std::cout << std::endl;
//    map[5] =  '5';

//    std::cout << map[1] << std::endl;
//    std::cout << map[2] << std::endl;
//    std::cout << map[3] << std::endl;
//    std::cout << map[4] << std::endl;
//    std::cout << map[5] << std::endl;

//    map.remove(2);
//    std::cout << std::endl;
//    map[2] = 'a';

//    std::cout << map[1] << std::endl;
//    std::cout << map[2] << std::endl;
//    std::cout << map[3] << std::endl;
//    std::cout << map[4] << std::endl;
//    std::cout << map[5] << std::endl;

//    std::cout << map.contains(1) << std::endl;
//    std::cout << map.contains(2) << std::endl;
//    std::cout << map.contains(3) << std::endl;
//    std::cout << map.contains(4) << std::endl;
//    std::cout << map.contains(5) << std::endl;
//    std::cout << map.contains(6) << std::endl;
//    std::cout << map.contains(1000) << std::endl;

//    std::cout << std::endl;

//    for (auto it = map.begin(); it != map.end(); ++it)
//        std::cout << "Key - " << it.key() << " value - " << it.value() << std::endl;

}

