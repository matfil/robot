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
	cout << "\033[2J\033[1;1H";//clearscreen!!!

	string filename;
	string filename2;

	cout << "podaj nazwę mapki:";
	cin >> filename;
	cout << filename.c_str() << endl;

    cout << "podaj nazwę mapki:";
	cin >> filename2;
	cout << filename2.c_str() << endl;
	plansza* mapka;
	plansza* mapka2;
	mapka = new plansza(filename);
	mapka2 = new plansza(filename2);

	mapka->show();

    plansza nowa;
    nowa = (*mapka) + (*mapka2);
    cout<<"po dodaniu"<<endl;
    nowa.show();




    plansza nowa2;
	nowa2 = (*mapka) * (*mapka2);
	cout<<"po wymnożeniu"<<endl;
	nowa2.show();

	return 0;
}
