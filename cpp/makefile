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


SRCS=$(SRC)driver.cpp $(SRC)game_board.cpp $(SRC)player.cpp $(SRC)human_player.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: CnnectFour

CnnectFour: $(OBJS)
	mkdir $(BIN)
	$(CXX) $(CPPFLAGS) -o $(BIN)CnnectFour $(OBJS)
	
driver.o: $(SRC)driver.cpp $(INC)constants.h

game_board.o: $(SRC)gameboard.cpp $(INC)gameboard.h

human_player.o: $(SRC)human_player.cpp $(INC)human_player.h

player.o: $(INC)player.cpp $(INC)player.h
    
clean:
	cd ./$(BIN) && $(RM) *
	cd ./$(SRC) && $(RM) *.o
	$(RM) ./$(BIN)
