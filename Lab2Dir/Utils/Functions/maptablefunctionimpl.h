#ifndef MAPTABLEFUNCTIONIMP_H
#define MAPTABLEFUNCTIONIMP_H

#include <QMap>

#include "tablefunction.h"

template <typename R, typename P>
class MapTableFunctionImpl : public TableFunction<R, P>
{
public:
    MapTableFunctionImpl(const std::function<R (const P &)> &defaultFuction =
            [](const P &){
        return R();
    }) : TableFunction<R, P>(defaultFuction)
    {

    }

    R calculate(const P &key) override
    {
        return m_functionMap.value(key, this->m_defaultFunction(key));
    }

    void setValueFor(const P &key, const R &value) override
    {
        m_functionMap[key] = value;
    }


private:
    QMap<P, R> m_functionMap;

};

#endif // MAPTABLEFUNCTIONIMP_H
