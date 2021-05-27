#include "multilogger.h"

MultiLogger::MultiLogger()
{

}

void MultiLogger::log(const QString &msg, Logger::LogMessageType type)
{
    for (auto l: m_loggers)
        if (l)
            l->log(msg, type);
}

void MultiLogger::addLogger(Logger *l)
{
    m_loggers.insert(l);
}

void MultiLogger::removeLogger(Logger *l)
{
    m_loggers.remove(l);
}
