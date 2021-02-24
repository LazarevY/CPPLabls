#include "lab1tests.h"
#include "mysnprintf.h"
#include <string.h>

Lab1Tests::Lab1Tests(QObject *parent) : QObject(parent)
{

}

void Lab1Tests::test001()
{
    const char *format = "Digit %d test";
    int len = strlen(format);
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format, 1);
    int stat2 = my_snprintf(current, len, format, 1);
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test002()
{
    const char *format = "%d texttttt %d";
    int len = 20;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format, 1, 2);
    int stat2 = my_snprintf(current, len, format, 1, 2);
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test003()
{
    const char *format = "Insert string %s";
    int len = 20;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format, "mystr");
    int stat2 = my_snprintf(current, len, format, "mystr");
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test004()
{
    const char *format = "%d%s";
    int len = 20;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format, 1, "str");
    int stat2 = my_snprintf(current, len, format, 1, "str");
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test005()
{
    const char *format = "Char test %c";
    int len = 20;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,'a');
    int stat2 = my_snprintf(current, len, format, 'a');
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test006()
{
    const char *format = "String: %s, char: %c, int: %d .";
    int len = 40;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,"hello", 'r', 200);
    int stat2 = my_snprintf(current, len, format, "hello", 'r', 200);
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY(stat1 == stat2);
}

void Lab1Tests::test007()
{
    const char *format = "String: %s, char: %c, int: %d .";
    int len = 10;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,"hello", 'r', 200);
    int stat2 = my_snprintf(current, len, format, "hello", 'r', 200);
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY2(stat1 == stat2, QString("%1 vs %2").arg(stat1).arg(stat2).toStdString().c_str());
}

void Lab1Tests::test008()
{
    const char *format = "String: %s";
    int len = 5;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,"1111111111111111111111111111111");
    int stat2 = my_snprintf(current, len, format, "1111111111111111111111111111111");
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY2(stat1 == stat2, QString("%1 vs %2").arg(stat1).arg(stat2).toStdString().c_str());
}

void Lab1Tests::test009()
{
    const char *format = "ww %k";
    int len = 5;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,"122");
    int stat2 = my_snprintf(current, len, format, "122");
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY2(stat1 == stat2, QString("%1 vs %2").arg(stat1).arg(stat2).toStdString().c_str());
}

void Lab1Tests::test010()
{
    const char *format = "ww %v";
    int len = 5;
    char current[50] = "";
    char expected[50] = "";
    int stat1 = snprintf(expected, len, format,"122");
    int stat2 = my_snprintf(current, len, format, "122");
    QVERIFY2(!strcmp(current, expected), expected);
    QVERIFY2(stat1 == stat2, QString("%1 vs %2").arg(stat1).arg(stat2).toStdString().c_str());
}

void Lab1Tests::test011()
{
    const char *format = "ww %v";
    int len = 5;
    int stat = my_snprintf(nullptr, len, format, "122");
    QVERIFY(stat < 0);
}

void Lab1Tests::test012()
{
    int len = 5;
    int stat = my_snprintf(nullptr, len, nullptr);
    QVERIFY(stat < 0);
}
