#include "filelogger.h"
#include <QDateTime>

FileLogger::FileLogger(const QString &file) : Logger(), m_file(file)
{
    m_file.open(QIODevice::WriteOnly);
}

FileLogger::~FileLogger()
{
    m_file.close();
}

void FileLogger::setLogMessageTypeEnabled(Logger::LogMessageType type, bool enabled)
{
    m_typesMap[type] = enabled;
}


void FileLogger::log(const QString &msg, Logger::LogMessageType type)
{
    if (m_typesMap.value(type, false))
        m_file.write(QString("(%1)[%2]: %3\n").arg(QDateTime::currentDateTime().toString(DATA_FORMAT))
                     .arg(QMetaEnum::fromType<Logger::LogMessageType>().valueToKey(type)).arg(msg).toStdString().data());
}
