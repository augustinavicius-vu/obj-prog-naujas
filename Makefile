output: main.o menu.o functions.o
	g++ -std=c++0x main.o  menu.o functions.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

menu.o: ./includes/menu.cpp ./includes/menu.h
	g++ -std=c++0x -c ./includes/menu.cpp

functions.o: ./includes/functions.cpp ./includes/functions.h
	g++ -std=c++0x -c ./includes/functions.cpp

clean:
	rm -rf *.o output