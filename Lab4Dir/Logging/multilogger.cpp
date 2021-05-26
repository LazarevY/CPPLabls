#include "multilogger.h"

MultiLogger::MultiLogger()
{

}

void MultiLogger::log(const QString &msg, Logger::LogMessageType type)
{
    if (auto v = m_loggersMap.value(type, nullptr))
        v->log(msg, type);
}

void MultiLogger::subscribeLogger(Logger::LogMessageType type, Logger *logger)
{
   m_loggersMap[type] = logger;
}
