#ifndef LIST_H
#define LIST_H

class ForwardList
{
public:
    struct ForwardListNode
    {
        value_type value;
        ForwardListNode *next; // Pointer to next node
    };

    typedef int             value_type;
    typedef unsigned        size_type;
    typedef ForwardListNode node_type;    

    ForwardList();
    ~ForwardList();

    node_type *BeforeHead(); // Return the dummy pointer, not to be dereferenced
    node_type *Head();

    node_type *NodeAt(size_type pos);

    void InsertAfter(node_type *node, value_type value);
    void EraseAfter(node_type *node); // Remove the node after

    value_type &Front(); // Return the first value
    void PushFront(value_type value); // Insert a value at head
    void PopFront(); // Remove the first value

private:
    node_type *beforeHead;  // A dummy node, so that InsertAfter() and
                            // EraseAfter() may be used with head also.
};

#endif // LIST_H
