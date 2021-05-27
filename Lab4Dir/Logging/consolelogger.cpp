#include "consolelogger.h"
#include <QDebug>
#include <QDateTime>

ConsoleLogger::ConsoleLogger()
{

}

void ConsoleLogger::log(const QString &msg, LogMessageType type)
{
    qDebug().noquote() << QString("(%1)[%2]:").arg(QDateTime::currentDateTime().toString(DATA_FORMAT))
                          .arg(QMetaEnum::fromType<Logger::LogMessageType>().valueToKey(type))
             << msg;
}
