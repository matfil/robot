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

int main()
{


    /*test site
    queue test;

    for (int i = 0;i<3;i++)
    {
        test.push(i,1);
    }

    test.show();

    point xy;
    for (int j = 0;j<3;j++)
    {
        xy = test.pop();
        cout << xy.a;
    }
    char asd;
    cin >> asd;
    -------------- kolejka działa --------------------*/
	cout << CLEARSCREEN;

	string filename;
	string filename2;

	cout << "podaj nazwę mapki:"<<std::endl;
	cin >> filename;

    cout << "podaj nazwę mapki:"<<std::endl;
	cin >> filename2;

	plansza mapka (filename);
	plansza mapka2 (filename2);

	mapka.show();

    plansza nowa;
    nowa = mapka + mapka2;
    cout<<"po dodaniu"<<endl;
    nowa.show();

// mnożenie

    plansza nowa2;
	//nowa2 = mapka * mapka2;

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
    int a; a = 0;

   while (a!='+')
   {
       a=cin.get();

       if (a == 'r')//'r' jak return
        testowy.startfinder();

       cout<<CLEARSCREEN;
       testowy.ruch(a);
       testowy.position();
       nowa2.show();

       cout << endl << testowy.waytodest();
   }


    /* ** restore terminal settings ** */

    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    /* */
//koniec
	return 0;
}
