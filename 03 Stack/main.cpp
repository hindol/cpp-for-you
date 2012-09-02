#include "stack.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
    Stack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    assert(stack.Size() == 5);

    std::cout << "Should print \'5, 4, 3, 2, 1,\'" << std::endl;
    while (stack.Size() > 0)
    {
    	std::cout << stack.Top() << ", ";
        stack.Pop();
    }
    std::cout << std::endl;

    return 0;
}
