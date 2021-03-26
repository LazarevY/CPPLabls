#ifndef ASSOCIATIVEARRAY_H
#define ASSOCIATIVEARRAY_H

#include <QHash>

template <typename Key>
inline int hashOf(const Key& key);

template <typename Key,  typename Value>
class HashTable
{
public:

    HashTable() :
        m_bucketSize(32),
        m_filled(0)
    {
        init();
    }

    class iterator;


    class Node{
    public:


        Node(int hash_,
             const Key& key_,
             const Value &value_,
             Node *next_ = nullptr) :
            hash(hash_),
            key(key_),
            value(value_),
            next(next_){}
        friend class iterator;

        static const Node defaultNode;

    private:
        int hash;
        Key key;
        Value value;
        Node *next;

    };

    class iterator{

        iterator(const Node &n) : m_key(n.key), m_value(n.value){

        }


        Key key(){
            return m_key;
        }

        Value value(){
            return m_value;
        }

    private:
        Key m_key;
        Value m_value;

    };

    iterator insert(const Key &key,  const Value &value);
    bool contains(const Key &key) const;
    iterator remove(const Key &key);

    Value &operator[](const Key &key);
    Value &operator[](const Key &key) const;

private:
    void init();
    void resize(int newSize);
    void rehash();
    Node *nodeFor(const Key &key);
    Node **bucketEnd();


private:

    int m_bucketSize;
    int m_filled;

    static constexpr double fillFactor = 0.75;

    Node **m_bucket;


};


template<typename Key, typename Value>
inline typename HashTable<Key, Value>::iterator HashTable<Key, Value>::insert(const Key &key, const Value &value)
{
    Node *n = nodeFor(key);

    if (!n){
        int hash = hashOf(key);

        int index =  hash % m_bucketSize;

        m_bucket[index] = new Node(hash, key, value, nullptr);

    }
    else{
        Node *iter = n;
        bool isFindEqual;
        while (iter->next) {
            if (iter->key == key){
                iter->value = value;
                isFindEqual = true;
                break;
            }
        }
        if (!isFindEqual){
            iter->next = new Node(iter->hash, key, value, nullptr);
        }
    }

    m_filled++;

    return iterator(*n);
}

template<typename Key, typename Value>
bool HashTable<Key, Value>::contains(const Key &key) const
{
    return nodeFor(key);
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::iterator HashTable<Key, Value>::remove(const Key &key)
{
    Node *n = nodeFor(key);

    if (!n)
        return iterator(Node::defaultNode);
    int index = n->hash % m_bucketSize;

    Node *prev = n;
    Node *next = prev->next;

    if (!next)
        *m_bucket[index] = nullptr;

    while (next && next->key == key){
        prev = next;
        next = next->next;
    }

    prev->next = next->next;

    iterator it(*next);
    delete next;
    m_filled--;
    return it;


}

template<typename Key, typename Value>
void HashTable<Key, Value>::init()
{
    m_bucket = new Node*[m_bucketSize + 1]();
}

template<typename Key, typename Value>
typename HashTable<Key, Value>::Node *HashTable<Key, Value>::nodeFor(const Key &key)
{
    int hash = hashOf(key);

    int index =  hash % m_bucketSize;

    Node **head = m_bucket[index];

    Node *iter = *head;
    if (!iter)
        return nullptr;

    while (iter->next)
        if(iter->key == key)
            return iter;

    return nullptr;

}


#endif // ASSOCIATIVEARRAY_H
