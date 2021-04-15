#ifndef HASHTABLECLI_H
#define HASHTABLECLI_H

#include <QString>
#include <QDebug>
#include "AssociativeArray/hashtable.h"
#include "CLIUtils/cliutils.h"


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
    void removeValueKey();

    void viewAllStrings();
    void viewAllInts();

private:
    HashTable<QString, int> m_stringMap;
    HashTable<int, QString> m_intMap;
};

#endif // HASHTABLECLI_H
