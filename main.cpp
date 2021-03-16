#include "Functions/maptablefunctionimpl.h"
#include <iostream>
#include "Objects/harvest.h"
#include "Objects/mole.h"
#include "Logic/logic.h"
#include "Render/fieldrenderimpl.h"
#include "Functions/maptablefunctionimpl.h"
#include <QThread>
#include "ObjectsHandlers/cottagerhandler.h"
#include "ObjectsHandlers/harvestremovehandler.h"
#include "ObjectsHandlers/molehanlder.h"
#include "UI/uiimpl.h"

void logicInit(Logic &logic);


int main(int argc, char *argv[])
{




    Logic logic(nullptr);

    MapTableFunctionImpl<int, int> *func  =  new MapTableFunctionImpl<int, int>();

    func->setDefaultFuction([](const int& v){if (v < 0) return 0; else if(3 > 4) return 100; });
    func->setValueFor(1, 5);
    func->setValueFor(2, 30);
    func->setValueFor(3, 70);

    auto mH = new MoleHanlder(&logic);
    mH->setChiildChangeStateFunc(func);
    mH->setOngroundChangeStateFunc(func);
    mH->setUndegroundChangeStateFunc(func);
    logic.registerHandler(mH);

    auto cH = new CottagerHandler(&logic);
    logic.registerHandler(cH);

    auto hrH = new HarvestRemoveHandler(&logic);
    logic.registerRemoveHandler(hrH);

    MapTableFunctionImpl<char, int> charMap([](int){return 'M';});
    charMap.setValueFor(0, '-');
    charMap.setValueFor(1, 'C');
    charMap.setValueFor(4, 'M');
    charMap.setValueFor(6, 'm');
    charMap.setValueFor(12, 'X');
    charMap.setValueFor(20, 'Y');
    charMap.setValueFor(64, 'M');
    charMap.setValueFor(32, 'H');

    FieldRenderImpl render(&charMap);
    UIImpl ui(&logic, &render);
    ui.show();

    return 0;


    Field field = Field(16, 16);
    Cottager cottager(2, IntegerVector(0, 0), IntegerVector(1,0), 2);
    Mole mole = Mole(2, IntegerVector(1,1), IntegerVector(1,0), Mole::Gender::Male, false, 2);
    Mole mole1 = Mole(2, IntegerVector(2,5), IntegerVector(1,0), Mole::Gender::Female, false, 2);
    Mole mole2 = Mole(2, IntegerVector(10,4), IntegerVector(1,0), Mole::Gender::Male, true, 2);
    Mole mole3 = Mole(2, IntegerVector(12,13), IntegerVector(1,0), Mole::Gender::Male, false, 2);
    mole.setState(Mole::State::OnGround);
    Mole mole4 = Mole(2, IntegerVector(4, 4), IntegerVector(1,0), Mole::Gender::Male, false, 2);

    logic.addObject(&mole);
    logic.addObject(&mole1);
    logic.addObject(&mole2);
    logic.addObject(&mole3);
    logic.addObject(&mole4);
    logic.addObject(&cottager);

    for (int x = 0; x < 7; ++x)
        logic.addObject(new Harvest(IntegerVector(x, 2)), true);



    int counter = 0;
    render.renderField(logic.getField());
    logic.startGame();

    while(!logic.isGameOver()){
        QThread::msleep(200);
        logic.update();
        render.renderField(logic.getField());

        std::cout << "steps: " << counter++ << std::endl;
        std::cout << "moles: " <<  logic.getAll<Mole>().size() << std::endl;
        std::cout << "harvest: " <<  logic.getHarvestCount() << std::endl;
        std::cout << "game status: " <<  logic.isGameOver() << std::endl;
    }

    return 0;
}

void logicInit(Logic &logic){

    MapTableFunctionImpl<int, int> *func  =  new MapTableFunctionImpl<int, int>();

    func->setDefaultFuction([](const int& v){if (v < 0) return 0; else if(3 > 4) return 100; });
    func->setValueFor(1, 5);
    func->setValueFor(2, 30);
    func->setValueFor(3, 70);

    auto mH = new MoleHanlder(&logic);
    mH->setChiildChangeStateFunc(func);
    mH->setOngroundChangeStateFunc(func);
    mH->setUndegroundChangeStateFunc(func);
    logic.registerHandler(mH);

    auto cH = new CottagerHandler(&logic);
    logic.registerHandler(cH);

    auto hrH = new HarvestRemoveHandler(&logic);
    logic.registerRemoveHandler(hrH);
}
