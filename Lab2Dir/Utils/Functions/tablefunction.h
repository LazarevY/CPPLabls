#ifndef TABLEFUNCTION_H
#define TABLEFUNCTION_H

#include "function.h"
#include <functional>

template <typename R, typename P>
class TableFunction: public Function<R, P>
{
public:
    explicit TableFunction(const std::function<R (const P &)> &defaultFunction =
            [](){
        return R();
    }) :
        m_defaultFunction(defaultFunction)
    {

    }
    virtual R calculate(const P &key) override = 0;

    virtual void setValueFor(const P &key, const R &value) = 0;

    void setDefaultFuction(const std::function<R (const P &)> &defaultFuction)
    {
        m_defaultFunction = defaultFuction;
    }

protected:
    std::function<R (const P &)> m_defaultFunction;
};

#endif // TABLEFUNCTION_H
