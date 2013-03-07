#include "robot.h"
#include "plansza.h"

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
        if (isset == 1)
        {
            break;
        }
    }
}

void robot::flag ()
{
    if (this->target[2]==0)
    {
        this->target[X]=this->pos[X];
        this->target[Y]=this->pos[Y];
    }
}
