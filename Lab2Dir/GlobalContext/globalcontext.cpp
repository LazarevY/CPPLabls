#include "globalcontext.h"
#include <QDebug>

GlobalContext GlobalContext::m_globalInstance = GlobalContext();


GlobalContext::GlobalContext()
{

}

void GlobalContext::reportFatal(const QString &msg)
{
    qDebug().noquote() << "[FAIL]: " << msg;
    qDebug() << "Terminame program..\n";
    exit(-1);
}

void GlobalContext::reportError(const QString &msg)
{
    qDebug().noquote() << "[Error]: " << msg << "\n";
}

GlobalContext *GlobalContext::globalInstance()
{
    return &m_globalInstance;
}
