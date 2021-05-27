#ifndef MULTILOGGER_H
#define MULTILOGGER_H

#include "logger.h"

#include <QSet>

class MultiLogger: public Logger
{
public:
    MultiLogger();

    void log(const QString &msg, LogMessageType type) override;

    void addLogger(Logger *l);
    void removeLogger(Logger *l);

private:
    QSet<Logger *> m_loggers;


};

#endif // MULTILOGGER_H
