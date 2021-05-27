#ifndef GUILOGGER_H
#define GUILOGGER_H

#include "logger.h"
#include <QtWidgets/QTextEdit>
#include <QString>

class GUILogger : public Logger
{
    Q_OBJECT
public:
    GUILogger(QTextEdit *textArea);
    ~GUILogger() override;
    void log(const QString &msg, LogMessageType type) override;
signals:
    void logSignal(const QString &msg);

private:
    const QString DATA_FORMAT = "dd.MM.yy hh:mm:ss";
};

#endif // GUILOGGER_H
