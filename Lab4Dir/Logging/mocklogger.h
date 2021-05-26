#ifndef MOCKLOGGER_H
#define MOCKLOGGER_H

#include "Logging/logger.h"

class MockLogger : public Logger
{
public:
    MockLogger();

    // Logger interface
public:
    void log(const QString &msg, LogMessageType type) override;
    static MockLogger &instance();

private:
    static MockLogger m_instance;
};

#endif // MOCKLOGGER_H
