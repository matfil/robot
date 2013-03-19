//Przechowywanie planszy projekt 1
#include "plansza.h"
#include "pole.h"

#include <iostream>
#include <string>

// ******** konstruktory ********
plansza::plansza()//konstruktor ustawiający wszystko na wartości bazowe
{
    xmax=0;
    ymax=0;
    for(int i = 0; i<MAX_TERMINAL_X; i++)
    {
        for(int j = 0; j<MAX_TERMINAL_Y; j++)
        {
            this->mapa[i][j].type=' ';
            this->mapa[i][j].color = WHITE;
        }
    }
}

plansza::plansza(std::string filename)//wczytuje z pliku planszę
{
    std::ifstream file;
    file.open(filename.c_str(),std::ifstream::in);
    int i;
    std::string line;//linia zczytywanego tekstu z pliku
    std::string help;//pomocniczy
    file >> line;
    for (i = 0; i<(int)line.size(); i++)
    {
        if (line[i]>47 && line[i]<58)
            help.push_back(line[i]);
        else
            break;
    }
    std::string::size_type sz;   // alias of size_t
    this->xmax = std::stoi (help,&sz,10);//string to integer
    help.erase();
    i++;//przeskok na kolejną cyfrę zgodnie z ustalonym formatem pliku mapki.

    for (; i<(int)line.size(); i++)
    {
        if (line[i]>'/' && line[i]<':')// '/' 1 poniżej 0, ':' 1 powyżej 9 (ASCII)
            help.push_back(line[i]);
        else
            break;
    }
    this->ymax = std::stoi (help,&sz,10);

    std::cout << this->xmax <<" x "<< this->ymax << std::endl;

    for(i=0; file >> line && i < this->ymax; i++)
    {
        for(int j=0; j < this->xmax; j++)
        {
            this->mapa[j][i].type=line[j];
            this->mapa[j][i].color = WHITE;
        }
        //std::cout << line << std::endl;
    }
    file.close();
}//plansza::plansza(ifstream file)

// ******** metody ********
void plansza::clearways() // przywraca mapce stan początkowy, zeruje odległości od robota
{
    for (int i = 0; i < this->ymax; i++) //przejście po wierszach (oś y)
    {
        for (int j = 0; j < this->xmax; j++) // przejście po kolumnach (oś x)
        {
            this->mapa[j][i].color = WHITE;
            this->mapa[j][i].way.clear();
        }
    }
}

void plansza::show() const // zgodnie z nazwą pokazuje mapkę
{
    for (int i = 0; i < this->ymax; i++) //przejście po wierszach (oś y)
    {
        for (int j = 0; j < this->xmax; j++) // przejście po kolumnach (oś x)
        {
            std::cout << mapa[j][i].type;
        }
        std::cout << std::endl;
    }
}//void plansza::show()


int plansza::width() const
{
    return xmax;
}

int plansza::height() const
{
    return ymax;
}

char plansza::getpoletype(int x, int y) const
{
    if(x<0||y<0)
    {
        return '*';
    }
    return mapa[x][y].type;
}

void plansza::changepoletype(int x, int y, char c)
{
    if(x>=0&&y>=0)
    {
        mapa[x][y].type = c;
    }
}

std::string plansza::getpoleway(int x, int y) const
{
    if(x<0||y<0)
    {
        std::string ret;
        return ret;
    }
    return mapa[x][y].way;
}

void plansza::setpoleway(int x, int y, std::string s)
{
    if(x>=0&&y>=0)
        mapa[x][y].way = s;
}

// ******** operatory ********
plansza plansza::operator+ (const plansza &b) const
{
    plansza nowa;
    nowa.xmax = this->xmax + b.xmax -2;
    nowa.ymax = this->ymax > b.ymax ? this->ymax : b.ymax;
    for(int i = 0; i < this->ymax; i++)//przepisanie pierwszej mapy
    {
        for (int j = 0; j < this->xmax; j++)
        {
            nowa.mapa[j][i] = this->mapa[j][i];
        }
    }
    for(int i = 0; i < b.ymax; i++)//przepisanie drugiej mapy z nadpisaniem ostatniej kolumny
    {
        for (int j = 1; j < b.xmax; j++)
        {
            nowa.mapa[j+this->xmax-2][i] = b.mapa[j][i];
        }
    }
    return nowa;
}

bool plansza::isblack(int x, int y) const
{
    if (x<0||y<0)
        return true;

    if (mapa[x][y].color == BLACK)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool plansza::isgray(int x, int y) const
{
    if (x<0||y<0)
        return false;

    if (mapa[x][y].color == GRAY)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool plansza::iswhite(int x, int y) const
{
    if (x<0||y<0)
        return false;

    if (mapa[x][y].color == WHITE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void plansza::setpolecolor(int x, int y, int c)
{
    if(x>=0&&y>=0)
        mapa[x][y].color = c;
}


plansza plansza::operator* (const plansza &b) const
{
    int i,j;
    plansza nowa;
    nowa.xmax = this->xmax < b.xmax ? this->xmax : b.xmax;
    nowa.ymax = this->ymax < b.ymax ? this->ymax : b.ymax;
    for(i=0; i<nowa.ymax; i++)
    {
        for(j=0; j<nowa.xmax; j++)
        {
            if (this->mapa[j][i].type==b.mapa[j][i].type)
            {
                nowa.mapa[j][i].type=this->mapa[j][i].type;    //jak są identyczne zostaje to samo
            }
            else
            {
                nowa.mapa[j][i].type='.';    //jak nie to ścieżka
            }
            if (this->mapa[j][i].type==' '||b.mapa[j][i].type==' ')//jak było puste to staje się ścianą. Po pustym się nie chodzi
            {
                nowa.mapa[j][i].type='*';
            }
        }
    }
    for(i=0; i<nowa.xmax; i++)
    {
        nowa.mapa[i][0].type='*';
        nowa.mapa[i][nowa.ymax-1].type='*';
    }
    for(i=0; i<nowa.ymax; i++)
    {
        nowa.mapa[0][i].type='*';
        nowa.mapa[nowa.xmax-1][i].type='*';
    }

    return nowa;
}
