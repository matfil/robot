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
	ifstream file;
	file.open(filename.c_str(),ifstream::in);// otworzenie pliku do czytania
	
	return 0;
}
