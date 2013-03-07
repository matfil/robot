//Przechowywanie planszy projekt 1
#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <fstream>
#include "pole.h"

class plansza
{

private:
    static const int MAX_TERMINAL_X = 70;
    static const int MAX_TERMINAL_Y = 50;

    int xmax;//maksymalna ilość niepustych znaczków w wierszu
	int ymax;
	pole mapa[MAX_TERMINAL_X][MAX_TERMINAL_Y];

public:

    plansza();
	plansza(std::string filename);
	void show() const;
    int width() const;
    int height() const;
    char getpoletype(int x, int y) const;
    void changepoletype(int x, int y, char c);

    plansza operator+ (const plansza &b) const;
    plansza operator* (const plansza &b) const;
};



#endif
