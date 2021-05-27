#ifndef DATAWRITING_H
#define DATAWRITING_H

#include <QFile>
#include <QString>
#include <QVector>

namespace DataWriting
{
    void writeToFile(const QString &fileName, const QVector<QString> &v);
};

#endif // DATAWRITING_H
