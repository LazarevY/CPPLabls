#include "datawriting.h"
#include <QTextStream>
#include "appexception.h"

void DataWriting::writeToFile(const QString &fileName, const QVector<QString> &v)
{
    QFile file(fileName);

    if (!file.open(QIODevice::WriteOnly)){
        throw AppException(QString("Can't open ") + fileName);;
    }

    QTextStream o(&file);

    for (auto str: v)
        o << str << "\n";
    file.close();
}

