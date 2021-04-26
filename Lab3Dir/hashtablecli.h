#ifndef HASHTABLECLI_H
#define HASHTABLECLI_H

#include <QString>
#include <QDebug>
#include "AssociativeArray/hashtable.h"
#include "CLIUtils/cliutils.h"

template<>
inline int hashOf<int>(const int & key){
    unsigned x = key;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
}

template<>
inline int hashOf<QString>(const QString & key){
    unsigned hash = 5381;

    for (auto it :key.toStdString())
        hash = ((hash << 5) + hash) + (uchar)it; /* hash * 33 + c */

    return hash;
}


class HashTableCLI
{
public:
    HashTableCLI();

    void run();

    void addIntValue();
    void addStringValue();

    void getStringValue();
    void getIntValue();

    void removeIntKey();
    void removeStringKey();

    void viewAllStrings();
    void viewAllInts();

    void showMenu();

private:
    HashTable<QString, int> m_stringMap;
    HashTable<int, QString> m_intMap;
    int m_menuCode = 1;
};

#endif // HASHTABLECLI_H
