#ifndef HARVEST_H
#define HARVEST_H

#include "baseobject.h"

class Harvest : public BaseObject
{
public:
    explicit Harvest(const IntegerVector &pos = IntegerVector(0,0));

    // BaseObject interface
public:
    int digitCode() override;
};

#endif // HARVEST_H
