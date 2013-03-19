#Wersja kompilatora
CC= g++-4.7

#Flagi kompilatora
CFLAGS= -c -W -Wall -std=c++11

all: testing

testing: main.o robot.o plansza.o queue.o queue.o
	$(CC) -o testing main.o robot.o plansza.o queue.o

queue.o: queue.cpp queue.h
	$(CC) $(CFLAGS) -o queue.o queue.cpp

robot.o: robot.cpp robot.h
	$(CC) $(CFLAGS) -o robot.o robot.cpp

plansza.o: plansza.cpp plansza.h
	$(CC) $(CFLAGS) -o plansza.o plansza.cpp

main.o: main.cpp
	$(CC) $(CFLAGS) -o main.o main.cpp

clean:
	rm -rf *.o testing


