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

#define CLEARSCREEN "\033[2J\033[1;1H"

static const int ARROW_UP = 279165;
static const int ARROW_DOWN = 279166;
static const int ARROW_RIGHT = 279167;
static const int ARROW_LEFT = 279168;

using namespace std;

int main()
{

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
       a = cin.get();
       cout<<a;
   }


    /* ** restore terminal settings ** */

    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);

    /* */
//koniec
	return 0;
}
