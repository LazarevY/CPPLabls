#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

#include <QHash>
#include <QDebug>
#include <QVector>

template <typename Key>
inline int hashOf(const Key& key);

template <typename Key,  typename Value>
class HashTable;

template <typename Key,  typename Value>
class HashTable
{
public:

    HashTable() :
        m_bucketSize(2),
        m_filled(0)
    {
        init(m_bucketSize);
        m_endNode = Node();
        m_endNode.next = &m_endNode;
        m_endNode.iterNext = &m_endNode;
        m_endNode.hash = 1;
    }

    class iterator;


    class Node{
    public:
        Node(): Node(-1, Key(), Value(), nullptr){

        }

        Node(int hash_,
             const Key& key_,
             const Value &value_,
             Node *iterNext_,
             Node *next_ = nullptr) :
            hash(hash_),
            key(key_),
            value(value_),
            iterNext(iterNext_),
            next(next_){}

        static Node defaultNode;

        int hash;
        Key key;
        Value value;
        Node *next;
        Node *iterNext;
    };

    class iterator{

    public:

        iterator(){}

        iterator(Node *n) : node(n){

        }

        iterator &operator++(){
            do{
                node = node->iterNext;
            }while(node->hash < 0);
            return *this;
        }

        iterator operator++(int){
            auto it = *this;
            do{
                node = node->iterNext;
            }while(node->hash < 0);
            return it;
        }

        bool operator==(const iterator &o){
            return node == o.node;
        }

        bool operator!=(const iterator &o){
            return node != o.node;
        }


        Key key(){
            return node->key;
        }

        Value value(){
            return node->value;
        }

        int hash(){
            return node->hash;
        }

        friend class HashTable;

    private:
        Node * node;

    };

    class keep{
    public:

        keep(): key(Key()), value(Value()), hash(-1){

        }

        keep(Node * n) : key(n->key), value(n->value), hash(n->hash)
        {

        }

        Key key;
        Value value;
        int hash;

    };

    iterator insert(const Key &key,  const Value &value);
    bool contains(const Key &key) const;
    keep remove(const Key &key);
    Value value(const Key &key);
    Value valueOrDefault(const Key &key, const Value &value = Value());

    Value &operator[](const Key &key);
    Value operator[](const Key &key) const;

    iterator begin();
    iterator end();

private:
    void init(int size);
    Node *_insert(const Key &key, const Value &value, int hash);
    void resize(int newSize);
    void rehash();
    void erase();
    void clearBucket();
    Node *nodeFor(const Key &key) const;
    Node **bucketEnd();
    Node **bucketBegin();
    QVector<keep> allPairs();

    void linkNextNode(Node *curr, Node *next);

    double fillFactor() const;
    bool isOverhead() const;


private:

    int m_bucketSize;
    int m_filled;
    Node **m_bucket;
    Node m_endNode = Node(0, Key(), Value(), nullptr);
    static constexpr double FILL_FACTOR = 0.75;


};

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node HashTable<Key, Value>::Node::defaultNode = Node();


template<typename Key, typename Value>
inline typename HashTable<Key, Value>::iterator HashTable<Key, Value>::insert(const Key &key, const Value &value)
{
    return iterator(*_insert(key, value, hashOf(key)));
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::contains(const Key &key) const
{
    return nodeFor(key);
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::keep HashTable<Key, Value>::remove(const Key &key)
{
    int hash = hashOf(key);

    int index =  hash % m_bucketSize;

    Node *head = m_bucket[index];

    Node *prev = head;
    Node *iter = head->next;

    while (iter && iter->key != key){
        prev = iter;
        iter = iter->next;
    }

    if (!iter)
        return keep(&Node::defaultNode);

    prev->next  = iter->next;
    prev->iterNext = iter->iterNext;


    m_filled--;
    keep k(iter);
    delete iter;
    return k;


}

template<typename Key, typename Value>
Value HashTable<Key, Value>::value(const Key &key)
{
    Node *n = nodeFor(key);

    return n? n->value : Value();

}

template<typename Key, typename Value>
Value HashTable<Key, Value>::valueOrDefault(const Key &key, const Value &value)
{
    Node *n = nodeFor(key);

    return n? n->value : value;
}

template<typename Key, typename Value>
Value &HashTable<Key, Value>::operator[](const Key &key)
{
    Node *n = nodeFor(key);

    if (!n)
        n = _insert(key, Value(), hashOf(key));

    return n->value;
}

template<typename Key, typename Value>
Value HashTable<Key, Value>::operator[](const Key &key) const
{
    return value(key);
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::iterator HashTable<Key, Value>::begin()
{
    auto begin = iterator(m_bucket[0]);
    while(begin.hash() < 0)
        ++begin;
    return begin;
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::iterator HashTable<Key, Value>::end()
{
    return iterator(&m_endNode);
}

template<typename Key, typename Value>
void HashTable<Key, Value>::init(int size)
{
    m_bucket = new Node*[size + 1]();
    m_bucketSize = size;

    for (int ind = 0; ind < size; ++ind)
        m_bucket[ind] = new Node();
    m_bucket[size] = &m_endNode;

    for (int ind = 0; ind < size; ++ind)
        m_bucket[ind]->iterNext = m_bucket[ind + 1];


}

template<typename Key, typename Value>
inline typename HashTable<Key, Value>::Node *HashTable<Key, Value>::_insert(const Key &key, const Value &value, int hash)
{
    if (isOverhead())
        resize(m_bucketSize * 2);

    int index =  hash % m_bucketSize;
    Node *n = m_bucket[index];
    n = n->next;

    bool isFindEqual = false;
    if (!n){
        n = new Node(hash, key, value, nullptr);
        linkNextNode(m_bucket[index], n);
    }
    else{
        Node *iter = n;
        auto prev = iter;
        while (iter) {
            if (iter->key == key){
                iter->value = value;
                isFindEqual = true;
                break;
            }
            prev = iter;
            iter = iter->next;
        }
        if (!isFindEqual){
            n = new Node(hash, key, value, nullptr);
            linkNextNode(prev, n);

        }
    }

    if (!isFindEqual)
        m_filled++;

    return n;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::resize(int newSize)
{
    //qDebug() << "start resize table";
    QVector<keep> all = allPairs();
    clearBucket();
    init(newSize);
    for (auto &it: all)
        _insert(it.key, it.value, it.hash);
    // qDebug() << "table has been resized";

}

template<typename Key, typename Value>
void HashTable<Key, Value>::rehash()
{
    clearBucket();
    QVector<iterator> all = allPairs();
    for (auto &it: all)
        _insert(it.key(), it.value(), it.hash());
}

template<typename Key, typename Value>
void HashTable<Key, Value>::erase()
{
    clearBucket();
    delete [] m_bucket;
    m_filled = 0;
    m_bucketSize = 0;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::clearBucket()
{
    Node **n = bucketBegin();
    Node *deleteNode = *n;
    while (n != bucketEnd()){
        deleteNode = *n;
        if (deleteNode){
            Node *next = deleteNode->next;
            while(next){
                Node *deleteNext = next;
                next = next->next;
                delete deleteNext;
            }
        }
        n++;
        delete deleteNode;
    }
    m_filled = 0;
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node *HashTable<Key, Value>::nodeFor(const Key &key) const
{
    int hash = hashOf(key);

    int index =  hash % m_bucketSize;

    Node *head = m_bucket[index];

    Node *iter = head->next;
    if (!iter)
        return nullptr;

    while (iter && iter->key != key)
        iter = iter->next;

    return iter;
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node **HashTable<Key, Value>::bucketEnd()
{
    return m_bucket + m_bucketSize;
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node **HashTable<Key, Value>::bucketBegin()
{
    return m_bucket;
}

template<typename Key, typename Value>
QVector<typename HashTable<Key, Value>::keep> HashTable<Key, Value>::allPairs()
{
    QVector<keep> res;
    for (auto n = bucketBegin(); n != bucketEnd(); ++n){
        if (!(*n)->next)
            continue;

        auto iter = *n;
        iter = iter->next;
        res.append(keep(iter));
        iter = iter->next;
        while (iter){
            res.append(keep(iter));
            iter = iter->next;
        }
    }
    return res;
}

template<typename Key, typename Value>
void HashTable<Key, Value>::linkNextNode(HashTable::Node *curr, HashTable::Node *next)
{
    next->next = curr->next;
    next->iterNext = curr->iterNext;
    curr->next = next;
    curr->iterNext = next;
}

template<typename Key, typename Value>
double HashTable<Key, Value>::fillFactor() const
{
    return m_filled / m_bucketSize;
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::isOverhead() const
{
    return fillFactor() > FILL_FACTOR;
}





#endif // ASSOCIATIVEARRAY_H
