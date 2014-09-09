CC       = g++
DEBUG    = -O0 -g
CFLAGS   = -Wall 
CXXFLAGS = $(CFLAGS)
LDFLAGS	 = -g

TARGETS=main
INCLUDES=link_dependency.h

all:$(TARGETS)

main: main.o
	$(CC) $(LDFLAGS) $^ -o $@ 

main.o: main.cpp $(INCLUDES)
	$(CC) $(CXXFLAGS) -c $< -o $@

.PHONY: clean 

clean :
	rm -rf main
	rm -rf *.o
