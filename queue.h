#ifndef QUEUE_H
#define QUEUE_H
#include <string>

class point
{
    public:
    int a;
    int b;
    std::string way;
};


class queue
{

    class insider
    {
        public:
        int pos[2];
        std::string way;
        insider* next;

        insider(int, int, std::string);
    };

    insider* first;
    insider* last;

    public:

    queue();
    void push(int, int, std::string);
    point pop();
    bool isempty() const;

    void show() const;

};

#endif
