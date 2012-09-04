#ifndef LIST_ITERATOR_H
#define LIST_ITERATOR_H

#include <iterator>

template <typename ValueType>
struct ListIterator : std::iterator<std::bidirectional_iterator_tag, ValueType>
{
    template <typename OtherValueType>
    ListIterator(const ListIterator<OtherValueType> &other) : cur(other.cur) {}

    ListIterator &operator =(const ListIterator &other)
    { cur = other.cur; return *this; }
    
    ~ListIterator() {}

    ValueType &operator *() const
    { return cur->value; }

    friend bool operator !=(const ListIterator &lhs, const ListIterator &rhs)
    { return lhs.cur != rhs.cur; }
    
    friend bool operator ==(const ListIterator &lhs, const ListIterator &rhs)
    { return lhs.cur == rhs.cur; }

    ListIterator operator ++()
    { cur = cur->next; return *this; }

    ListIterator operator ++(int)
    { ListIterator copy(*this); cur = cur->next; return copy; }

    ListIterator operator --()
    { cur = cur->prev; return *this; }

    ListIterator operator --(int)
    { ListIterator copy(*this); cur = cur->prev; return copy; }

    ValueType *operator ->() const
    { return &(cur->value); }

private:
    ListIterator(Node *init) : cur(init) {}

    Node *cur;

    friend class List;
    friend class ListIterator<const ValueType>;
};

template <class ValueType>
struct ListReverseIterator : std::iterator<std::bidirectional_iterator_tag, ValueType>
{
    ListReverseIterator(const ListReverseIterator &other) : cur(other.cur) {}

    ListReverseIterator &operator =(const ListReverseIterator &other)
    { cur = other.cur; return *this; }
    
    ~ListReverseIterator() {}

    ValueType &operator *() const
    { return cur->value; }

    friend bool operator !=(const ListReverseIterator &lhs, const ListReverseIterator &rhs)
    { return lhs.cur != rhs.cur; }
    
    friend bool operator ==(const ListReverseIterator &lhs, const ListReverseIterator &rhs)
    { return lhs.cur == rhs.cur; }

    ListReverseIterator operator ++()
    { cur = cur->prev; return *this; }

    ListReverseIterator operator ++(int)
    { ListReverseIterator copy(*this); cur = cur->prev; return copy; }

    ListReverseIterator operator --()
    { cur = cur->next; return *this; }

    ListReverseIterator operator --(int)
    { ListReverseIterator copy(*this); cur = cur->next; return copy; }

    ValueType *operator ->() const
    { return &(cur->value); }

private:
    ListReverseIterator(Node *init) : cur(init) {}

    Node *cur;

    friend class List;
};

#endif // LIST_ITERATOR_H