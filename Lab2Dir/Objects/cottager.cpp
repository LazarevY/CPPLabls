#include "cottager.h"

Cottager::Cottager()
{

}

Cottager::Cottager(
        int speed,
        const IntegerVector &position,
        const IntegerVector &direction)
    :
    MovingObject(
        speed,
        position,
        direction)
{

}


int Cottager::digitCode()
{
    return 0x2;
}
