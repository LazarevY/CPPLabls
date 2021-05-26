#include "consolelogger.h"
#include <QDebug>

ConsoleLogger::ConsoleLogger()
{

}

void ConsoleLogger::log(const QString &msg, LogMessageType type)
{
    qDebug().noquote() << QString("[%1]:").arg(QMetaEnum::fromType<Logger::LogMessageType>().valueToKey(type))
             << msg;
}
