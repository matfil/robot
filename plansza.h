//Przechowywanie planszy projekt 1 
#ifndef PLANSZA_H
#define PLANSZA_H

#include <iostream>
#include <fstream>
#include "pole.h"

class plansza
{
private:
	int xmax;
	int ymax;
	pole mapa[70][50];
public:
	plansza(ifstream file);
	plansza(char tab[70][50]);
};
#endif
