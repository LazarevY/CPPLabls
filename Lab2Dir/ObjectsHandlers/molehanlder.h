#ifndef MOLEHANLDER_H
#define MOLEHANLDER_H

#include "objecthandler.h"
#include "Objects/mole.h"
#include "Logic/logic.h"

class MoleHanlder : public ObjectHandler<Mole>
{
public:
    MoleHanlder(Logic *logic);

    // ObjectHandler interface
public:
    void process(Mole *o) override;

private:
    Logic *m_logic;
};

#endif // MOLEHANLDER_H
