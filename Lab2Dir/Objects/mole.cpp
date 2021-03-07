#include "mole.h"

Mole::Mole()
{

}

Mole::Mole(int speed,
        const IntegerVector &position,
        const IntegerVector &direction,
        Gender gender,
        bool isChild,
        int damageRadius)
    :
    MovingObject(
        speed,
        position,
        direction),
    m_gender(gender),
    m_isChild(isChild),
    m_damageRadius(damageRadius)
{

}


int Mole::digitCode()
{
    return 0x4;
}

Mole::Gender Mole::gender() const
{
    return m_gender;
}

void Mole::setGender(const Gender &gender)
{
    m_gender = gender;
}

bool Mole::isChild() const
{
    return m_isChild;
}

void Mole::setIsChild(bool isChild)
{
    m_isChild = isChild;
}

int Mole::currentTicksUnderGround() const
{
    return m_currentTicksUnderGround;
}

void Mole::setCurrentTicksUnderGround(int currentTicksUnderGround)
{
    m_currentTicksUnderGround = currentTicksUnderGround;
}

int Mole::currentTicksOnGround() const
{
    return m_currentTicksOnGround;
}

void Mole::setCurrentTicksOnGround(int currentTicksOnGround)
{
    m_currentTicksOnGround = currentTicksOnGround;
}

int Mole::childTicks() const
{
    return m_childTicks;
}

void Mole::setChildTicks(int childTicks)
{
    m_childTicks = childTicks;
}

int Mole::damageRadius() const
{
    return m_damageRadius;
}

void Mole::setDamageRadius(int damageRadius)
{
    m_damageRadius = damageRadius;
}

Mole::State Mole::state() const
{
    return m_state;
}

void Mole::setState(const State &state)
{
    m_state = state;
}

bool Mole::isAnipodeGender(const Mole::Gender &g)
{
    return m_gender != g;
}

int Mole::frozeTicks() const
{
    return m_frozeTicks;
}

void Mole::setFrozeTicks(int frozeTicks)
{
    m_frozeTicks = frozeTicks;
}

void Mole::requestState(Mole::State state)
{
    m_requestState = state;
}

bool Mole::haveRequestState() const
{
    return m_requestState != Mole::State::None;
}

Mole::State Mole::acceptRequestState()
{
    State s = m_requestState;
    m_requestState = State::None;
    return s;
}
