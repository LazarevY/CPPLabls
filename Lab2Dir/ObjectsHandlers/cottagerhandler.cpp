#include "cottagerhandler.h"
#include "Objects/mole.h"

CottagerHandler::CottagerHandler(Logic *logic) : m_logic(logic)
{

}


void CottagerHandler::processObject(Cottager *o)
{
    if (checkMoles(o)){
    }else {
        Mole *nearest = m_logic->findNearestObject<Mole>(o->position(),
                                                         [](Mole *m)
        {return m->state() == Mole::State::OnGround;});

        if (nearest){
            move(o, nearest->position());
        }
    }

}

void CottagerHandler::move(Cottager *o, const IntegerVector &to)
{
    auto needStep = m_logic->getPath(o->position(), to).pop() - o->position();

    auto canStep = needStep.normalized() * o->speed();

    auto step = qMin(needStep, canStep);

    m_logic->moveObject(o, m_logic->fixCoords(o->position() + step));
}

bool CottagerHandler::checkMoles(Cottager *o)
{
    int maxKills = 1;
    IntegerVector radius = IntegerVector(o->damageRaduis(),o->damageRaduis());

    IntegerVector min = m_logic->fixCoords(o->position() - radius);
    IntegerVector max = m_logic->fixCoords(o->position() + radius);

    for (int y = max.y(); y >= min.y() && maxKills; --y)
        for (int x = min.x(); x <= max.x() && maxKills; ++x){
            auto current = IntegerVector(x,y);

            auto moles = m_logic->getAllObjectsInCell<Mole>(current);

            for (auto mole: moles)
                if (mole->state() == Mole::State::OnGround && maxKills){
                    m_logic->removeObject(mole);
                    maxKills--;
                }
        }

    return maxKills < 1;
}
