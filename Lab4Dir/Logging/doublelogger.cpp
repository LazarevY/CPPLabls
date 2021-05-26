#include "doublelogger.h"

DoubleLogger::DoubleLogger(Logger *fisrt,
        Logger *second) :
    Logger(),
    m_first(fisrt),
    m_second(second)
{

}


void DoubleLogger::log(const QString &msg, Logger::LogMessageType type)
{
    if (m_first)
        m_first->log(msg, type);
    if(m_second)
        m_second->log(msg, type);
}

Logger *DoubleLogger::first()
{
    return m_first;
}

void DoubleLogger::setFirst(Logger *first)
{
    m_first = first;
}

Logger *DoubleLogger::second()
{
    return m_second;
}

void DoubleLogger::setSecond(Logger *second)
{
    m_second = second;
}
