output: main.o functions.o menu.o studentas.o
	g++ -std=c++0x main.o functions.o menu.o studentas.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

functions.o: ./includes/functions.cpp ./includes/functions.h
	g++ -std=c++0x -c ./includes/functions.cpp

menu.o: ./includes/menu.cpp ./includes/menu.h
	g++ -std=c++0x -c ./includes/menu.cpp

studentas.o: ./includes/studentas.cpp ./includes/studentas.h
	g++ -std=c++0x -c ./includes/studentas.cpp

clean:
	rm -rf *.o output