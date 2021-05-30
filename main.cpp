#include <iostream>
#include <QHash>
#include <QApplication>

#include "GUI/mainwindow.h"
#include "Utils/dataparsing.h"

#include "Logging/consolelogger.h"
#include "Logging/guilogger.h"
#include "Logging/filelogger.h"
#include "Logging/multilogger.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    Logic l;

    MultiLogger mainLogger;
    l.setLogger(&mainLogger);

    ConsoleLogger consoleLogger;
    mainLogger.addLogger(&consoleLogger);

    FileLogger fileLogger(QString("logs/log_%1.log").arg(QDateTime::currentDateTime().toString("dd_MM_yy_hh_mm_ss")));
    mainLogger.addLogger(&fileLogger);

    MainWindow w(l);
    GUILogger guiLogger(w.getContexForGuoLogger());
    mainLogger.addLogger(&guiLogger);



    w.setLogger(&mainLogger);
    w.show();

    return  a.exec();



}

