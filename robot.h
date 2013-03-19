#ifndef ROBOT_H
#define ROBOT_H

#include "plansza.h"
#include "queue.h"


enum os {X = 0, Y};//by wstawiać literki odwołując się do tablicy pos w klasie robot

class robot
{
private:
    queue kolejka;
    int pos[2];//aktualna pozycja robota
    int target[3];//pozycja celu i to czy został ustawiony
    bool fl;//czy robot stoi na fladze?
    plansza* mapka;// wskaźnik do świata, w którym aktualnie porusza się robot

public:
    //******** Konstruktor ********
    robot(plansza* mapa);

    //******** Metody ********
    void ruch (int c);
    void position() const;
    void flag();//zmienia fl na 1 by robot zchodząc ze swjego pola zostawił znak 'x'
    void startfinder();
    std::string waytodest() const;
    bool istargetset() const;
};
#endif
