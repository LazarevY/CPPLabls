#ifndef LOGIC_H
#define LOGIC_H

#include <QMap>
#include <QMultiMap>
#include <QStack>
#include <type_traits>

#include "field.h"
#include "Objects/baseobject.h"
#include "ObjectsHandlers/baseobjecthandler.h"
#include "ObjectsHandlers/objecthandler.h"

using Path = QStack<IntegerVector>;


class Logic
{
public:
    Logic(Field *field);
    ~Logic();

    void addObject(BaseObject *o, const IntegerVector &position, bool resouceCapture = false);
    void addObject(BaseObject *o, bool resouceCapture = false);
    void moveObject(BaseObject *o, const IntegerVector &position);
    void removeObject(BaseObject *o);

    IntegerVector fieldSize() const;

    Field *getField() const;
    void setField(Field *field);

    int getHarvestCount() const;

    Path getPath(const IntegerVector &from, const IntegerVector &to);

    void removeHarvest(int count = 1);

    void startGame();

    bool isGameOver();

    void update();

    template<typename T>
    T *findNearestObject(const IntegerVector &pos, const std::function<bool(T *m)> &filter = [](T *){return true;}){
        if (!std::is_base_of<BaseObject, T>::value){
            return nullptr;
        }

        BaseObject *object = nullptr;

        for (auto o : getAll<T>()){
            BaseObject *base = dynamic_cast<BaseObject *>(o);
            if ((!object || (pos - base->position()).lenghtSqr() < (pos - object->position()).lenghtSqr()) && filter(o))
                object = base;
        }
        return dynamic_cast<T *>(object);
    }


    template<typename T>
    T* createObject(){
        if (!std::is_base_of<BaseObject, T>::value){
            return nullptr;
        }
        T *o = new T();
        BaseObject *base = dynamic_cast<BaseObject *>(o);
        addObject(base, true);
        return o;
    }


    IntegerVector fixCoords(const IntegerVector &coords);

    template<typename T>
    void registerHandler(ObjectHandler<T> *handler){
        m_handlersMap.insertMulti(
                    typeid (T).hash_code(),
                    handler);
    }

    template<typename T>
    void registerRemoveHandler(ObjectHandler<T> *handler){
        m_removeHandlersMap.insertMulti(
                    typeid (T).hash_code(),
                    handler);
    }

    template<typename ObjectType>
    QVector<ObjectType *> getAllObjectsInCell(const IntegerVector &coords, const std::function<bool(ObjectType *m)> &filter = [](ObjectType *){return true;}){
        auto objects = getAllObjectsInCell<BaseObject>(coords);
        return fillterByType<BaseObject, ObjectType>(objects, filter);
    }


    template<typename ObjectType>
    QVector<ObjectType *> getAll(){
        return fillterByType<BaseObject, ObjectType>(m_objectsMap.values().toVector());
    }



private:
    template<typename P, typename D>
    QVector<D *> fillterByType(const QVector<P*> in, const std::function<bool(D *m)> &filter = [](D *){return true;}){
        QVector<D *> filetered = QVector<D *>();
        for (auto o: in){
            D * casted  = dynamic_cast<D *>(o);
            if (casted && filter(casted))
                filetered.append(casted);
        }
        return filetered;
    }


    void processObject(BaseObject *o);

private:
    Field *m_field;
    int m_idCounter = 1;

    QMap<int, BaseObject *> m_objectsMap;
    QMap<int, BaseObject *> m_resourceCapturedObjects;
    QMultiMap<size_t, BaseObjectHandler *> m_handlersMap;
    QMultiMap<size_t, BaseObjectHandler *> m_removeHandlersMap;

    int m_harvestCount = 0;
};

template<>
inline QVector<BaseObject *> Logic::getAllObjectsInCell<BaseObject>(const IntegerVector &coords, const std::function<bool(BaseObject *m)> &){
    return m_field->operator()(coords).getAllObjects();
}

template<>
inline QVector<BaseObject *> Logic::getAll<BaseObject>(){
    return m_objectsMap.values().toVector();
}

#endif // LOGIC_H
