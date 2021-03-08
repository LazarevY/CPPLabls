#include "harvestremovehandler.h"

HarvestRemoveHandler::HarvestRemoveHandler(Logic *logic) :
    m_logic(logic)
{

}


void HarvestRemoveHandler::processObject(Harvest *o)
{
    m_logic->removeHarvest();
}
