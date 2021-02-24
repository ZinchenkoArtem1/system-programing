#Makefile for Hello World project

carTest: carTest.o car.o
	g++ carTest.o car.o -o carTest

carTest.o: carTest.cpp
	g++ -c carTest.cpp

car.o: car.cpp
	g++ -c car.cpp

clean:
	rm  -rf *.o carTest
