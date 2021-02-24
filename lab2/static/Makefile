# Makefile for Lab2(static)

binary: userinterface.o libcardb.a
	g++ -o binary userinterface.o -L. -lcardb

userinterface.o: userinterface.cpp
	g++ -c userinterface.cpp
	
libcardb.a: database.o car.o
	ar cr libcardb.a database.o car.o
	
database.o: database.cpp
	g++ -c database.cpp
	
car.o: car.cpp
	g++ -c car.cpp
	
clean:
	rm -rf *.o *.a binary
