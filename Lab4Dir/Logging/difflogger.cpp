#include "difflogger.h"

DiffLogger::DiffLogger()
{

}

void DiffLogger::log(const QString &msg, Logger::LogMessageType type)
{
    if (auto v = m_loggersMap.value(type, nullptr))
        v->log(msg, type);
}

void DiffLogger::subscribeLogger(Logger::LogMessageType type, Logger *logger)
{
   m_loggersMap[type] = logger;
}
