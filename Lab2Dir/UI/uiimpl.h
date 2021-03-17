#ifndef UIIMPL_H
#define UIIMPL_H

#include <QSet>
#include <QString>

#include "abstarctui.h"
#include "Logic/logic.h"
#include "Objects/cottager.h"
#include "Objects/harvest.h"
#include "Objects/mole.h"
#include "Random/probabilitychecker.h"
#include "Render/fieldrenderimpl.h"
#include "Functions/maptablefunctionimpl.h"
#include <QThread>
#include "ObjectsHandlers/cottagerhandler.h"
#include "ObjectsHandlers/harvestremovehandler.h"
#include "ObjectsHandlers/molehanlder.h"


class UIImpl : public AbstarctUI
{
public:
    UIImpl(Logic *logic, FieldRender *render);

    int show() override;


private:

    void initLogic();
    int getIntFromConsole(const QString &msg = "");
    int getBoundedFromConsole(int min, int max, const QString &msg = "");
    char getCharFromConsole(const QSet<char> &right = QSet<char>(), const QString &msg = "");

    void fill(Mole &mole);
    void fill(Cottager &cottager);
    void fill(Harvest &harvest);

    IntegerVector getPositionFromConsole();
    void loopAction();
    void processMenu();

    template<typename T>
    void removeAllObjectsFromCell(const IntegerVector &cell){
        for (auto *o : m_logic->getAllObjectsInCell<T>(cell))
            m_logic->removeObject(o);
    }



private:

    Logic *m_logic;
    Field *m_field;
    FieldRender *m_render;
    bool m_isExit = false;
    bool m_needUpdateLogic = true;

};

inline std::ostream &operator<<(std::ostream &o, const QString &str){
    o << str.toStdString();
    return o;
}

#endif // UIIMPL_H
