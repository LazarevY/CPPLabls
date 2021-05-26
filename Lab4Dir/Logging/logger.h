#ifndef LOGGER_H
#define LOGGER_H

#include <QString>
#include <QMetaEnum>

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger();
    enum LogMessageType {
        FAIL, OK, WARNING, INFO
    };
    Q_ENUM(LogMessageType);

    virtual ~Logger();

    virtual void log(const QString &msg, LogMessageType type);
};

#endif // LOGGER_H
