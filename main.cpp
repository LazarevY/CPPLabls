#include <iostream>
#include <string>
#include "Lab1/lab1tests.h"
#include <string.h>
#include "Lab1/mysnprintf.h"

int main(int argc, char *argv[])
{

    Lab1Tests tests;

    QTest::qExec(&tests, QStringList() << "" << "-silent");


    return 0;
}
