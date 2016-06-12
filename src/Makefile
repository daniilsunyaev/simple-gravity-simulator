CC=g++

CFLAGS=-c -Wall -pedantic -std=c++11
LDFLAGS=-lSDL2 -lSDL2_image

SOURCES=solar.cpp init_graphics.cpp massive_body_controller.cpp massive_body.cpp math_vector.cpp graphical_reflection.cpp pixel_reflection.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=planet

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o planet

publish:
	-rm -rf *.o
	-mv	planet ../bin
