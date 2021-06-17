calculator: list.o main.o
	g++ -o calculator list.o main.o

list.o: list.cpp list.h
	g++ -c list.cpp

main.o: main.cpp list.h
	g++ -c main.cpp

clean:
	rm list.o