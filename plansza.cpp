//Przechowywanie planszy projekt 1
#include "plansza.h"
#include "pole.h"
#include <iostream>
#include <string>

// ******** konstruktory ********
plansza::plansza()
{

}

plansza::plansza(std::string filename)
{
    std::ifstream file;
    file.open(filename.c_str(),std::ifstream::in);
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

	for(i=0;file >> line && i < this->ymax;i++)
	{
	    for(int j=0;j < this->xmax;j++)
	    {
            this->mapa[j][i].type=line[j];
	    }
		std::cout << line << std::endl;
	}
	file.close();
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
	std::cout << std::endl;
	}
}//void plansza::show()


// ******** operatory ********
plansza operator+ (plansza a, plansza b)
{
    plansza nowa;
    nowa.xmax = a.xmax + b.xmax -2;
    nowa.ymax = a.ymax > b.ymax ? a.ymax : b.ymax;
    for(int i = 0; i < a.ymax; i++)//przepisanie pierwszej mapy
    {
        for (int j = 0; j < a.xmax; j++)
        {
            nowa.mapa[j][i] = a.mapa[j][i];
        }
    }
    for(int i = 0; i < b.ymax; i++)//przepisanie drugiej mapy z nadpisaniem ostatniej kolumny
    {
        for (int j = 1; j < b.xmax; j++)
        {
            nowa.mapa[j+a.xmax-2][i] = b.mapa[j][i];
        }
    }
    return nowa;
}
