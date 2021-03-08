#ifndef HARVESTREMOVEHANDLER_H
#define HARVESTREMOVEHANDLER_H

#include "objecthandler.h"
#include "Objects/harvest.h"
#include "Logic/logic.h"

class HarvestRemoveHandler : public ObjectHandler<Harvest>
{
public:
    HarvestRemoveHandler(Logic *logic);

    void processObject(Harvest *o) override;

private:
    Logic *m_logic;
};

#endif // HARVESTREMOVEHANDLER_H
