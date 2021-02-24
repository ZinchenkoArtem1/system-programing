# Makefile for Lab2(static)

binary: userinterface.o libcardb.so
	g++ -o binary userinterface.o -L. -lcardb -Wl,-rpath,.

userinterface.o: userinterface.cpp
	g++ -c userinterface.cpp
	
libcardb.so: database.o car.o
	g++ -shared -o libcardb.so database.o car.o
	
database.o: database.cpp
	g++ -c -fPIC database.cpp
	
car.o: car.cpp
	g++ -c -fPIC car.cpp
	
clean:
	rm -rf *.o *.so binary
