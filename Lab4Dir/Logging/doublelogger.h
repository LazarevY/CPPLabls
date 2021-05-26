#ifndef DOUBLELOGGER_H
#define DOUBLELOGGER_H

#include "Logging/logger.h"
#include "mocklogger.h"

class DoubleLogger : public Logger
{
public:
    DoubleLogger(Logger *fisrt = &MockLogger::instance(), Logger *second = &MockLogger::instance());

    // Logger interface
public:
    void log(const QString &msg, LogMessageType type) override;
    Logger *first();
    void setFirst(Logger *first);

    Logger *second();
    void setSecond(Logger *second);

private:
    Logger *m_first;
    Logger *m_second;
};

#endif // DOUBLELOGGER_H
