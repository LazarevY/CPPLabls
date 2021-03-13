#include "molehanlder.h"
#include "Objects/harvest.h"
#include "Random/randomgenerator.h"

MoleHanlder::MoleHanlder(Logic *logic) :
    m_logic(logic)
{

}


void MoleHanlder::processObject(Mole *o)
{
    if (processRequestedState(o)){

    }
    else if (o->isChild()){
        childStatehandle(o);
    }
    else {
        switch (o->state()) {
        case Mole::State::OnGround:
            onGroundStateHandle(o);
            break;
        case Mole::State::Underground:
            undergroundStateHandle(o);
            break;
        case Mole::State::Froze:
            frozeStateHandle(o);
            break;
        }
    }
}

void MoleHanlder::undergroundStateHandle(Mole *o)
{
    int undergroundTicks = o->currentTicksUnderGround();
    o->setCurrentTicksUnderGround(undergroundTicks + 1);
    if(!o->canBeFroze())
        o->setTickToCanFroze(o->tickToCanFroze() - 1);

    auto antipodeMole = checkAntiGenderMole(o);
    if (antipodeMole){
        o->setState(Mole::State::Froze);
        antipodeMole->requestState(Mole::State::Froze);

    }
    else {
        int transitionProbability = m_undegroundChangeStateFunc->calculate(undergroundTicks);

        if (m_probabilityChecker.check(transitionProbability)){
            o->setCurrentTicksUnderGround(0);
            o->setCurrentTicksOnGround(0);
            o->setState(Mole::State::OnGround);
            auto harvestes  = m_logic->getAllObjectsInCell<Harvest>(o->position());
            for (auto harvest: harvestes)
                m_logic->removeObject(harvest);
        }
        else {
            o->setCurrentTicksUnderGround(undergroundTicks + 1);
            move(o);
        }

    }
}

void MoleHanlder::onGroundStateHandle(Mole *o)
{
    int onGroundTicks = o->currentTicksOnGround();
     o->setCurrentTicksOnGround(onGroundTicks + 1);
    int transitionProbability = m_ongroundChangeStateFunc->calculate(onGroundTicks);

    if(!o->canBeFroze())
        o->setTickToCanFroze(o->tickToCanFroze() - 1);

    if (m_probabilityChecker.check(transitionProbability)){
        o->setState(Mole::State::Underground);
        o->setCurrentTicksUnderGround(0);
        o->setCurrentTicksOnGround(0);
    }
    else {
        IntegerVector radius = IntegerVector(o->damageRadius(), o->damageRadius());

        IntegerVector min = m_logic->fixCoords(o->position() - radius);
        IntegerVector max = m_logic->fixCoords(o->position() + radius);

        int maxDestroyCount = RandomGenerator::getNewRandom().bounded(1,2);

        for (int y = max.y(); y >= min.y() && maxDestroyCount; --y)
            for (int x = min.x(); x <= max.x() && maxDestroyCount; ++x){
                auto current = IntegerVector(x,y);

                if (o->position() == current)
                    continue;

                auto harvestes = m_logic->getAllObjectsInCell<Harvest>(current);

                for (auto harvest: harvestes)
                    if (maxDestroyCount){
                        m_logic->removeObject(harvest);
                        maxDestroyCount--;
                    }
            }
    }
}

void MoleHanlder::frozeStateHandle(Mole *o)
{
    if (o->frozeTicks() >= 2){
        o->setState(Mole::State::Underground);
        o->setTickToCanFroze(5);
        if (o->gender() == Mole::Gender::Female){
            Mole* child = m_logic->createObject<Mole>();
            auto gender = m_probabilityChecker.check(50) ? Mole::Gender::Female : Mole::Gender::Male;
            child->setGender(gender);
            child->setIsChild(true);
            child->setSpeed(3);
            child->setDamageRadius(1);
            IntegerVector childPos = m_logic->fixCoords(o->position() + IntegerVector(1,0));
            m_logic->moveObject(child, childPos);
        }
    }
    else {
        o->setFrozeTicks(o->frozeTicks() + 1);
    }
}

void MoleHanlder::childStatehandle(Mole *o)
{
    int childTicks = o->childTicks();
    int adultProbability = m_chiildChangeStateFunc->calculate(childTicks);

    if (m_probabilityChecker.check(adultProbability)){
        o->setIsChild(false);
        o->setState(Mole::State::Underground);
    }
    else{
        move(o);
        o->setChildTicks(childTicks + 1);
    }
}

Mole* MoleHanlder::checkAntiGenderMole(Mole *o)
{
    if (!o->canBeFroze())
        return nullptr;

    IntegerVector radius = IntegerVector(1,1);

    IntegerVector min = m_logic->fixCoords(o->position() - radius);
    IntegerVector max = m_logic->fixCoords(o->position() + radius);

    for (int y = max.y(); y >= min.y(); --y)
        for (int x = min.x(); x <= max.x(); ++x){
            auto current = IntegerVector(x,y);

            if (o->position() == current)
                continue;

            auto moles = m_logic->getAllObjectsInCell<Mole>(current);

            for (auto mole: moles)
                if (o->isAnipodeGender(mole->gender()) && mole->state() == Mole::State::Underground){
                    return mole;
                }
        }

    return nullptr;
}

bool MoleHanlder::processRequestedState(Mole *o)
{
    if (o->haveRequestState()){
        auto state = o->acceptRequestState();
        if (state == Mole::State::Froze){
            o->setState(state);
            o->setCurrentTicksUnderGround(o->currentTicksUnderGround() + 1);
            return true;
        }
    }

    return false;
}

void MoleHanlder::move(Mole *o)
{
    IntegerVector dir = o->direction();
    if (m_probabilityChecker.check(50)){
        auto g = RandomGenerator::getNewRandom();
        dir = IntegerVector(g.bounded(-1, 1), g.bounded(-1, 1));
        if (dir == IntegerVector(0,0)){
            dir.setX(1);
            dir.normalize();
        }
    }

    o->setDirection(dir);

    IntegerVector pos = m_logic->fixCoords(dir * o->speed() + o->position());

    m_logic->moveObject(o, pos);
}


ProbabiltyFunction *MoleHanlder::ongroundChangeStateFunc() const
{
    return m_ongroundChangeStateFunc;
}

void MoleHanlder::setOngroundChangeStateFunc(ProbabiltyFunction *ongroundChangeStateFunc)
{
    m_ongroundChangeStateFunc = ongroundChangeStateFunc;
}

ProbabiltyFunction *MoleHanlder::chiildChangeStateFunc() const
{
    return m_chiildChangeStateFunc;
}

void MoleHanlder::setChiildChangeStateFunc(ProbabiltyFunction *chiildChangeStateFunc)
{
    m_chiildChangeStateFunc = chiildChangeStateFunc;
}

ProbabiltyFunction *MoleHanlder::undegroundChangeStateFunc() const
{
    return m_undegroundChangeStateFunc;
}

void MoleHanlder::setUndegroundChangeStateFunc(ProbabiltyFunction *undegroundChangeStateFunc)
{
    m_undegroundChangeStateFunc = undegroundChangeStateFunc;
}
