#ifndef MOLE_H
#define MOLE_H

#include <QStack>

#include "movingobject.h"
using Path = QStack<IntegerVector>;

class Mole : public MovingObject
{
public:
    enum class Gender
    {
        Male, Female
    };

    enum class State{
        Underground, OnGround, Froze, None
    };

    Mole();
    Mole(int speed,
         const IntegerVector &position,
         const IntegerVector &direction,
         Gender gender,
         bool isChild,
         int damageRadius);

    int digitCode() override;

    Gender gender() const;
    void setGender(const Gender &gender);


    bool isChild() const;
    void setIsChild(bool isChild);

    int currentTicksUnderGround() const;
    void setCurrentTicksUnderGround(int currentTicksUnderGround);

    int currentTicksOnGround() const;
    void setCurrentTicksOnGround(int currentTicksOnGround);

    int childTicks() const;
    void setChildTicks(int childTicks);

    int damageRadius() const;
    void setDamageRadius(int damageRadius);

    State state() const;
    void setState(const State &state);

    bool isAnipodeGender(const Gender &g);

    int frozeTicks() const;
    void setFrozeTicks(int frozeTicks);

    void requestState(State state);
    bool haveRequestState() const;
    State acceptRequestState();

    int tickToCanFroze() const;
    void setTickToCanFroze(int tickToCanFroze);

    bool canBeFroze() const;

private:
    Gender m_gender;
    State m_state = State::Underground;
    State m_requestState = State::None;
    bool m_isChild = false;
    int m_currentTicksUnderGround = 0;
    int m_currentTicksOnGround = 0;
    int m_childTicks = 0;
    int m_frozeTicks = 0;
    int m_damageRadius = 1;
    int m_tickToCanFroze = 2;
};

#endif // MOLE_H
