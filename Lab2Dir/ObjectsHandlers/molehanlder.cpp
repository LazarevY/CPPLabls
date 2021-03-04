#include "molehanlder.h"

MoleHanlder::MoleHanlder(Logic *logic) :
    m_logic(logic)
{

}


void MoleHanlder::process(Mole *o)
{
    m_logic->moveObject(o, IntegerVector(0,0));
}
