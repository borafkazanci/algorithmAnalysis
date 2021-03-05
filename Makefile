hw1: Main.o sorting.o
	g++ Main.o sorting.o -o hw1

Main.o: Main.cpp
	g++ -c Main.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

clean:
	rm *.o hw1