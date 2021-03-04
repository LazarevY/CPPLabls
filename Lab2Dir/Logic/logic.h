#ifndef LOGIC_H
#define LOGIC_H

#include <QMap>

#include "field.h"
#include "Objects/baseobject.h"

class Logic
{
public:
    Logic(Field *field);

    template<typename ObjectType>
    QVector<ObjectType *> getAllObjectsInCell(const IntegerVector &coords){
        auto objects = getAllObjectsInCell<BaseObject>(coords);
        return fillterByType<BaseObject, ObjectType>(objects);
    }


    template<typename ObjectType>
    QVector<ObjectType *> getAll(){
        return fillterByType<BaseObject, ObjectType>(m_objectsMap.values().toVector());
    }


   void addObject(BaseObject *o, const IntegerVector &position);
   void addObject(BaseObject *o);
   void moveObject(BaseObject *o, const IntegerVector &toCell);
   void removeObject(BaseObject *o);

private:
    template<typename P, typename D>
    QVector<D *> fillterByType(const QVector<P*> in){
        QVector<D *> filetered = QVector<D *>();
                for (auto o: in){
                    D * casted  = dynamic_cast<D *>(o);
                    if (casted)
                        filetered.append(casted);
                }
                return filetered;
    }

private:
    Field *m_field;
    QMap<int, BaseObject *> m_objectsMap;
    int m_idCounter = 1;
};

template<>
inline QVector<BaseObject *> Logic::getAllObjectsInCell<BaseObject>(const IntegerVector &coords){
    return m_field->operator()(coords).getAllObjects();
}

template<>
inline QVector<BaseObject *> Logic::getAll<BaseObject>(){
    return m_objectsMap.values().toVector();
}

#endif // LOGIC_H
