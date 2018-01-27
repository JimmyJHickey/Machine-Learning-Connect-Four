CC=gcc
CXX=g++
RM=rm -f
CPPFLAGS=-I./inc/
#CPPFLAGS=-g $(shell root-config --cflags)
#LDFLAGS=-g $(shell root-config --ldflags)
#LDLIBS=$(shell root-config --libs)

INC=./inc/
BIN=./bin/
SRC=./src/

SRCS=$(SRC)driver.cpp $(SRC)game_board.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: CnnectFour

CnnectFour: $(OBJS)
	$(CXX) $(CPPFLAGS) -o $(BIN)CnnectFour $(OBJS)
	
driver.o: $(SRC)driver.cpp $(INC)constants.h

game_board.o: $(SRC)gameboard.cpp $(INC)gameboard.h
    
clean: 
	cd ./bin && $(RM) *
	cd ./src && $(RM) *.o
