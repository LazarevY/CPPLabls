#ifndef BASEOBJECTHANDLER_H
#define BASEOBJECTHANDLER_H

#include "Objects/baseobject.h"

class BaseObjectHandler
{
public:
    BaseObjectHandler();
    virtual ~BaseObjectHandler();

    virtual void process(BaseObject *o) = 0;

    virtual size_t objectTypeHashCode() = 0;
};

#endif // BASEOBJECTHANDLER_H
