#ifndef LOGICTESTS_H
#define LOGICTESTS_H

#include <QTest>

class LogicTests : public QObject
{
    Q_OBJECT
public:
    explicit LogicTests(QObject *parent = nullptr);

private slots:
    void testObjectAdd000();
    void testObjectAdd001();

};

#endif // LOGICTESTS_H
