CC=gcc
CXX=g++
RM=rm -f
#CPPFLAGS=-g $(shell root-config --cflags)
#LDFLAGS=-g $(shell root-config --ldflags)
#LDLIBS=$(shell root-config --libs)

#SRCS=tool.cc support.cc
#OBJS=$(subst .cc,.o,$(SRCS))

all: CnnectFour

CnnectFour: ./src/driver.cpp
	$(CXX) ./src/driver.cpp -o ./bin/CnnectFour
    
clean: 
	cd ./bin && rm -rf *
