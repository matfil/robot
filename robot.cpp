#include "robot.h"
#include "plansza.h"
#include "queue.h"
#include <iostream>



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
    if( mapka->getpoletype(pos[X],pos[Y]-1) != '*' )
    {
        way.clear();
        way.push_back('w');
        kolejka.push(pos[X],pos[Y]-1,way);
    }//up
    if( mapka->getpoletype(pos[X],pos[Y]+1) != '*' )
    {
        way.clear();
        way.push_back('s');
        kolejka.push(pos[X],pos[Y]+1,way);
    }//down
    if( mapka->getpoletype(pos[X]-1,pos[Y]) != '*' )
    {
        way.clear();
        way.push_back('a');
        kolejka.push(pos[X]-1,pos[Y],way);

    }//left
    if( mapka->getpoletype(pos[X]+1,pos[Y]) != '*' )
    {
        way.clear();
        way.push_back('d');
        kolejka.push(pos[X]+1,pos[Y],way);
    }//


    this->pathfinder();
}


void robot::pathfinder()
{

    if ( kolejka.isempty() )
        return;

    point current;
    std::string help;
    current = kolejka.pop();
    mapka->setpoleway(current.a,current.b,current.way);//pole zyskało najkrótszą ścieżkę do siebie

    if ( mapka->getpoletype(current.a,current.b) == 'x')
        return;

    if( mapka->getpoletype(current.a,current.b-1) != '*' && current.a!=pos[X] && current.b-1 !=pos[Y])
    {
        help = current.way;
        help.push_back('w');

        if( (mapka->getpoleway(current.a,current.b-1)).size() > help.size() || mapka->getpoletype(current.a+1,current.b) != ' ' )
            kolejka.push(current.a,current.b-1,help);
    }//up
    if( mapka->getpoletype(current.a,current.b+1) != '*' && current.a!=pos[X] && current.b+1 !=pos[Y] )
    {
        help = current.way;
        help.push_back('s');

        if( mapka->getpoleway(current.a,current.b+1).size() > help.size() || mapka->getpoletype(current.a+1,current.b) != ' ' )
            kolejka.push(current.a,current.b+1,help);
    }//down
    if( mapka->getpoletype(current.a-1,current.b) != '*' && current.a -1 != pos[X] && current.b !=pos[Y] )
    {
        help = current.way;
        help.push_back('a');

        if( mapka->getpoleway(current.a-1,current.b).size() > help.size() || mapka->getpoletype(current.a+1,current.b) != ' ' )
            kolejka.push(current.a-1,current.b,help);

    }//left
    if( mapka->getpoletype(current.a+1,current.b) != '*' && current.a +1 != pos[X] && current.b !=pos[Y] )
    {
        help = current.way;
        help.push_back('d');

        if( mapka->getpoleway(current.a+1,current.b).size() > help.size() || mapka->getpoletype(current.a+1,current.b) != ' ' )
            kolejka.push(current.a+1,current.b,help);
    }//right

    this->pathfinder();
}


std::string robot::waytodest() const
{
    return mapka->getpoleway(target[X],target[Y]);
}
