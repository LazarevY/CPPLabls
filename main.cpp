#include <iostream>
#include <QHash>
#include <QApplication>

#include "GUI/mainwindow.h"
#include "Utils/dataparsing.h"

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w;

    w.show();

    return  a.exec();



}

