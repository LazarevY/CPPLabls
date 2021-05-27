#include <iostream>
#include <QHash>
#include <QApplication>

#include "GUI/mainwindow.h"
#include "Utils/dataparsing.h"

#include "Logging/consolelogger.h"
#include "Logging/guilogger.h"
#include "Logging/multilogger.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;


    ConsoleLogger consoleLogger;

    GUILogger guiLogger(w.getContexForGuoLogger());

    MultiLogger mainLogger;
    mainLogger.addLogger(&consoleLogger);
    mainLogger.addLogger(&guiLogger);

    w.setLogger(&mainLogger);

    w.show();

    return  a.exec();



}

