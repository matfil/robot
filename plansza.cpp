//Przechowywanie planszy projekt 1
#include "plansza.h"
#include "pole.h"
#include <iostream>
#include <string>

// ******** konstruktory ********
plansza::plansza(std::ifstream file)
{
	int i;
	std::string line;//linia zczytywanego tekstu z pliku
	std::string help;//pomocniczy
	file >> line;
	for (i = 0;i<line.size();i++)
	{
		if (line[i]>47 && line[i]<58)
		{
		help.push_back(line[i]);
		}
		else
		break;
	}
	std::string::size_type sz;   // alias of size_t
	this->xmax = std::stoi (help,&sz,10);
	help.erase();
	i++;

	for (i; i<line.size(); i++)
	{
		if (line[i]>47 && line[i]<58)
		{
		help.push_back(line[i]);
		}
		else
		break;
	}
	this->ymax = std::stoi (help,&sz,10);

	std::cout << this->xmax << this->ymax << std::endl;

	while(file >> line)
	{
		std::cout << line << std::endl;
	}
}//plansza::plansza(ifstream file)

plansza::plansza(pole tab[70][50])
{
}//plansza::plansza(pole tab[70][50])

// ******** metody ********
void plansza::show()
{
	for (int i = 0;i < this->ymax;i++)//przejście po wierszach (oś y)
	{
	for (int j = 0;j < this->xmax;j++)// przejście po kolumnach (oś x)
	{
		std::cout << mapa[j][i].type;
	}
	}
}//void plansza::show()
