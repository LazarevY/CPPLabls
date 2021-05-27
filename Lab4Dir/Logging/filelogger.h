#ifndef FILELOGGER_H
#define FILELOGGER_H
#include <QString>
#include <QFile>
#include <QMap>

#include "Logging/logger.h"

class FileLogger : public Logger
{
public:
    FileLogger(const QString &file);
    ~FileLogger();
    void setLogMessageTypeEnabled(LogMessageType type, bool enabled);

    // Logger interface
public:
    void log(const QString &msg, LogMessageType type) override;
private:
    QFile m_file;
    QString m_fileName;
    QMap<Logger::LogMessageType, bool> m_typesMap;
    const QString DATA_FORMAT = "dd.MM.yy hh:mm:ss";
};

#endif // FILELOGGER_H
