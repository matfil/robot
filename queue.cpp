#include <iostream>
#include "queue.h"

static const int X = 0;
static const int Y = 1;

queue::insider::insider(int a, int b,std::string w)
{
    pos[X] = a;
    pos[Y] = b;
    way = w;
    next = nullptr;
}


queue::queue()
{
    first= nullptr;
    last = nullptr;
}

void queue::push(int a, int b, std::string way)
{
    if (first == nullptr)
    {
        first = new insider(a,b,way);
        last = first;
    }
    else
    {
        last->next = new insider(a,b,way);
        last = last->next;
    }
}

point queue::pop()
{
    point xy;
    insider* help;

    xy.a=-1;
    xy.b=-1;

    if (first == nullptr)
        return xy;

    xy.a = first->pos[X];
    xy.b = first->pos[Y];
    xy.way = first->way;
    help = first->next;
    delete first;
    first = help;
    return xy;
}

void queue::show() const
{
    insider* help;
    help = first;
    while(help != nullptr)
    {
        std::cout << help->pos[X] << " " << help->pos[Y] << std::endl;
        help = help->next;


    }
}


bool queue::isempty() const
{
    if (first == nullptr)
        return true;
    else
        return false;
}
