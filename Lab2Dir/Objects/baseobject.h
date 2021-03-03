#ifndef BASEOBJECT_H
#define BASEOBJECT_H


class BaseObject
{
public:
    BaseObject();

    /**
     * @brief The number is power of tho, unique for even type of object
     */
    virtual int digitCode() = 0;

    int id() const;


protected:
    void setId(int id);

protected:
    int m_id;
};

#endif // BASEOBJECT_H
