#ifndef COTTAGERHANDLER_H
#define COTTAGERHANDLER_H

#include "Objects/cottager.h"
#include "ObjectsHandlers/objecthandler.h"
#include "Logic/logic.h"

class CottagerHandler : public ObjectHandler<Cottager>
{
public:
    explicit CottagerHandler(Logic *logic = nullptr);
    void processObject(Cottager *o) override;

private:

    void move(Cottager *o, const IntegerVector &to);
    bool checkMoles(Cottager *o);

    Logic *m_logic;
};

#endif // COTTAGERHANDLER_H
