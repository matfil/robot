#include "robot.h"
#include "plansza.h"
#include "queue.h"
#include <iostream>
#include <string>

//implementacja obsługi robota

robot::robot(plansza* mapa)
{
    this->target[2]=0;
    pos[X]=0;
    pos[Y]=0;
    fl=0;
    bool isset;
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
                isset = true;
                break;
            }
        }
        if (isset)
        {
            break;
        }
    }
}

bool robot::istargetset() const
{
    return target[2]==1?true:false;
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

    if (c == 'x')
    {
        flag();
        return;
    }

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
        target[X]=pos[X];
        target[Y]=pos[Y];
        target[2]=1;
        fl=1;
    }
}


void robot::startfinder()
{

    std::string way;
    point current;

    mapka->setpolecolor(pos[X],pos[Y],GRAY);
    mapka->setpoleway(pos[X],pos[Y],way);
    kolejka.push(pos[X],pos[Y],way);

    while (kolejka.isempty() != true)
    {
        current = kolejka.pop();
        if ( mapka->iswhite(current.a,current.b-1) && mapka->getpoletype(current.a,current.b-1) != '*' )
        {
            way=current.way;
            way.push_back('w');
            mapka->setpolecolor(current.a,current.b-1,GRAY);
            mapka->setpoleway(current.a,current.b-1,way);
            kolejka.push(current.a,current.b-1,way);
        }//up 'w'
        if ( mapka->iswhite(current.a,current.b+1) && mapka->getpoletype(current.a,current.b+1) != '*' )
        {
            way=current.way;
            way.push_back('s');
            mapka->setpolecolor(current.a,current.b+1,GRAY);
            mapka->setpoleway(current.a,current.b+1,way);
            kolejka.push(current.a,current.b+1,way);
        }//down 's'
        if ( mapka->iswhite(current.a-1,current.b) && mapka->getpoletype(current.a-1,current.b) != '*' )
        {
            way=current.way;
            way.push_back('a');
            mapka->setpolecolor(current.a-1,current.b,GRAY);
            mapka->setpoleway(current.a-1,current.b,way);
            kolejka.push(current.a-1,current.b,way);
        }//left 'a'
        if ( mapka->iswhite(current.a+1,current.b) && mapka->getpoletype(current.a+1,current.b) != '*')
        {
            way=current.way;
            way.push_back('d');
            mapka->setpolecolor(current.a+1,current.b,GRAY);
            mapka->setpoleway(current.a+1,current.b,way);
            kolejka.push(current.a+1,current.b,way);
        }//right 'd'
    }
}




std::string robot::waytodest() const
{
    return mapka->getpoleway(target[X],target[Y]);
}
