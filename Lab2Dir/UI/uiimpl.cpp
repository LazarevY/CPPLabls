#include "uiimpl.h"
#include <iostream>

UIImpl::UIImpl(Logic *logic, FieldRender *render) : m_logic(logic), m_render(render)
{

}


int UIImpl::show()
{

    initLogic();

    int counter = 0;
    m_logic->startGame();

    system("clear");


    while(!m_isExit){
        std::cout << "Steps: " << counter << std::endl;
        loopAction();
        counter++;
    }



    return 0;
}

void UIImpl::initLogic()
{
    std::cout << "Set field size, min is [3 x 3], max [50 x 50]" << std::endl;
    IntegerVector fieldSize(
                getBoundedFromConsole(3, 50, "Width: "),
                getBoundedFromConsole(3, 50, "Height: "));

    m_field = new Field(fieldSize.x(), fieldSize.y());

    m_logic->setField(m_field);

    Cottager *cottager = m_logic->createObject<Cottager>();
    std::cout << "Let's add cottager to field..." << std::endl;
    fill(*cottager);
    m_logic->moveObject(cottager, cottager->position());

    std::cout << "Let's add some harvest to field..." << std::endl;
    for (int i = 0; i < 2; ++i){
        Harvest *h = m_logic->createObject<Harvest>();
        fill(*h);
        m_logic->moveObject(h, h->position());
    }

    std::cout << "And finally add a mole..." << std::endl;
    Mole *m = m_logic->createObject<Mole>();
    fill(*m);



}

int UIImpl::getIntFromConsole(const QString &msg)
{
    int val;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << msg;
        std::cin >> val;
    }

    return val;
}

int UIImpl::getBoundedFromConsole(int min, int max, const QString &msg)
{
    int val = min;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail() || val < min || val > max) {
        std::cin.clear();
        std::cin.ignore(1024,'\n');
        std::cout << "Must me in range [" << min << ", " << max<< "]. " << msg;
        std::cin >> val;
    }

    return val;
}

char UIImpl::getCharFromConsole(const QSet<char> &right, const QString &msg)
{
    char val;

    std::cout << msg;
    std::cin >> val;

    while (std::cin.fail() || !(right.empty() || right.contains(val))) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Error. " << msg;
        std::cin >> val;
    }

    return val;
}

void UIImpl::fill(Mole &mole)
{
    mole.setDamageRadius(
                getBoundedFromConsole(1, 3, "Mole damage radius in range [1, 3]: "));
    mole.setSpeed(
                getBoundedFromConsole(1, 4, "Mole speed in range [1, 4]: "));

    mole.setPosition(getPositionFromConsole());

    char gender = getCharFromConsole({'m', 'f', 'r'}, "Gender of mole (m - male, f - female, r - random): ");

    switch (gender) {
    case 'm':
        mole.setGender(Mole::Gender::Male);
        break;
    case 'f':
        mole.setGender(Mole::Gender::Female);
        break;
    case 'r':
        mole.setGender(ProbabilityChecker().check(50) ? Mole::Gender::Male : Mole::Gender::Female);
    }

    char isChild = getCharFromConsole({}, "It's child-mole? y-yes, other - no: ");

    mole.setChildTicks(0);
    mole.setIsChild(isChild == 'y');

    char onGround = getCharFromConsole({}, "State of mole? o - on ground, other - under ground: ");
    mole.setState(onGround == 'o'? Mole::State::OnGround : Mole::State::Underground);

}

void UIImpl::fill(Cottager &cottager)
{
    cottager.setDamageRaduis(
                getBoundedFromConsole(1, 3, "Cottager damage radius in range [1, 3]: "));
    cottager.setSpeed(
                getBoundedFromConsole(1, 4, "Cottager speed in range [1, 4]: "));

    cottager.setPosition(getPositionFromConsole());
}

void UIImpl::fill(Harvest &harvest)
{

    harvest.setPosition(getPositionFromConsole());
}

IntegerVector UIImpl::getPositionFromConsole()
{
    IntegerVector fieldSize = m_logic->fieldSize();
    IntegerVector position(
                getBoundedFromConsole(0, fieldSize.x() - 1, QString("X position [0, %1): ").arg(fieldSize.x())),
                getBoundedFromConsole(0, fieldSize.y() - 1, QString("Y position [0, %1): ").arg(fieldSize.y())));
    return position;
}

void UIImpl::loopAction()
{

    if (m_needUpdateLogic)
        m_logic->update();
    m_needUpdateLogic = true;
    m_render->renderField(m_logic->getField());

    std::cout << "moles: " <<  m_logic->getAll<Mole>().size() << std::endl;
    std::cout << "harvest: " <<  m_logic->getHarvestCount() << std::endl;
    std::cout << "game status: " <<  m_logic->isGameOver() << std::endl;

    processMenu();


}

void UIImpl::processMenu()
{
    std::cout << "Actions" << std::endl;
    std::cout << "1. Add mole" << std::endl;
    std::cout << "2. Add harvest" << std::endl;
    std::cout << "3. Make step" << std::endl;
    std::cout << "0. Exit" << std::endl;

    int action = getBoundedFromConsole(0, 3, "Input action: ");

    switch (action) {

    case 1:{
        auto *o = m_logic->createObject<Mole>();
        fill(*o);
        m_logic->moveObject(o, o->position());
        m_needUpdateLogic = false;
        break;
    }
    case 2:{
        auto *o = m_logic->createObject<Harvest>();
        fill(*o);
        m_logic->moveObject(o, o->position());
        m_needUpdateLogic = false;
        break;
    }
    case 3:{
        m_needUpdateLogic = true;
        break;
    }
    case 0:{
        m_isExit = true;
    }

    }
}
