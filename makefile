output: main.o calculations.o menu.o helpers.o
	g++ -std=c++0x main.o calculations.o menu.o helpers.o -o output

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

calculations.o: ./includes/calculations.cpp ./includes/calculations.h
	g++ -std=c++0x -c ./includes/calculations.cpp

menu.o: ./includes/menu.cpp ./includes/menu.h
	g++ -std=c++0x -c ./includes/menu.cpp

helpers.o: ./includes/helpers.cpp ./includes/helpers.h
	g++ -std=c++0x -c ./includes/helpers.cpp

clean:
	rm -rf *.o output