#ifndef OBJECTHANDLER_H
#define OBJECTHANDLER_H

#include "baseobjecthandler.h"


template<typename T>
class ObjectHandler : public BaseObjectHandler
{
public:
    ObjectHandler()
    {

    }

    void process(BaseObject *o) override
    {
        auto casted = dynamic_cast<T *>(o);
        if (casted)
            process(casted);

    }

    virtual void processObject(T * o)
    {

    }
};

#endif // OBJECTHANDLER_H
