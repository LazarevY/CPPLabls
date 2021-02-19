#ifndef LAB1TESTS_H
#define LAB1TESTS_H

#include <QObject>
#include <QTest>

class Lab1Tests : public QObject
{
    Q_OBJECT
public:
    explicit Lab1Tests(QObject *parent = nullptr);

signals:
private slots:
    void test001();
    void test002();
    void test003();
    void test004();
    void test005();
    void test006();
    void test007();
private:

};

#endif // LAB1TESTS_H
