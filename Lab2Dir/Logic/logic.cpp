#include "logic.h"
#include "Objects/harvest.h"
#include "Objects/mole.h"
#include "Objects/cottager.h"

Logic::Logic(Field *field) :
    m_field(field)
{

}

Logic::~Logic()
{
    for (auto kv = m_resourceCapturedObjects.begin(); kv != m_resourceCapturedObjects.end(); ++kv)
        delete kv.value();
}

IntegerVector Logic::fieldSize() const
{
    return m_field->size();
}

void Logic::addObject(BaseObject *o, const IntegerVector &position, bool resouceCapture)
{
    o->setId(m_idCounter++);
    m_objectsMap[o->id()] = o;
    m_field->add(position, o);
    if (resouceCapture)
        m_resourceCapturedObjects[o->id()] = o;
}

void Logic::addObject(BaseObject *o, bool resouceCapture)
{
    addObject(o, o->position(), resouceCapture);
}

void Logic::moveObject(BaseObject *o, const IntegerVector &toCell)
{
    if (!m_objectsMap.contains(o->id())){
        return;
    }

    m_field->move(toCell, o);
    o->setPosition(toCell);

}

void Logic::removeObject(BaseObject *o)
{
    if (!m_objectsMap.contains(o->id())){
        return;
    }

    m_objectsMap.take(o->id());
    for (auto h: m_handlersMap.values(typeid (o).hash_code()))
        h->process(o);
    m_field->remove(o);
    if (m_resourceCapturedObjects.contains(o->id())){
        delete m_resourceCapturedObjects.take(o->id());
    }
}

Path Logic::getPath(const IntegerVector &from, const IntegerVector &to)
{
    Path p;
    p.push(to);
    p.push(IntegerVector(to.x(), from.y()));
    return p;
}

void Logic::removeHarvest(int count)
{
    m_harvestCount -= count;
}

void Logic::startGame()
{
    m_harvestCount = getAll<Harvest>().size();
}

bool Logic::isGameOver()
{
    return !(m_harvestCount && getAll<Mole>().size());
}

bool Logic::isWin()
{
    return !getAll<Mole>().size();
}

void Logic::update()
{
    for (auto *o : m_objectsMap)
        for (auto *h : m_handlersMap.values(typeid (*o).hash_code()))
            if (!dynamic_cast<Cottager *>(o))
                h->process(o);

    for (auto c: getAll<Cottager>())
        for (auto *h : m_handlersMap.values(typeid (*c).hash_code()))
                h->process(c);
}

IntegerVector Logic::fixCoords(const IntegerVector &coords)
{
    return m_field->fixSize(coords);
}

void Logic::processObject(BaseObject *o)
{
    for (auto handler: m_handlersMap.values(typeid(o).hash_code()))
        handler->process(o);
}

void Logic::setField(Field *field)
{
    m_field = field;
}

int Logic::getHarvestCount() const
{
    return m_harvestCount;
}

Field *Logic::getField() const
{
    return m_field;
}
