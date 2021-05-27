#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H

#include "logger.h"

class ConsoleLogger : public Logger
{
public:
    ConsoleLogger();

    void log(const QString &msg, LogMessageType type) override;
private:
    const QString DATA_FORMAT = "dd.MM.yy hh:mm:ss";
};

#endif // CONSOLELOGGER_H
