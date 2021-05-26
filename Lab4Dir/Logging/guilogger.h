#ifndef GUILOGGER_H
#define GUILOGGER_H

#include "logger.h"
#include <QtWidgets/QTextEdit>


class GUILogger : public Logger
{
    Q_OBJECT
public:
    GUILogger(QTextEdit *textArea);
    ~GUILogger() override;
    void log(const QString &msg, LogMessageType type) override;
signals:
    void logSignal(const QString &msg);
};

#endif // GUILOGGER_H
