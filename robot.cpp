#include "robot.h"
#include "plansza.h"
#include <iostream>



robot::robot(plansza* mapa)
{
    this->target[2]=0;
                    pos[X]=0;
    pos[Y]=0;
    fl=0;
    int isset;
    isset = 0;
    mapka = mapa;
    /*znajdź pierwsze wolne miejsce na robota*/
    for(int i=0; i<mapka->width(); i++)
    {
        for(int j=0; j<mapka->height(); j++)
        {
            if (mapka->getpoletype(i,j) == '.')
            {
                mapka->changepoletype(i,j,'r');
                pos[X]=i;
                pos[Y]=j;
                isset = 1;
                break;
            }
        }
        if (isset )
        {
            break;
        }
    }
}

void robot::position() const
{
    std::cout << pos[X] << " " << pos[Y] <<std::endl;
}

void robot::ruch (int c)
{
    static const int ARROW_UP = 119;
    static const int ARROW_DOWN = 115;
    static const int ARROW_RIGHT = 100;
    static const int ARROW_LEFT = 97;
    switch(c)
    {
        case ARROW_UP:
            if (mapka->getpoletype(pos[X],pos[Y]-1) != '*')
            {
                if (mapka->getpoletype(pos[X],pos[Y]-1) == 'x')
                {
                    mapka->changepoletype(pos[X],pos[Y],'.');
                    fl=1;
                }
                else
                {
                    mapka->changepoletype(pos[X],pos[Y],(fl?'x':'.'));
                    fl=0;
                }
                mapka->changepoletype(pos[X],pos[Y]-1,'r');
                pos[Y]--;
            }

        break;//ARROW_UP

        case ARROW_DOWN:
            if (mapka->getpoletype(pos[X],pos[Y]+1)!='*')
            {
                if (mapka->getpoletype(pos[X],pos[Y]+1)=='x')
                {
                    mapka->changepoletype(pos[X],pos[Y],'.');
                    fl=1;
                }
                else
                {
                    mapka->changepoletype(pos[X],pos[Y],(fl?'x':'.'));
                    fl=0;

                }
                mapka->changepoletype(pos[X],pos[Y]+1,'r');
                pos[Y]++;
            }

        break;//ARROW_DOWN

        case ARROW_RIGHT:
            if (mapka->getpoletype(pos[X]+1,pos[Y])!='*')
            {
                if (mapka->getpoletype(pos[X]+1,pos[Y])=='x')
                {
                    mapka->changepoletype(pos[X],pos[Y],'.');
                    fl=1;
                }
                else
                {
                    mapka->changepoletype(pos[X],pos[Y],(fl?'x':'.'));
                    fl=0;
                }
                mapka->changepoletype(pos[X]+1,pos[Y],'r');
                pos[X]++;
            }

        break;//ARROW_RIGHT

        case ARROW_LEFT:
            if (mapka->getpoletype(pos[X]-1,pos[Y])!='*')
            {
                if (mapka->getpoletype(pos[X]-1,pos[Y])=='x')
                {
                    mapka->changepoletype(pos[X],pos[Y],'.');
                    fl=1;
                }
                else
                {
                    mapka->changepoletype(pos[X],pos[Y],(fl?'x':'.'));
                    fl=0;
                }
                mapka->changepoletype(pos[X]-1,pos[Y],'r');
                pos[X]--;
            }

        break; //ARROW_LEFT

    }
}

void robot::flag ()
{
    if (this->target[2]==0)
    {
        this->target[X]=this->pos[X];
        this->target[Y]=this->pos[Y];
        this->target[2]=1;
    }
}
