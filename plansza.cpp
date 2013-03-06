//Przechowywanie planszy projekt 1
#include "plansza.h"
#include "pole.h"

#include <iostream>
#include <string>

// ******** konstruktory ********
plansza::plansza()
{
    this->xmax=0;
    this->ymax=0;
    for(int i = 0; i<70;i++)
    {
        for(int j = 0; j<50;j++)
        {
            this->mapa[i][j].type=' ';
        }
    }
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
		//std::cout << line << std::endl;
	}
	file.close();
}//plansza::plansza(ifstream file)

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

plansza operator* (plansza a, plansza b)
{
    int i,j;
    plansza nowa;
    nowa.xmax = a.xmax < b.xmax ? a.xmax : b.xmax;
    nowa.ymax = a.ymax < b.ymax ? a.ymax : b.ymax;
    for(i=0;i<nowa.ymax;i++)
    {
        for(j=0;j<nowa.xmax;j++)
        {
            if (a.mapa[j][i].type==b.mapa[j][i].type)
            {nowa.mapa[j][i].type=a.mapa[j][i].type;}//jak są równe zostaje to samo
            else
            {nowa.mapa[j][i].type='.';}//jak nie to ścieżka
            if (a.mapa[j][i].type==' '||b.mapa[j][i].type==' ')//jak było puste zostaje puste
            {nowa.mapa[j][i].type=' ';}
        }
    }
    for(i=0;i<nowa.xmax;i++)
    {
        nowa.mapa[i][0].type='*';
        nowa.mapa[i][nowa.ymax-1].type='*';
    }
    for(i=0;i<nowa.ymax;i++)
    {
        nowa.mapa[0][i].type='*';
        nowa.mapa[nowa.xmax-1][i].type='*';
    }

    return nowa;
}
