#include <iostream>
#include <string>
#include "Lab1/lab1tests.h"
#include <string.h>
#include "Lab1/mysnprintf.h"
#include "Lab1/laboneinterface.h"

/**
 * @author Yaroslav Lazarev, group 4.2
 * @task description: implemet function "snprintf"
 * @function desc
 * Write formatted output to sized buffer
    Composes a string with the same text that would be printed if format was used on printf,
    but instead of being printed, the content is stored as a C string
    in the buffer pointed by s (taking n as the maximum buffer capacity to fill).

 *features:
 * If the resulting string would be longer than n-1 characters,
 * the remaining characters are discarded and not stored, but counted for the value returned by the function.
 *
 * return The number of characters that would have been written if n had been sufficiently large,
 * not counting the terminating null character.
 * If an encoding error occurs, a negative number is returned.
 *
 * @note from http://www.cplusplus.com/reference/cstdio/snprintf/
 */



void runTests(){

    Lab1Tests tests;

    QTest::qExec(&tests, QStringList() << "" << "-silent");
}

int main(int argc, char *argv[])
{
    runTests();

    std::cout << std::endl;

    LabOneInterface inc;

    inc.runDemo();


    return 0;
}
