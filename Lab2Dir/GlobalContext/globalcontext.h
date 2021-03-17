#ifndef GLOBALCONTEXT_H
#define GLOBALCONTEXT_H

#include <QString>

class GlobalContext
{
public:
    GlobalContext();

    void reportFatal(const QString &msg);

    static GlobalContext *globalInstance();

private:
    static GlobalContext m_globalInstance;
};

#endif // GLOBALCONTEXT_H
