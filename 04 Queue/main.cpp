#include "queue.h"
#include <cassert>
#include <iostream>

int main(int argc, char *argv[])
{
    Queue queue;

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    assert(queue.Size() == 5);

    std::cout << "Should print \'1, 2, 3, 4, 5\'" << std::endl;
    while (queue.Size() > 0)
    {
        std::cout << queue.Front() << ", ";
        queue.Dequeue();
    }
    std::cout << std::endl;

    return 0;
}
