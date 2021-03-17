#include "globalcontext.h"
#include <QDebug>

GlobalContext GlobalContext::m_globalInstance = GlobalContext();


GlobalContext::GlobalContext()
{

}

void GlobalContext::reportFatal(const QString &msg)
{
    qDebug().noquote() << "[FAIL]: " << msg;
    qDebug() << "Terminame program..";
    exit(-1);
}

GlobalContext *GlobalContext::globalInstance()
{
    return &m_globalInstance;
}
