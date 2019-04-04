CC=g++
CFLAGS=-c -Wall -Wextra -Wmain -pedantic-errors 
LDFLAGS=
SOURCES=DBDemo.cpp MechPart.cpp DBInterface.cpp BSTree.h BTNode.h
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=DBDemo

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

%.o : %.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *.o core *~
