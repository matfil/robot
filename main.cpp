//main.cpp robot projekt1 PrOI

#include <iostream>
#include <fstream>
#include <string>

#include "pole.h"
#include "plansza.h"

using namespace std;

int main()
{
	char a;
	cout << "hello world" << endl;
	cin >> a;
	cout << "\033[2J\033[1;1H";//clearscreen!!!
	cin >> a;

	string filename;
	cin >> filename;
	cout << filename.c_str() << endl;
	plansza* mapka;
	mapka = new plansza(filename);

	mapka->show();

    plansza nowa;
	nowa = *mapka+*mapka;
	nowa.show();
	return 0;
}
