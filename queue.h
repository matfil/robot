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


class queue//kolejka typu FIFO
{

    class insider // lista jednokierunkowa
    {
    public:
        int pos[2];
        std::string way;
        insider* next;// wskaźnik na kolejny element listy

        insider(int, int, std::string);
    };

    insider* first;//pierwszy element kolejki
    insider* last;//ostatni

public:

    queue();//tworzy pustą kolejkę
    void push(int, int, std::string);//wstawia element
    point pop();//usuwa element
    bool isempty() const;//sprawdza czy kolejka jest pusta

    void show() const; // pokazuje zawartość kolejki (element debuga)

};

#endif
