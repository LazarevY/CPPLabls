#include "mocklogger.h"

MockLogger MockLogger::m_instance = MockLogger();

MockLogger::MockLogger()
{

}


void MockLogger::log(const QString &, Logger::LogMessageType)
{
}

MockLogger &MockLogger::instance()
{
    return m_instance;
}
