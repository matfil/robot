#ifndef ROBOT_H
#define ROBOT_H

#include "plansza.h"
#include "queue.h"

// klasa robot

enum os {X = 0, Y};//by wstawiać literki odwołując się do tablicy target w klasie robot

class robot
{
private:

    class position //klasa tylko po to by uniknąć typedefa
    {
    public:
        int x;
        int y;
    };

    queue kolejka;
    position pos;//aktualna pozycja robota
    int target[3];//pozycja celu i to czy został ustawiony
    bool fl;//czy robot stoi na fladze?
    plansza* mapka;// wskaźnik do świata, w którym aktualnie porusza się robot
    void move(int, int);


public:
    //******** Konstruktor ********
    robot(plansza* mapa);

    //******** Metody ********
    void clear();
    void ruch (int c);
    void rposition() const;
    void flag();//zmienia fl na 1 by robot zchodząc ze swjego pola zostawił znak 'x'
    void startfinder();
    void notarget();
    std::string waytodest() const;
    bool istargetset() const;
};
#endif
