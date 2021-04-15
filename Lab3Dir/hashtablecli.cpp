#include "hashtablecli.h"

HashTableCLI::HashTableCLI()
{

}

void HashTableCLI::run()
{

}

void HashTableCLI::addIntValue()
{
    QString str = CLIUtils::getStringFromConsole("Input string key: ");

    int value = CLIUtils::getIntFromConsole("Iput int value: ");

    m_stringMap[str] = value;
}

void HashTableCLI::addStringValue()
{
    int key = CLIUtils::getIntFromConsole("Input int key: ");
    QString str = CLIUtils::getStringFromConsole("Input string value: ");


    m_intMap[key] = str;
}

void HashTableCLI::getStringValue()
{
    int key = CLIUtils::getIntFromConsole("Input int key: ");
    if (m_intMap.contains(key)){
        qDebug().noquote() << QString("By string key '%1' founded value %2").arg(key).arg(m_intMap[key]);
    }
    else {
        qDebug().noquote() << QString("No founded by key '%1'").arg(key);
    }
}

void HashTableCLI::getIntValue()
{
    QString str = CLIUtils::getStringFromConsole("Input string key: ");
    if (m_stringMap.contains(str)){
        qDebug().noquote() << QString("By string key '%1' founded value %2").arg(str).arg(m_stringMap[str]);
    }
    else {
        qDebug().noquote() << QString("No founded by key '%1'").arg(str);
    }
}

void HashTableCLI::removeIntKey()
{
    int key = CLIUtils::getIntFromConsole("Input int key: ");
    m_intMap.remove(key);
}

void HashTableCLI::removeValueKey()
{
    QString str = CLIUtils::getStringFromConsole("Input string key: ");
    m_stringMap.remove(str);
}

void HashTableCLI::viewAllStrings()
{

}

void HashTableCLI::viewAllInts()
{

}
