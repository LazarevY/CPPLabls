#include "guilogger.h"
#include <QDateEdit>

GUILogger::GUILogger(QTextEdit *textArea) : Logger()
{
    connect(this, &GUILogger::logSignal, textArea, &QTextEdit::insertHtml);
}

GUILogger::~GUILogger()
{

}

void GUILogger::log(const QString &msg, LogMessageType type)
{
    QString message;
    if (type == LogMessageType::FAIL){
        message = QString("<div style=\"color:red;font-size:14px;\">(%1)[FAIL]:%2</div><br>").arg(QDateTime::currentDateTime().toString(DATA_FORMAT)).arg(msg);
    }
    else if (type == LogMessageType::WARNING){
        message = QString("<div style=\"color:orange;font-size:14px;\">(%1)[WARN]:%2</div><br>").arg(QDateTime::currentDateTime().toString(DATA_FORMAT)).arg(msg);
    }
    else if (type == LogMessageType::INFO){
        message = QString("<div style=\"color:#00BFFF;font-size:14px;\">(%1)[INFO]:%2</div><br>").arg(QDateTime::currentDateTime().toString(DATA_FORMAT)).arg(msg);
    }
    else if (type == LogMessageType::OK){
        message = QString("<div style=\"color:#228B22;font-size:14px;\">(%1)[OK]:%2</div><br>").arg(QDateTime::currentDateTime().toString(DATA_FORMAT)).arg(msg);
    }
    emit logSignal(message);
}
