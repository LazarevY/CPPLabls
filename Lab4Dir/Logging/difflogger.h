#ifndef MULTILOGGER_H
#define MULTILOGGER_H

#include <QMap>
#include <QVector>
#include "logger.h"


class DiffLogger : public Logger
{
public:
    DiffLogger();
    void log(const QString &msg, LogMessageType type) override;
    void subscribeLogger(LogMessageType type, Logger *logger);

private:
    QMap<Logger::LogMessageType, Logger*> m_loggersMap;
};

#endif // MULTILOGGER_H
