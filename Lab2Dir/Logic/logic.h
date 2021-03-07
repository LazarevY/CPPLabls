#ifndef LOGIC_H
#define LOGIC_H

#include <QMap>
#include <QMultiMap>
#include <QStack>

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

    template<typename ObjectType>
    QVector<ObjectType *> getAllObjectsInCell(const IntegerVector &coords){
        auto objects = getAllObjectsInCell<BaseObject>(coords);
        return fillterByType<BaseObject, ObjectType>(objects);
    }


    template<typename ObjectType>
    QVector<ObjectType *> getAll(){
        return fillterByType<BaseObject, ObjectType>(m_objectsMap.values().toVector());
    }


   void addObject(BaseObject *o, const IntegerVector &position, bool resouceCapture = false);
   void addObject(BaseObject *o, bool resouceCapture = false);
   void moveObject(BaseObject *o, const IntegerVector &position);
   void removeObject(BaseObject *o);

   Path getPath(const IntegerVector &from, const IntegerVector &to);


   template<typename T>
   T* createObject(){
       if (!std::is_base_of_v<BaseObject, T>()){
           return nullptr;
       }
       T *o = new T();
       BaseObject *base = dynamic_cast<BaseObject *>(o);
       addObject(base, true);
   }


   IntegerVector fixCoords(const IntegerVector &coords);

   template<typename T>
   void registerHandler(ObjectHandler<T> *handler){
        m_handlersMap.insertMulti(
                    typeid (T).hash_code(),
                    handler);
   }

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

    void processObject(BaseObject *o);

private:
    Field *m_field;
    QMap<int, BaseObject *> m_objectsMap;
    QMap<int, BaseObject *> m_resourceCapturedObjects;
    int m_idCounter = 1;
    QMultiMap<size_t, BaseObjectHandler *> m_handlersMap;
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
