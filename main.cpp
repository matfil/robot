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

<<<<<<< HEAD
void delay(int seconds);

int main()
=======
void delay(int seconds)
>>>>>>> 11f556ddb0808920e017e4494a096ec86ba7a41a
{
    time_t start, current;

<<<<<<< HEAD
    cout << CLEARSCREEN;

    string filename;
    string filename2;

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename;//pierwsza mapka

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename2;// druga mapka

=======
    time(&start);

    do
    {
        time(&current);
    }
    while ((current - start) < seconds);
}

int main()
{



    cout << CLEARSCREEN;

    string filename;
    string filename2;

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename;

    cout << "podaj nazwę mapki:"<<std::endl;
    cin >> filename2;

>>>>>>> 11f556ddb0808920e017e4494a096ec86ba7a41a
    plansza mapka (filename);
    plansza mapka2 (filename2);

    mapka.show();

    plansza nowa;
    nowa = mapka + mapka2;
    cout<<"po dodaniu"<<endl;
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
<<<<<<< HEAD

    while (a!='+')
    {
        a=cin.get();


        cout<<CLEARSCREEN;

        if (a == 'r')//'r' jak return
        {
            testowy.startfinder();
        }

        testowy.ruch(a);
        testowy.position();
        nowa2.show();

        if (a == 'g')
        {
            for (int iter = 0; iter < (int)(testowy.waytodest()).size(); iter++)
            {
                delay(1);
                testowy.ruch((testowy.waytodest())[iter]);
                cout<<CLEARSCREEN;
                nowa2.show();
            }
        }
    }


    /* ** restore terminal settings ** */

    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    /* */
//koniec
    return 0;
}

=======

    while (a!='+')
    {
        a=cin.get();


        cout<<CLEARSCREEN;

        if (a == 'r')//'r' jak return
        {
            testowy.startfinder();
        }

        testowy.ruch(a);
        testowy.position();
        nowa2.show();

        if (a == 'g')
        {
            for (int iter = 0; iter < (int)(testowy.waytodest()).size(); iter++)
            {
                delay(1);
                testowy.ruch((testowy.waytodest())[iter]);
                cout<<CLEARSCREEN;
                nowa2.show();
            }
        }
    }
>>>>>>> 11f556ddb0808920e017e4494a096ec86ba7a41a


void delay(int seconds) //opóźniacz
{
    time_t start, current;

    time(&start);

<<<<<<< HEAD
    do
    {
        time(&current);
    }
    while ((current - start) < seconds);
=======
    /* */
//koniec
    return 0;
>>>>>>> 11f556ddb0808920e017e4494a096ec86ba7a41a
}
