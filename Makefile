#Wersja kompilatora
CC= g++ 

#Flagi kompilatora
CFLAGS= -c -W -Wall -std=c++11 

all: testing

testing: main.o robot.o plansza.o
	$(CC) -o testing main.o robot.o plansza.o
	
robot.o: robot.cpp robot.h
	$(CC) $(CFLAGS) -o robot.o robot.cpp
	
plansza.o: plansza.cpp plansza.h
	$(CC) $(CFLAGS) -o plansza.o plansza.cpp
	
main.o: main.cpp
	$(CC) $(CFLAGS) -o main.o main.cpp
	
clean:
	rm -rf *.o testing


