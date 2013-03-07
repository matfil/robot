//Przechowywanie planszy projekt 1
#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <fstream>
#include "pole.h"

class plansza
{

    int xmax;//maksymalna ilość niepustych znaczków w wierszu
	int ymax;
	pole mapa[70][50];

public:

    plansza();
	plansza(std::string filename);
	void show();
    int width();
    int height();
    char getpoletype(int x, int y);
    void changepoletype(int x, int y, char c);

    plansza operator+ (const plansza &b);
    plansza operator* (const plansza &b);
};



#endif
