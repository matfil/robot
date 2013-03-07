//main.cpp robot projekt1 PrOI

#include <iostream>
#include <fstream>
#include <string>

#include "pole.h"
#include "plansza.h"
#include "robot.h"

#define CLEARSCREEN "\033[2J\033[1;1H"

using namespace std;

int main()
{

	cout << CLEARSCREEN;

	string filename;
	string filename2;

	cout << "podaj nazwę mapki:";
	cin >> filename;

    cout << "podaj nazwę mapki:";
	cin >> filename2;
	plansza mapka(filename);
	plansza mapka2(filename2);

	mapka.show();

    plansza nowa;
    nowa = mapka + mapka2;
    cout<<"po dodaniu"<<endl;
    nowa.show();

// mnożenie

    plansza nowa2;
	nowa2 = mapka * mapka2;

	nowa2 = nowa2 * nowa2;// teraz na pewno ma ramkę

	cout << CLEARSCREEN;//clearscreen!!!
    robot testowy (&nowa2);

    nowa2.show();

//koniec
	return 0;
}
