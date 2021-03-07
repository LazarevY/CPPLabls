#ifndef MOLEHANLDER_H
#define MOLEHANLDER_H

#include "objecthandler.h"
#include "Objects/mole.h"
#include "Logic/logic.h"
#include "Functions/function.h"
#include "Random/probabilitychecker.h"

using ProbabiltyFunction = Function<int, int>;

class MoleHanlder : public ObjectHandler<Mole>
{
public:
    MoleHanlder(Logic *logic);

    // ObjectHandler interface
public:
    void processObject(Mole *o) override;

    ProbabiltyFunction *undegroundChangeStateFunc() const;
    void setUndegroundChangeStateFunc(ProbabiltyFunction *undegroundChangeStateFunc);

    ProbabiltyFunction *ongroundChangeStateFunc() const;
    void setOngroundChangeStateFunc(ProbabiltyFunction *ongroundChangeStateFunc);

    ProbabiltyFunction *chiildChangeStateFunc() const;
    void setChiildChangeStateFunc(ProbabiltyFunction *chiildChangeStateFunc);

protected:
    void undergroundStateHandle(Mole *o);
    void onGroundStateHandle(Mole *o);
    void frozeStateHandle(Mole *o);
    void childStatehandle(Mole *o);
    Mole *checkAntiGenderMole(Mole *o);
    bool processRequestedState(Mole *o);
    void move(Mole *o);

private:
    Logic *m_logic;
    ProbabiltyFunction *m_undegroundChangeStateFunc;
    ProbabiltyFunction *m_ongroundChangeStateFunc;
    ProbabiltyFunction *m_chiildChangeStateFunc;
    ProbabilityChecker m_probabilityChecker;
};

#endif // MOLEHANLDER_H
