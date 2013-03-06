//Przechowywanie planszy projekt 1
#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <fstream>
#include "pole.h"

class plansza
{
public:
	int xmax;
	int ymax;
	pole mapa[70][50];

    plansza();
	plansza(std::string filename);
	void show();

};

plansza operator+ (plansza a, plansza b);
plansza operator* (plansza a, plansza b);

#endif
