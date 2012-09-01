#include "list.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
    List list;

    list.PushBack(1);
    list.PushFront(2);
    list.PushBack(3);
    list.PushFront(4);
    list.PushBack(5);

    *(list.RBegin()) = 10;

    std::cout << list.Size() << std::endl;

    for (List::Iterator it = list.Begin(); it != list.End(); ++it)
    {
    	std::cout << *it << ", ";
    }
    std::cout << std::endl;

    return 0;
}
