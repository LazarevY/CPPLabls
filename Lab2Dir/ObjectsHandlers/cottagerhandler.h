#ifndef COTTAGERHANDLER_H
#define COTTAGERHANDLER_H

#include "Objects/cottager.h"
#include "ObjectsHandlers/objecthandler.h"
#include "Logic/logic.h"

class CottagerHandler : public ObjectHandler<Cottager>
{
public:
    CottagerHandler();

    // ObjectHandler interface
public:
    void processObject(Cottager *o) override;
};

#endif // COTTAGERHANDLER_H
