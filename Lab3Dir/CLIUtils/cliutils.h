#ifndef CLIUTILS_H
#define CLIUTILS_H

#include <QString>
#include <iostream>
#include <string>

inline std::ostream &operator<<(std::ostream &o, const QString &str){
    o << str.toStdString();
    return o;
}

namespace CLIUtils {

int getIntFromConsole(const QString &msg);

int getBoundedFromConsole(int min, int max, const QString &msg);

QString getStringFromConsole(const QString &msg);



}
#endif // CLIUTILS_H
