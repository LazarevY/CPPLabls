#include "logger.h"

Logger::Logger() : QObject()
{

}

Logger::~Logger()
{

}

void Logger::log(const QString &msg, LogMessageType type)
{
    Q_UNUSED(msg);
}
