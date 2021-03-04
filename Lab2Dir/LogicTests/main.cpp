#include <QCoreApplication>

#include "logictests.h"

int main(int argc, char *argv[])
{
    LogicTests tests;

    QTest::qExec(&tests, QStringList() << "" << "-silent");
}
