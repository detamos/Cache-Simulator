
CC=g++
CFLAGS=-c -Wall -std=c++11 -I
LFLAGS=-Wall -std=c++11

IFLAGS=-I

DFLAGS=-g -Wextra -Werror

INCLUDES=./include

RM=rm
RMFLAGS=-f

SRCS=./src/simulator.cpp ./src/hexToDec.cpp ./src/cache.cpp

OBJS=$(SRCS:.cpp=.o)

all: clean-objects clean cacheSimulator
clean: 
	$(RM) $(RMFLAGS) ./bin/cacheSimulator

clean-objects:
	$(RM) $(RMFLAGS) src/*.o

cacheSimulator: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o ./bin/cacheSimulator -lm

.cpp.o: 
	$(CC) $(CFLAGS) $(INCLUDES) $<  -o $@