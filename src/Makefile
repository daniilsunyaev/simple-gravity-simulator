CC=g++ -Wl,-rpath,../lib/

CFLAGS=-c -Wall -std=c++11
SDLFLAGS=-lSDL2 -lSDL2_image

all: solar.o init_graphics.o massive_body.o math_vector.o
	$(CC) $(SDLFLAGS) solar.o init_graphics.o math_vector.o	massive_body.o -o planet 

solar.o: solar.cpp
	$(CC) $(CFLAGS) solar.cpp

init_graphics.o: init_graphics.cpp
	$(CC) $(CFLAGS) init_graphics.cpp

massive_body.o: massive_body.cpp
	$(CC) $(CFLAGS) massive_body.cpp

math_vector.o: math_vector.cpp
	$(CC) $(CFLAGS) math_vector.cpp

clean:
	rm -rf *.o planet

publish:
	-rm -rf *.o
	-mv	planet ../bin
