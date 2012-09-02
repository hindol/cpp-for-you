#include "list.h"

List::~List()
{
    Node *prev;
    while (head != 0L)
    {
        prev = head;
        head = head->next;
        delete prev;
    }
}

void List::Insert(Iterator it, ValueT value)
{
    if (it == Begin())
    {
        if (head != 0L)
        {
            head->prev = new Node(value, 0L, head);
            head = head->prev;
        }
        else
        {
            head = tail = new Node(value, 0L, 0L);
        }
    }
    else if (it == End()) // also Begin() != End()
    {
        tail->next = new Node(value, tail, 0L);
        tail = tail->next;
    }
    else
    {
        it.cur->prev = new Node(value, it.cur->prev, it.cur);
    }

    ++size;
}
