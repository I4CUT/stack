main: main.o 
	g++ main.o -o main
main.o: main.cpp stack_t.hpp
	g++ -c main.cpp -o main.o
clear:
	del *.o *.exe