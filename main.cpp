//main.cpp robot projekt1 PrOI

#include <iostream>
#include <cstdio>
#include <fstream>
#include <string>
#include <unistd.h>
#include <termios.h>


#include "pole.h"
#include "plansza.h"
#include "robot.h"
#include "queue.h"

#define CLEARSCREEN "\033[2J\033[1;1H"

using namespace std;

void delay(int seconds);

int main()
{

    cout << CLEARSCREEN;

    string filename;
    string filename2;
    char dm;

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename;//pierwsza mapka

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename2;// druga mapka

    cout << "dodać? mnożyć? (d/m)"<<std::endl;
    cin >> dm;

    plansza mapka (filename);
    plansza mapka2 (filename2);

    mapka.show();

    plansza nowa;

    if (dm == 'd')
        nowa = mapka + mapka2;

    if (dm == 'm')
        nowa = mapka * mapka2;

    nowa.show();

// mnożenie

    plansza nowa2;

    nowa2 = nowa * nowa;// teraz na pewno ma ramkę

    cout << CLEARSCREEN;//clearscreen!!!
    robot testowy (&nowa2);

    /* ******** no input buffer starts here ********* */

    struct termios old_tio, new_tio;

    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);

    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;

    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);

    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);

    /* ** ******* ** */

    nowa2.show();
    cout<<std::flush;
    int a;
    a = 0;

    while (a!='+')
    {
        a=cin.get();//literka sterująca


        cout<<CLEARSCREEN;

        if (a == 'r')//'r' jak return
        {
            testowy.startfinder();
        }

        testowy.ruch(a);
        testowy.rposition();
        nowa2.show();

        if ((a=='w'||a=='s'||a=='a'||a=='d')&&testowy.istargetset()&&(int)(testowy.waytodest()).size()>0)
        {
            testowy.clear();
        }

        cout << testowy.waytodest() << endl;

        if (a == 'g')
        {
            for (int iter = 0; iter < (int)(testowy.waytodest()).size(); iter++)
            {
                delay(1);
                testowy.ruch((testowy.waytodest())[iter]);
                cout<<CLEARSCREEN;
                nowa2.show();
            }
            testowy.notarget();
        }
    }


    /* ** restore terminal settings ** */

    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    /* */
//koniec
    return 0;
}



void delay(int seconds) //opóźniacz
{
    time_t start, current;

    time(&start);


    do
    {
        time(&current);
    }
    while ((current - start) < seconds);
}
