#include "logictests.h"
#include "Logic/logic.h"
#include "Objects/mole.h"
#include "Objects/cottager.h"

LogicTests::LogicTests(QObject *parent) : QObject(parent)
{

}

void LogicTests::testObjectAdd000()
{
    Field field = Field(3,3);
    Mole mole = Mole(2, IntegerVector(1,1), IntegerVector(1,0), Mole::Gender::Male, false, 2);
    Logic logic(&field);

    logic.addObject(&mole);

    QVector<Mole *> all = logic.getAll<Mole>();
    QVector<Mole *> fromCell = logic.getAllObjectsInCell<Mole>(IntegerVector(1,1));

    QVERIFY(all.size() == fromCell.size());
    QVERIFY(all.size() == 1);
}

void LogicTests::testObjectAdd001()
{
    Field field = Field(3,3);
    Mole mole = Mole(2, IntegerVector(1,1), IntegerVector(1,0), Mole::Gender::Male, false, 2);
    Cottager cottager = Cottager(2, IntegerVector(2,2), IntegerVector(1,0), 3);
    Logic logic(&field);

    logic.addObject(&mole);
    logic.addObject(&cottager);

    QVector<Mole *> all = logic.getAll<Mole>();
    QVector<Cottager *> allC = logic.getAll<Cottager>();
    QVector<Mole *> fromCell = logic.getAllObjectsInCell<Mole>(IntegerVector(1,1));
    QVector<Cottager *> fromCellC = logic.getAllObjectsInCell<Cottager>(IntegerVector(2,2));

    QVERIFY(all.size() == fromCell.size());
    QVERIFY(allC.size() == fromCellC.size());
    QVERIFY(all.size() == 1);
    QVERIFY(all.size() == allC.size());
}
