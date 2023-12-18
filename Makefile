PROG = main.exe
Classes = Classes
SRC = main.cpp $(wildcard $(Classes)/*.cpp)
CFLAGS = -g -std=c++20
LIBS = 
CC = g++

all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(LDFLAGS) $^ $(LIBS)

clean:
	rm -f $(PROG)

.PHONY: all clean
