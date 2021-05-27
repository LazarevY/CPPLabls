#ifndef APPEXCEPTION_H
#define APPEXCEPTION_H

#include <exception>
#include <QString>

class AppException : public std::exception
{
public:
    AppException(const QString &message = "");

    const char *what() const noexcept override;
private:
    QString m_message;

};

#endif // APPEXCEPTION_H
