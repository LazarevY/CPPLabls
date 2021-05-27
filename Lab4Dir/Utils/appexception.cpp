#include "appexception.h"

AppException::AppException(const QString &message): m_message(message)
{

}

const char *AppException::what() const noexcept
{
    return m_message.toStdString().data();
}
