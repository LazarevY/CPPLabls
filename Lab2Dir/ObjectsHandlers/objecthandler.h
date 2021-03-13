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
            processObject(casted);

    }

    virtual void processObject(T * o)
    {

    }

    size_t objectTypeHashCode() override
    {
        return typeid (T).hash_code();
    }
};

#endif // OBJECTHANDLER_H
