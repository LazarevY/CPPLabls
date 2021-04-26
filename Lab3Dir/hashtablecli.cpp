#include "hashtablecli.h"

HashTableCLI::HashTableCLI()
{

}

void HashTableCLI::run()
{
    while (m_menuCode){
        showMenu();
    }
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
        qDebug().noquote() << QString("By int key '%1' founded value '%2'").arg(key).arg(m_intMap[key]);
    }
    else {
        qDebug().noquote() << QString("No founded by key '%1'").arg(key);
    }
}

void HashTableCLI::getIntValue()
{
    QString str = CLIUtils::getStringFromConsole("Input string key: ");
    if (m_stringMap.contains(str)){
        qDebug().noquote() << QString("By string key '%1' founded value '%2'").arg(str).arg(m_stringMap[str]);
    }
    else {
        qDebug().noquote() << QString("No founded by key '%1'").arg(str);
    }
}

void HashTableCLI::removeIntKey()
{
    int key = CLIUtils::getIntFromConsole("Input int key: ");
    m_intMap.remove(key);
    qDebug().noquote() << QString("Passed");
}

void HashTableCLI::removeStringKey()
{
    QString str = CLIUtils::getStringFromConsole("Input string key: ");
    m_stringMap.remove(str);
    qDebug().noquote() << QString("Passed");
}

void HashTableCLI::viewAllStrings()
{
    qDebug().noquote() << QString("Map <int, string> contains next items:");
    for (auto it = m_intMap.begin(); it != m_intMap.end(); ++it)
        std::cout << "Key - " << it.key() << " value - " << it.value() << std::endl;
    qDebug() << "";
    qDebug().noquote() << QString("End of map");
}

void HashTableCLI::viewAllInts()
{
    qDebug().noquote() << QString("Map <string, int> contains next items:");
    for (auto it = m_stringMap.begin(); it != m_stringMap.end(); ++it)
        std::cout << "Key - " << it.key() << " value - " << it.value() << std::endl;
    qDebug() << "";
    qDebug().noquote() << QString("End of map");
}

void HashTableCLI::showMenu()
{
    qDebug() << "";
    m_menuCode = CLIUtils::getBoundedFromConsole(0, 8, "Enter action code\n"
                                                       "0. Exit\n"
                                                       "1. Add int, string pair\n"
                                                       "2. Add string, int pair\n"
                                                       "3. Remove int, string pair\n"
                                                       "4. Remove string, int pair\n"
                                                       "5. Get string by int key\n"
                                                       "6. Get int by string key\n"
                                                       "7. Show int, string map\n"
                                                       "8. Show string, int map\n"
                                                       "Code: ");
    qDebug() << "";

    switch (m_menuCode) {
    case 0:
        return;
    case 1:
        addStringValue();
        break;
    case 2:
        addIntValue();
        break;
    case 3:
        removeIntKey();
        break;
    case 4:
        removeStringKey();
        break;
    case 5:
        getStringValue();
        break;
    case 6:
        getIntValue();
        break;
    case 7:
        viewAllStrings();
        break;
    case 8:
        viewAllInts();
        break;
    }

}
